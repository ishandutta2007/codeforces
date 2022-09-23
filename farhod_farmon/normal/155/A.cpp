#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
int a,b[1000],j,i,f=0,f1=0,g=0,g1=0,fa=0,ker=0;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
   ker++;
 }
 farhod:
 f1++;
   for(j=f1; j>=1; j--){
      if(b[f1]>b[j]){
         g++;
       }
      if(b[f1]<b[j]){
         g1++;
       }
    }

   if(g==f1-1 || g1==f1-1){
      fa++;
    }
   g1=0;
   g=0;

   if(f1<ker){
    goto farhod;
    }
cout<<fa-1;
return 0;
}