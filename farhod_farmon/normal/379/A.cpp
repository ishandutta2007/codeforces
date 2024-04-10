#include <iostream>
using namespace std;
int main ()
{
int a,b,i,c=0,d=0;
cin>>a>>b;
while(a>0){
  c++;
  d++;
  a--;
  if(d>=b){a++; d=0;}
  }
  cout<<c+a;
return 0;
}