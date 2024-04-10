#include <iostream>
#include <algorithm>
using namespace std;
int main ()
 {
  int a1,a2,a3,b1,b2,b3,a;
  cin>>a1>>a2>>a3>>b1>>b2>>b3>>a;
  a1=a1+a2+a3;
  b1=b1+b2+b3;
  while(a1>0){
     a1-=5;
     a--;
   }
  while(b1>0){
     b1-=10;
     a--;
   }
  if(a>=0){
     cout<<"YES";
   }
  else {
     cout<<"NO";
   }
  }