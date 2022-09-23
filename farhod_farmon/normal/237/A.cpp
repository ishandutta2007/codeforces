#include <iostream>
#include <algorithm>
using namespace std;
int main ()
 {
  long long int a,b[100000],b1[100000],max1=0,min1=0,i;
  cin>>a;
  for( i=1; i<=a; i++ ){
     cin>>b[i]>>b1[i];
     b[i]=b[i]*60+b1[i];
   }
  sort(b+1,a+b+1);

  for( i=1; i<a; i++ ){
    if(b[i]==b[i+1]){
       min1++;
     }
    if(min1>max1){max1=min1;}
    if(b[i]!=b[i+1]){
       min1=0;
     }
   }

  cout<<max1+1;

  }