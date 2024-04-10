#include <iostream>
using namespace std;
int main()
{
long long int a,b[1000001],b25=0,b50=0,i;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }
for( i=1; i<=a; i++ ){
   if(b[i]==25){
      b25+=25;
    }
   else if(b[i]==50){
      if(b25>=25){
         b25-=25;
         b50+=50;
       }
      else{
         cout<<"NO";
         return 0;
       }
    }
   else if(b[i]==100){
      if(b50>=50 && b25>=25){
         b50-=50;
         b25-=25;
       }
      else if(b25>=75){
         b25-=75;
       }
      else{
         cout<<"NO";
         return 0;
       }
    }
 }
cout<<"YES";
return 0;
}