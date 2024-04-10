#include <iostream>
using namespace std;
int main()
{
int a,c,b[1001],i,d=0,d1,d2;
cin>>a>>c;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }
for( i=1; i<a; i++ ){
   if(b[i]-b[i+1]>d && b[i]-b[i+1]-c>0){
      d=b[i]-b[i+1];
    }
 }
if(d-c<0){
   cout<<0;
 }
else{
   cout<<d-c;
 }
return 0;
}