#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
 int a,i,j;
 for(i=1;i<=5;++i){
   for(j=1;j<=5;++j){
      cin>>a;
      if(a==1){
         cout<<(abs(3-i)+abs(3-j));
       }
 }
  }
 return 0;
 }