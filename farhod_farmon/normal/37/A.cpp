#include <iostream>
using namespace std;
int main ()
{
int a,b[1000],i,j,d=1,c=1,d1=0;
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b[i];
}
for(i=1; i<=a; i++)
{
for(j=1; j<a; j++)
{
if(b[j]>b[j+1]){d=b[j]; b[j]=b[j+1]; b[j+1]=d;}
}
}
d=0;
for(j=1; j<a; j++)
{
if (b[j] == b[j+1]) {d++;}
else {c++; if(d1<d){d1=d;} d=0;}
}
if(d1<d){d1=d;}
cout<<d1+1<<" "<<c;
return 0 ;
}