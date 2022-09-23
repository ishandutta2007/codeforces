#include <iostream>
using namespace std;
int main ()
{
int a[1000],b1=0,i,j,d,c=3;
for(i=1; i<=4; i++)
{
cin>>a[i];
}
for(i=1; i<=4; i++)
{
for(j=1; j<4; j++)
{
if(a[j]>a[j+1]){d=a[j]; a[j]=a[j+1]; a[j+1]=d;}
}
}

for(j=1; j<4; j++)
{
if (a[j] != a[j+1]) {c--;}
}
cout<<c;
return 0;
}