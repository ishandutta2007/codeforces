#include <iostream>
using namespace std;
int main()
{
int a,v,i,j,b[100001],c[1001][1001],d[100001],f=0;
cin>>a>>v;
for( j=1; j<=a; j++ ){
   cin>>b[j];
   for( i=1; i<=b[j]; i++ ){
      cin>>c[j][i];
    }
 }
for( j=1; j<=a; j++ ){
   for( i=1; i<=b[j]; i++ ){
      if(c[j][i]<v){
         d[f]=j;
         f++;
         break;
       }
    }
 }
cout<<f<<endl;
for( i=0; i<f; i++ ){
   cout<<d[i]<<" ";
 }
return 0;
}