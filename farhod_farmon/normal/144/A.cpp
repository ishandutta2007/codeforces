#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
int a,b[1000],i,j,max1=0,min1=101,max2,min2;
cin>>a;
for(i=1; i<=a; i++)
{
cin>>b[i];
if(b[i]>max1){max1=b[i]; max2=i;}
if(b[i]<=min1){min1=b[i]; min2=i;}
}
if(max2>min2){cout<<(abs(1-max2))+(abs(a-min2))-1;}
if(max2<min2){cout<<(abs(1-max2))+(abs(a-min2));}
return 0;
}