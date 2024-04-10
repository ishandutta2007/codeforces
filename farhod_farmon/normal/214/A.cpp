#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int a,b,m,n,d=0;
cin>>n>>m;
for( a=0; a<=1000; a++ ){
   for( b=0; b<=1000; b++ ){
      if((a*a)+b==n && a+(b*b)==m){
         d++;
       }
    }
 }
cout<<d;
return 0;
}