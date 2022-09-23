#include <iostream>
using namespace std;
int main()
{
int a,b,i,d=0,d1=0;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b;
   if(b==5){
      d++;
    }
   else{
      d1++;
    }
 }
if(d/9==0 && d1==0 || d1==0){
   cout<<-1;
   return 0;
 }
else if(d/9>0){
   for( i=1; i<=d-(d%9); i++ ){
      cout<<5;
    }
   for( i=1; i<=d1; i++ ){
      cout<<0;
    }
 }
else{
   cout<<0;
 }
return 0;
}