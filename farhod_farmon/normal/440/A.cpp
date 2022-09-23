#include <iostream>
using namespace std;
int main()
{
 int a,b,g=0,d=0,i;
 cin >> a;
  for( i=1; i<a; i++ ){
     cin >> b;
     g = g + b;
   }
  for( i = 1; i <= a; i++ ){
     d = d + i;
   }
 cout<<d-g;

 return 0;
}