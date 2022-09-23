#include <iostream>
using namespace std;
int main()
{
int a,i,j,d=0,f=1;
cin>>a;
for( j=1; j<=a; j++ ){
d+=a;
   for( i=f; i<=d/2; i++ ){
      cout<<i<<" ";
    }
   for( i=f; i<=d/2; i++ ){
      cout<<a*a-(i-1)<<" ";
    }
   f+=a/2;
   cout<<endl;
 }
return 0;
}