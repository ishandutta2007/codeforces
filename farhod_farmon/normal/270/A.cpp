#include <iostream>
using namespace std;
int main ()
{
int a,b[1000],i;
cin>>a;
for(i=1; i<=a; i++){
   cin>>b[i];
 }

for(i=1; i<=a; i++){
   if(360%(180-b[i])==0){
      cout<<"YES"<<endl;
    }
    else{
       cout<<"NO"<<endl;
     }
 }
return 0;
}