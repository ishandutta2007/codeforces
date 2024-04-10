#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main ()
{
int a,i,j;
long long d=0,c=0;
scanf("%d",&a);
int b[1000000];
for( i=1; i<=a; i++ ){
   scanf("%d",&b[i]);
   c+=b[i];
   d+=b[i];
 }

sort(b+1,b+a+1);

for(i=1; i<a; i++){
   d+=b[i];
   c-=b[i];
   d+=c;
 }
     cout<<d<<" ";

}