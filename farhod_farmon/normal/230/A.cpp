#include <iostream>
using namespace std;
int main ()
{
int a,b,x[100000],y[100000],i,j,f;
cin>>a>>b;
for( i=1; i<=b; i++ ){
   cin>>x[i]>>y[i];
 }
for( j=1; j<=b; j++ ){
   for( i=1; i<b; i++ ){
      if(x[i]>x[i+1]){
         f=x[i];
         x[i]=x[i+1];
         x[i+1]=f;

         f=y[i];
         y[i]=y[i+1];
         y[i+1]=f;
       }
    }
 }
for( i=1; i<=b; i++ ){
   if(a>x[i]){
      a+=y[i];
    }
   else{
      cout<<"NO";
      return 0;
    }
 }
cout<<"YES";
return 0;
}