#include <iostream>
using namespace std;
int main()
{
long long int a,b[20000],i,j,h,min1=0,max1=-999999999999999999;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }

for( i=1; i<=a; i++ ){
   if( a%i==0 && a/i>=3 ){
      for( h=1; h<=i; h++ ){
           for( j=h; j<=a; j=j+i ){
         min1=min1+b[j];
       }
      if(min1>max1){
         max1=min1;
       }
       min1=0;
       }
    }
 }

cout<<max1;

return 0;

}