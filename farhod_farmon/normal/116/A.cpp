#include <iostream>
using namespace std;
int main ()
{
int a[1000],b[1000],n,d=0,f=0;
cin>>n;
for(int i=1; i<=n; i++)
{cin>>a[i]>>b[i];}
for(int i=1; i<=n; i++)
{
   d-=a[i];
   d+=b[i];
   if( d>f ){f=d;}
}
cout<<f;
return 0;
}