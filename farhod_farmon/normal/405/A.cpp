#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
int a,b[1000],i,j,d;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }

for( i=1; i<=a; i++ ){
   for( j=1; j<=a-1; j++ ){
      if(b[j]>b[j+1]){
         d=b[j];
         b[j]=b[j+1];
         b[j+1]=d;
       }
    }
 }

for( i=1; i<=a; i++ ){
   cout<<b[i]<<" ";
 }

return 0;
}