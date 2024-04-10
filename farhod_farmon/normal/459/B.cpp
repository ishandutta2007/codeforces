#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
long long int a,b[1000000],i,j,f1=0,f2=0;
cin>>a;

for( i=1; i<=a; i++ ){
    cin>>b[i];
 }

sort(b+1,b+a+1);

for( i=1; i<=a; i++ ){
   if(b[1]==b[i] ){f1++;}
   if(b[a]==b[i] ){f2++;}
 }

cout<<b[a]-b[1]<<" "<<((b[a]==b[1])?((f2*(f2-1))/2):(f2*f1));

return 0;
}