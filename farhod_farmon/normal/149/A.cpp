#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int a,b[12],i,d=0,g=0;
cin>>a;
for(i=1; i<=12; i++){
   cin>>b[i];
 }
    sort(b+1,b+12+1);
for(i=12; i>=1; i--){
       if(d<a){
          d+=b[i];
          g++;
        }
       if(d>=a){
          break;
        }
     }
if(d>=a){
   cout<<g;
 }
else{
   cout<<-1;
 }
return 0;
}