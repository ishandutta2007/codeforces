#include <iostream>
using namespace std;
int main ()
{
 int a,b,c,d,i,g=0,g1=0,g2=0;
 cin>>a;
 for( i = 1; i <= a; i ++ )
 {
 cin >> b >> c >> d;
 g = g + b;
 g1 = g1 + c;
 g2 = g2 + d;
 }
if(g == 0 && g1 == 0 && g2 == 0 ){
   cout<<"YES";
 }
else {
   cout<<"NO";
 }
  return 0;
}