#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
int ta=0, tb=0, tc=0, td=0, t=0;
class citizen
{  char name[30];
   int age;
   int gender;
   char marital_status[5];
   int religion;
   int mot_tongue;
   char status[10];
   float income;
   int literate;
   public:
	   void input();
	   void show();
	   int ret_age()
	   {  return age;}
	   int ret_religion()
	   {return religion;}
	   float ret_income()
	   {  return income;}
	   char*ret_marital()
	   {  return marital_status;}
	   int ret_gender()
	   {  return gender;  }
	   int ret_literate()
	   {  return literate;  }
	   int ret_mot_tongue()
	   {  return mot_tongue;  }

};

void citizen :: input()
{  cout<<"\n Enter your name = ";
   gets(name);
   cout<<"\n Enter your age = ";
   cin>>age;
   cout<<"\n Enter your gender (1-> male (or) 2-> female) : ";
   cin>>gender;
   cout<<"\n Enter your marital status \n -> md-married \n -> umd-unmarried: ";
   gets(marital_status);
   cout<<"\n Enter your mother tongue = "
       <<"\n 1.Hindi"
       <<"\n 2.English"
       <<"\n 3.Urdu"
       <<"\n 4.Punjabi"
       <<"\n 5.Telegu"
       <<"\n 6.Malayalam"
       <<"\n 7.Bengali"
       <<"\n 8.Other ";
    cin>>mot_tongue;
   cout<<"\n Which religion do you practice ? "
       <<"\n 1. Hinduism"
       <<"\n 2. Islam"
       <<"\n 3. Sikhism"
       <<"\n 4. Christianity"
       <<"\n 5. Jainism"
       <<"\n 6. Buddhism"
       <<"\n 7. No religion"
       <<"\n 8. Any other : ";
   cin>>religion;
   if(age<=18)
     { strcpy(status,"student");
       income=0.0;
     }
   else if(age>=65)
     { strcpy(status,"retired");
       income=0.0;
     }
   else
     { cout<<"\n Enter status (earning/unemployed) ";
       gets(status);
       if(strcmpi(status,"earning")==0)
       {  cout<<"\n Enter your yearly income = ";
	  cin>>income;
       }
       else
	  income=0.0;
     }
   if(age>=7)
   { cout<<"\n Are you literate ( can read and write in atleast one language )"
	 <<"\n 1-> yes  (or)  0->no : " ;
     cin>>literate;
   }
   else
     literate = 2;
}
void citizen::show()
{  cout<<"\n Name = "<<name
       <<"\n Age = "<<age<<" years";
   if(gender==1)
       cout<<"\n Gender = Male ";
   else
       cout<<"\n Gender = Female";
   cout<<"\n Status = "<<status
       <<"\n Income = Rs."<<income<<" per month";
   if(strcmpi(marital_status,"md")==0)
     cout<<"\n Marital Status = Married";
   else
     cout<<"\n Marital Status = Unmarried";
   if(literate == 1)
     cout<<"\n Person is literate";
   else if(literate == 0)
     cout<<"\n Person is illeterate";
   else
     cout<<"\n Literacy is not applicable";
   cout<<"\n Religion practised = ";
   switch(religion)
   {  case 1 : cout<<"Hinduism";break;
      case 2 : cout<<"Islam";break;
      case 3 : cout<<"Sikhism";break;
      case 4 : cout<<"Christianity";break;
      case 5 : cout<<"Jainism";break;
      case 6 : cout<<"Buddhism";break;
      case 7 : cout<<"No religion practised";break;
      case 8 : cout<<"Other";break;
   }getch();
   cout<<"\n Mother Tongue = ";
   switch(mot_tongue)
   {  case 1: cout<<" Hindi";   break;
      case 2: cout<<" English"; break;
      case 3: cout<<" Urdu";    break;
      case 4: cout<<" Punjabi"; break;
      case 5: cout<<" Telegu";  break;
      case 6: cout<<" Malayalam"; break;
      case 7: cout<<" Bengali"; break;
      case 8: cout<<" Other ";  break;
    }getch();
}
void enter( char f[] )
{  ofstream ofile(f,ios::binary | ios::app);
   citizen s;
   char ans;
   do
   {  clrscr();
      cout<<"\n Enter records\n ";
      s.input();
      ofile.write((char*)&s,sizeof(s));
      cout<<"\n Do you want to enter more...? (y/n) : ";
      cin>>ans;
   }while(ans=='y' || ans=='Y');
   ofile.close();
}
void tpop( char f[] , int a)
{  ifstream ifile(f,ios::binary | ios::in);
   citizen s;
   int tot=0;
   while( ifile.read((char*)&s,sizeof(s)) )
   {  tot++;
   }
   ifile.close();
   char nm[10];
   switch(a)
   {  case 1 : ::ta=tot;strcpy(nm,"A");break;
      case 2 : ::tb=tot;strcpy(nm,"B");break;
      case 3 : ::tc=tot;strcpy(nm,"C");break;
      case 4 : ::td=tot;strcpy(nm,"D");break;
   }getch();
   cout<<"\n Total population of state "<<nm<<" : "<<tot;
}
void sex_ratio( char f[], int a )
{  ifstream ifile(f, ios::binary | ios::in);
   int male=0,female=0;
   citizen s;
   while(ifile.read((char*)&s,sizeof(s)))
   {  if(s.ret_gender()==1)
	male++;
      if(s.ret_gender()==2)
	female++;
   }
   ifile.close();
   if(a==2)
   {  cout<<"\n No. of males = "<<male;
   }
   else if(a==3)
   {  cout<<"\n No. of females = "<<female;
   }
   else if(a==4)
   {  cout<<"\n Sex ratio = "<< ( float(male)/float(female) )*100.0;
   }
}
void literacy( char f[])
{  ifstream ifile(f,ios::binary);
   citizen s;
   int l=0,p=0;
   while(ifile.read((char*)&s,sizeof(s)))
   {  if(s.ret_age()>=7)
	p++;
      if(s.ret_literate()==1)
	l++;
   }
   ifile.close();
   cout<<"\n Literate population = "<<l;
   cout<<"\n Total eigible population = "<<p;
   cout<<"\n Therefore, Literacy rate = "<< (float(l)/float(p))*100.0;
}
void pdensity(char f[],int state)
{  tpop(  f,  state);
   long area=0;
   int t;
   switch(state)
   {  case 1 : area=8790;  t=ta;  break;
      case 2 : area=587;   t=tb;  break;
      case 3 : area=143;   t=tc;  break;
      case 4 : area=6743;  t=td;  break;
   }getch();
   cout<<"\n Area of the state = "<<area<<" square kilometers";
   cout<<"\n Therefore, population density = "<< float(t)/float(area);
}
void voters( char f[] )
{  ifstream ifile(f,ios::binary );
   citizen s;
   int v=0;
   while(ifile.read((char*)&s,sizeof(s)))
   {  if(s.ret_age()>=18)
	v++;
   }
   ifile.close();
   cout<<"\n Eligible voters = "<<v;
}
void pcincome( char f[], int state)
{  tpop( f,state);
   int t;
   long float i=0.0;
   citizen s;
   switch(state)
   {  case 1 : t=ta;break;
      case 2 : t=tb;break;
      case 3 : t=tc;break;
      case 4 : t=td;break;
   }getch();
   ifstream ifile(f,ios::binary);
   while(ifile.read((char*)&s,sizeof(s)))
   {   i=s.ret_income();
       i++;
   }
   ifile.close();
   cout<<"\n Total personal income = "<<i;
   cout<<"\n Total population "<<t;
   cout<<"\n per capita income "<<float(i)/float(t);
}
void per_pop( char f[], int state, int a)
{  int m=0,c=0,ss=0,t=0;
   citizen s;
   tpop(f,state);
   switch(state)
   {  case 1 :t=ta;break;
      case 2 :t=tb;break;
      case 3 :t=tc;break;
      case 4 :t=td;break;
   }getch();
   ifstream ifile(f,ios::binary);
   while(ifile.read((char*)&s,sizeof(s)))
   {  if(strcmpi(s.ret_marital(),"md")==0)
	 m++;
      if(s.ret_age()<=18)
	c++;
      if(s.ret_age()>=65)
	ss++;
   }
   ifile.close();
   switch(a)
   {  case 9 :cout<<"\n No. of married people = "<<m;
	      cout<<"\n Percentage = "<<(float(m)/float(t))*100.0;
	      break;
      case 10:cout<<"\n No. of children (age<=18) = "<<c;
	      cout<<"\n Percentage = "<<( float(c)/float(t) )*100.0;
	      break;
      case 11:cout<<"\n No. of senior citizens = "<<ss;
	      cout<<"\n Percentage = "<<( float(ss)/float(t) )*100.0;
	      break;
   }getch();
}
void religious( char f[], int state)
{  tpop(f,state);
   int t;
   switch(state)
   {  case 1 : t=ta; break;
      case 2 : t=tb; break;
      case 3 : t=tc; break;
      case 4 : t=td; break;
   }getch();
   int r[8],i=0;
   for(i=0;i<8;i++)
      r[i]=0;
   citizen s;
   ifstream ifile;
   for(i=0;i<8;i++)
   {  ifile.open(f,ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if (s.ret_religion()==(i+1))
	    r[i]++;
      }
      ifile.close();
   }

   char rg[8][15]={"Hinduism","Islam","Sikhism","Christianity","Jainism",
		   "Buddhism","None","Other"};
   for(i=0;i<8;i++)
   {  cout<<"\n People following "<<rg[i]<<" are "<<r[i];
      cout<<"\n Therefore percentage of prople following "<<rg[i]
	  <<" is "<<(float(r[i])/float(t))*100<<"%";
      cout<<endl;
   }
}
void linguous( char f[], int state)
{  tpop(f,state);
   int t;
   switch(state)
   {  case 1 : t=ta; break;
      case 2 : t=tb; break;
      case 3 : t=tc; break;
      case 4 : t=td; break;
   }getch();
   int r[8],i=0;
   for(i=0;i<8;i++)
      r[i]=0;
   citizen s;
   ifstream ifile;
   for(i=0;i<8;i++)
   {  ifile.open(f,ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if (s.ret_religion()==(i+1))
	    r[i]++;
      }
      ifile.close();
   }

   char rg[8][15]={"Hindi","English","Urdu","Punjabi","Telegu",
		   "Malayalam","Bengali","Other"};
   for(i=0;i<8;i++)
   {  cout<<"\n Citizens with mother tongue as "<<rg[i]<<" are "<<r[i];
      cout<<"\n Therefore percentage of citizens with "<<rg[i]
	  <<" as their mother tongue is "<<(float(r[i])/float(t))*100<<"%";
      cout<<endl;
   }
}
void tpopc()
{  tpop("A.dat",1);
   tpop("B.dat",2);
   tpop("C.dat",3);
   tpop("D.dat",4);
   ::t=::ta + ::tb + ::tc + ::td;
   cout<<"\n Total population of the country = "<<::t;
}
void sex_ratio_c(int a)
{  citizen s;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   int i=0;
   ifstream ifile;
   int male=0,female=0;
   for(i=0;i<4;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(s.ret_gender()==1)
		male++;
	 if(s.ret_gender()==2)
		female++;
      }
      ifile.close();
   }
   if(a==2)
   {  cout<<"\n No. of males = "<<male;
   }
   else if(a==3)
   {  cout<<"\n No. of females = "<<female;
   }
   else if(a==4)
   {  cout<<"\n Sex ratio = "<< ( float(male)/float(female) )*100.0;
   }
}
void literacy_c()
{  citizen s;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   int i=0;
   ifstream ifile;
   int l=0,p=0;
   for(i=0;i<4;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(s.ret_age()>=7)
	   p++;
	 if(s.ret_literate()==1)
	   l++;
      }
      ifile.close();
   }
   cout<<"\n Literate population = "<<l;
   cout<<"\n Total eigible population = "<<p;
   cout<<"\n Therefore, Literacy rate = "<< (float(l)/float(p))*100.0;
}
void pdensity_c()
{  tpopc();
   long area=16263;
   cout<<"\n Area of the country = "<<area<<" square kilometers";
   cout<<"\n Therefore, population density = "<< float(::t)/float(area);
}
void voters_c()
{  citizen s;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   int i=0;
   ifstream ifile;
   int v=0;
   for(i=0;i<4;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(s.ret_age()>=18)
		v++;
      }
      ifile.close();
   }
   cout<<"\n Eligible voters = "<<v;
}
void pcincome_c()
{  tpopc();
   long float ic=0.0;
   citizen s;
   ifstream ifile;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   int i=0;
   for(i=0;i<4;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {   ic=s.ret_income();
	  ic++;
      }
      ifile.close();
   }
   cout<<"\n Total personal income = "<<ic;
   cout<<"\n Total population "<<::t;
   cout<<"\n per capita income "<<float(ic)/float(::t);
}
void per_pop_c(int a)
{  citizen s;
   tpopc();
   int m=0,c=0,ss=0;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   int i=0;
   ifstream ifile;
   for(i=0;i<4;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(strcmpi(s.ret_marital(),"md")==0)
	 m++;
      if(s.ret_age()<=18)
	c++;
      if(s.ret_age()>=65)
	ss++;
      }
      ifile.close();
   }
   switch(a)
   {  case 9 :cout<<"\n No. of married people = "<<m;
	      cout<<"\n Percentage = "<<(float(m)/float(::t))*100.0;
	      break;
      case 10:cout<<"\n No. of children (age<=18) = "<<c;
	      cout<<"\n Percentage = "<<( float(c)/float(::t) )*100.0;
	      break;
      case 11:cout<<"\n No. of senior citizens = "<<ss;
	      cout<<"\n Percentage = "<<( float(ss)/float(::t) )*100.0;
	      break;
   }getch();
}
void religious_c()
{  tpopc();
   int i,r[8];
   citizen s;
   for(i=0;i<8;i++)
      r[i]=0;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   ifstream ifile;
   for(i=0;i<8;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(s.ret_religion()==(i+1))
	   r[i]++;
      }
      ifile.close();
   }
   char rg[8][15]={"Hinduism","Islam","Sikhism","Christianity","Jainism",
		   "Buddhism","None","Other"};
   for(i=0;i<8;i++)
   {  cout<<"\n People following "<<rg[i]<<" are "<<r[i];
      cout<<"\n Therefore percentage of prople following "<<rg[i]
	  <<" is "<<(float(r[i])/float(::t))*100<<"%";
      cout<<endl;
   }
}
void linguous_c()
{  tpopc();
   int i,r[8];
   citizen s;
   for(i=0;i<8;i++)
      r[i]=0;
   char f[4][10]={"A.dat", "B.dat", "C.dat", "D.dat"};
   ifstream ifile;
   for(i=0;i<8;i++)
   {  ifile.open(f[i],ios::binary);
      while(ifile.read((char*)&s,sizeof(s)))
      {  if(s.ret_mot_tongue()==(i+1))
	   r[i]++;
      }
      ifile.close();
   }
   char rg[8][15]={"Hindi","English","Urdu","Punjabi","Telegu",
		   "Malayalam","Bengali","Other"};
   for(i=0;i<8;i++)
   {  cout<<"\n Citizens with mother tongue as "<<rg[i]<<" are "<<r[i];
      cout<<"\n Therefore percentage of citizens with "<<rg[i]
	  <<" as their mother tongue is "<<(float(r[i])/float(::t))*100<<"%";
      cout<<endl;
   }
}
void modify(char f[])
{ citizen c;
  char ans;
  ifstream ifile(f,ios::binary|ios::in);
  ofstream ofile("temp.dat",ios::binary);
  if(!f)
  cout<<"\nFile does not exit";
  else
  { while(ifile.read((char*) &c,sizeof(c)))
   { c.show();
     cout<<"\nDo you want to modify more(y/n)=";
     cin>>ans;
     if(ans=='y'||ans=='Y')
     {  clrscr();
	c.input();
	ofile.write((char*) &c,sizeof(c));
     }
     else
       ofile.write((char*)&c,sizeof(c));
     getch();
     clrscr();
   }
   ofile.close();
   ifile.close();
   remove(f);
   rename("temp.dat",f);
 }
}
void Delete(char f[])
{ citizen c;
  char ans;
  ifstream ifile(f,ios::binary|ios::in);
  ofstream ofile("temp.dat",ios::binary);
  if(!ifile)
     cout<<"\n No records found !!";
  else
  { while(ifile.read((char*) &c,sizeof(c)))
   { c.show();
     cout<<"\nDo you want to delete more(y/n)=";
     cin>>ans;
     if(ans=='n'||ans=='N')
     ofile.write((char*) &c,sizeof(c));
     getch();
     clrscr();
   }
   ofile.close();
   ifile.close();
   remove(f);
   rename("temp.dat",f);
  }
}
void display(char f[])
{ ifstream ifile(f,ios::binary|ios::in);
  citizen c;
  if(!ifile)
     cout<<"\n No records found !!";
  else
  { while(ifile.read((char*) &c,sizeof(c)))
    c.show();
    getch();
  }
  ifile.close();
}
void main()
{  clrscr();
   int ch,chs,chc,state;
   char file[10];
   do
   {  clrscr();
      cout<<"\n *********************** POPULATION CENSUS ***********************\n"
	  <<"\n ----------- MENU --------------\n"
	  <<"\n 1. Enter records for state A "
	  <<"\n 2. Enter records for state B "
	  <<"\n 3. Enter records for state C "
	  <<"\n 4. Enter records for state D "
	  <<"\n 5. State wise census"
	  <<"\n 6. Census for the whole country\n "
	  <<"\n 7. Modify records for state A"
	  <<"\n 8. Modify records for state B"
	  <<"\n 9. Modify records for state C"
	  <<"\n 10.Modify records for state D"
	  <<"\n 11.Delete records for state A"
	  <<"\n 12.Delete records for state B"
	  <<"\n 13.Delete records for state C"
	  <<"\n 14.Delete records for state D"
	  <<"\n 15.Display records dor state A"
	  <<"\n 16.Display records dor state B"
	  <<"\n 17.Display records dor state C"
	  <<"\n 18.Display records dor state D"
	  <<"\n 19. Exit ";
      cout<<"\n What do you want to do...? (1-19) : ";
      cin>>ch;
      switch(ch)
      {  case 1 : enter("A.dat");
		  break;
	 case 2 : enter("B.dat");
		  break;
	 case 3 : enter("C.dat");
		  break;
	 case 4 : enter("D.dat");
		  break;
	 case 5 : do
		  { clrscr();
		    cout<<"\n ****************** STATE WISE CENSUS ********************\n";
		    cout<<"\n Choose your state \n"
			<<"\n 1. A"
			<<"\n 2. B"
			<<"\n 3. C"
			<<"\n 4. D"
			<<"\n 5. Back to previous menu\n ";
		    cin>>state;
		    switch(state)
		    {  case 1 : strcpy(file,"A.dat");break;
		       case 2 : strcpy(file,"B.dat");break;
		       case 3 : strcpy(file,"C.dat");break;
		       case 4 : strcpy(file,"D.dat");break;
		       case 5 : cout<<"\n Going back"; break;
		       default: cout<<"\n Wrong choice";break;
		    }getch();
		    if(state==1 || state==2 || state==3 || state==4)
		    { do
		      { clrscr();
			cout<<"\n -------------- MENU --------------\n"
			    <<"\n 1.  Total population "
			    <<"\n 2.  No. of males"
			    <<"\n 3.  No. of females"
			    <<"\n 4.  Sex ratio"
			    <<"\n 5.  Literacy rate"
			    <<"\n 6.  Population Density"
			    <<"\n 7.  Eligible voters"
			    <<"\n 8.  Per Capita income"
			    <<"\n 9.  Percentage of married people"
			    <<"\n 10. Percentage of children"
			    <<"\n 11. Percentage of senior citizen"
			    <<"\n 12. Religious distribution"
			    <<"\n 13. Linguous distribution"
			    <<"\n 14. Back to previous menu";
			cout<<"\n Enter your choice (1-14) : ";
			cin>>chs;
			switch(chs)
			{  case 1 : tpop(file, state);
				    break;
			   case 2 : sex_ratio(file,2);
				    break;
			   case 3 : sex_ratio(file,3);
				    break;
			   case 4 : sex_ratio(file,4);
				    break;
			   case 5 : literacy(file);
				    break;
			   case 6 : pdensity(file,state);
				    break;
			   case 7 : voters(file);
				    break;
			   case 8 : pcincome(file,state);
				    break;
			   case 9 : per_pop(file,state,9);
				    break;
			   case 10: per_pop(file,state,10);
				    break;
			   case 11: per_pop(file,state,11);
				    break;
			   case 12: religious(file,state);
				    break;
			   case 13: linguous(file,state);
				    break;
			   case 14: cout<<"\n Going back to the previous menu ";
				    break;
			   default: cout<<"\n Wrong choice ";
				    break;
			}getch();
		      }while(chs!=14);
		    }
		  }while(state!=5);
		  break;
	 case 6 : do{ clrscr();
		      cout<<"\n -------------------------- COUNTRY WIDE CENSUS ---------------------------------\n";
		      cout<<"\n -------------- MENU --------------\n"
			  <<"\n 1.  Total population "
			  <<"\n 2.  No. of males"
			  <<"\n 3.  No. of females"
			  <<"\n 4.  Sex ratio"
			  <<"\n 5.  Literacy rate"
			  <<"\n 6.  Population Density"
			  <<"\n 7.  Eligible voters"
			  <<"\n 8.  Per Capita income"
			  <<"\n 9.  Percentage of married people"
			  <<"\n 10. Percentage of children"
			  <<"\n 11. Percentage of senior citizen"
			  <<"\n 12. Religious distribution"
			  <<"\n 13. Linguous distribution"
			  <<"\n 14. Back to previous menu";
		      cout<<"\n Enter your choice (1-14) : ";
		      cin>>chc;
		      switch(chc)
		      {  case 1 : tpopc();
				  break;
			 case 2 : sex_ratio_c(2);
				  break;
			 case 3 : sex_ratio_c(3);
				  break;
			 case 4 : sex_ratio_c(4);
				  break;
			 case 5 : literacy_c();
				  break;
			 case 6 : pdensity_c();
				  break;
			 case 7 : voters_c();
				  break;
			 case 8 : pcincome_c();
				  break;
			 case 9 : per_pop_c(9);
				  break;
			 case 10: per_pop_c(10);
				  break;
			 case 11: per_pop_c(11);
				  break;
			 case 12: religious_c();
				  break;
			 case 13: linguous_c();
				  break;
			 case 14: cout<<"\n Going back to the previous menu ";
				  break;
			 default: cout<<"\n Wrong choice ";
				  break;
		      }getch();
		    }while(chc!=14);
		    break;
	 case 7 : modify("A.dat");
		  break;
	 case 8 : modify("B.dat");
		  break;
	 case 9 : modify("C.dat");
		  break;
	 case 10: modify("D.dat");
		  break;
	 case 11: Delete("A.dat");
		  break;
	 case 12: Delete("B.dat");
		  break;
	 case 13: Delete("C.dat");
		  break;
	 case 14: Delete("D.dat");
		  break;
	 case 15: display("A.dat");
		  break;
	 case 16: display("B.dat");
		  break;
	 case 17: display("C.dat");
		  break;
	 case 18: display("D.dat");
		  break;
	 case 19: cout<<"\n Terminating";
		  break;
	 default: cout<<"\n Wrong choice";
		  break;
      }getch();
   }while(ch!=19);
}


























