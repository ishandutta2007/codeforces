#include <iostream>
using namespace std;
int main ()
{
int i,a,b[100],chest=0,biceps=0,back=0;
cin>>a;
for(  i=1; i<=a; i++ ){
   cin>>b[i];
 }

for( i=1; i<=a; i+=3 ){
   chest+=b[i];
 }

for( i=2; i<=a; i+=3 ){
   biceps+=b[i];
 }

for( i=3; i<=a; i+=3 ){
   back+=b[i];
 }

if(back>biceps && back>chest){
   cout<<"back";
 }

else if(back<biceps && biceps>chest){
   cout<<"biceps";
 }

else {
   cout<<"chest";
 }

 return 0;
}