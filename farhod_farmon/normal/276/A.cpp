#include <iostream>
using namespace std;
int main()
{
int a,v,f[100001],t[100001],i,max1=-999999999;
cin>>a>>v;
for( i=1; i<=a; i++ ){
   cin>>f[i]>>t[i];
 }
for( i=1; i<=a; i++ ){
   if(t[i]<=v){
      if(max1<f[i]){
         max1=f[i];
       }
    }
   else{
      if(max1<f[i]-(t[i]-v)){
         max1=f[i]-(t[i]-v);
       }
    }
 }
cout<<max1;
return 0;
}