#include <iostream>
using namespace std;
int main ()
{
int a,a1,a2,a3,b=0,c=0,i;
cin>>a;
for(i=1; i<=a; i++)
{
b=0;
cin>>a1>>a2>>a3;
if(a1==1){b++;}
if(a2==1){b++;}
if(a3==1){b++;}
if(b==2 || b==3){c++;}
}
cout<<c;
return 0;
}