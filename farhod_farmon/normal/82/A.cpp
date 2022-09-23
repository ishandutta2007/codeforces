#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
int a,s=1,l=1,p=1,r=1,h=1;
cin>>a;
while(a>0){
 a=a-s;
 s=s*2;
      if(a<1){cout<<"Sheldon"; break;}
 a=a-l;
 l=l*2;
      if(a<1){cout<<"Leonard"; break;}
 a=a-p;
 p=p*2;
      if(a<1){cout<<"Penny"; break;}
 a=a-r;
 r=r*2;
      if(a<1){cout<<"Rajesh"; break;}
 a=a-h;
 h=h*2;
      if(a<1){cout<<"Howard"; break;}
 }
return 0;
}