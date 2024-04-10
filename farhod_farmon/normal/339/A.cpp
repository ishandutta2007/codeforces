#include <iostream>
using namespace std;
int main ()
{
string a;
char b[10000],d;
int i,g,f=1,j;
cin>>a;
g=a.size();
for( i=0; i<g; i+=2 ){
   b[f]=a[i];
   f++;
 }

for(j=1; j<=f; j++){
   for( i=1; i<f; i++ ){
   if(b[i]>b[i+1]){
      d=b[i];
      b[i]=b[i+1];
      b[i+1]=d;
    }
 }
 }

for(i=2; i<f; i++){
   cout<<b[i]<<"+";
 }
cout<<b[f];
return 0;
}