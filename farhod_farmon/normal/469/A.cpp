#include <iostream>
using namespace std;
int main()
{
int a,b,c,b1[101],c1[101],i,j,d=0;
cin>>a;
cin>>b;
for( i=1; i<=b; i++ ){
   cin>>b1[i];
 }
cin>>c;
for( i=1; i<=c; i++ ){
   cin>>c1[i];
 }
for( j=1; j<=a; j++ ){
    for( i=1; i<=a; i++ ){
       if(j==b1[i] || j==c1[i]){
          d++;
          break;
        }
     }
 }
if(d==a){
   cout<<"I become the guy.";
 }
else {
   cout<<"Oh, my keyboard!";
 }
return 0;
}