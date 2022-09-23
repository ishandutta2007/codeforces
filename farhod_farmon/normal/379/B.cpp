#include <iostream>
using namespace std;
int main()
{
int a,b[301],k=0,i,j;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }
for( j=1; j<=a; j++ ){
   for( i=1; i<=b[j]; i++ ){
      cout<<"P"; k++;
      if(i<b[j]){
         if(j<a){
            cout<<"R"; k++;
            if(b[j+1]>0){
               b[j+1]--;
               cout<<"PL"; k+=2;
             }
            else{
               cout<<"L"; k++;
             }
          }
         else{
            cout<<"LR"; k+=2;
          }
       }
    }
   if(j<a){
      cout<<"R"; k++;
    }
 }
return 0;
}