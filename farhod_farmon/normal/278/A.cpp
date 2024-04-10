#include <iostream>
using namespace std;
int main()
{
int a,b[101],minn=0,i,d1,d2,c,d;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }
cin>>c>>d;
if(c<d){
   d1=c;
   d2=d;
 }
else{
   d2=c;
   d1=d;
 }
for( i=d1; i<d2; i++ ){
   minn+=b[i];
 }
int maxn=0;
for( i=d2; i<=a; i++ ){
   maxn+=b[i];
 }
for( i=1; i<d1; i++ ){
   maxn+=b[i];
 }
cout<<min(minn,maxn);
return 0;
}