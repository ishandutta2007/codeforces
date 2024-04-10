#include <iostream>
using namespace std;

int farhod(int a, int b)
{
int i,d;
if(a>b){
   for(i=b; i>=1; i--){
      if(a%i==0 && b%i==0){
         d=i;
         break;
       }
    }
 }
 else{
   for(i=a; i>=1; i--){
      if(a%i==0 && b%i==0){
         d=i;
         break;
       }
    }
 }
return d;
}

int main ()
 {
  int a,b,c,d=0,i;
  cin>>a>>b>>c;
  while(c>=0){
     if(c>=0){
        c=c-farhod(a,c);
        d=1;
      }
     if(c>=0){
        c=c-farhod(b,c);
        d=0;
      }

   }

   cout<<d;
  return 0;
 }