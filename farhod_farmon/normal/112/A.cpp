#include <iostream>
using namespace std;
int main ()
{
string a,b;
int i,b1=0,b2=0,b3=0,a1,a2,d;
cin>>a>>b;
for(i=0; i<a.size(); i++)
{
if(a[i]<92){a[i]=a[i]+32;}
if(b[i]<92){b[i]=b[i]+32;}
}
if(a==b){cout<<0;}
if(a<b){cout<<-1;}
if(a>b){cout<<1;}
return 0;
}