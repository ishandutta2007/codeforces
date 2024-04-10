#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main ()
{
 int a,b,x1=0,x2=0,c;
 cin>>a>>b;
 c=a;
while(c>0){
    if(c>=2){c-=2; x2++;}
    else if(c==1){c--; x1++;}
  }
 if(x1+x2%b==0){
    cout<<x1+x2;
  }
 else{
  while((x1+x2)%b!=0){
       if(x2<=0){cout<<-1; return 0;}
     x2--;
     x1=x1+2;
   }
   cout<<x1+x2;
  }
}