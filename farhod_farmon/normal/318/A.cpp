#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
int main ()
{
long long int a,b,c;
cin>>a>>b;
if(a%2!=0){
 if(a/2+1>=b){
     if(a%2==0){
   b=b;
   c=b*2-1;
   }
   else{
   b=b+1    ;
   c=b*2-3;
   }
 }
else{
   if(a%2==0){
   b=b-(a/2);
   c=b*2;
   }
   else{
   b=b-(a/2+1);
   c=b*2;
   }
 }
 }
else{
 if(a/2+1>b){
     if(a%2==0){
   b=b;
   c=b*2-1;
   }
   else{
   b=b+1    ;
   c=b*2-3;
   }
 }
else{
   if(a%2==0){
   b=b-(a/2);
   c=b*2;
   }
   else{
   b=b-(a/2+1);
   c=b*2;
   }
 }
 }
cout<<c;
return 0;
}