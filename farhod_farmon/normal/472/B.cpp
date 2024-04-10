#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int b,c,d=0,a[2001],i;
cin>>b>>c;
for (i=0;i<b;i++){
       cin>>a[i];
 }
sort(a,a+b);

for (i=b-1;i>=0;i-=c){
   d+=(a[i]-1)*2;
 }
cout<<d;
}