#include <iostream>
using namespace std;
int main()
{
int a,b[100001],dima=0,serega=0,i,j,t1,t2;
cin>>a;
for( i=1; i<=a; i++ ){
   cin>>b[i];
 }
t1=1;
t2=a;
for( i=1; i<=a; i++ ){
   if(i%2!=0){
      if(b[t1]>b[t2]){
         serega+=b[t1];
         t1++;
       }
      else{
         serega+=b[t2];
         t2--;
       }
    }
   else{
      if(b[t1]>b[t2]){
         dima+=b[t1];
         t1++;
       }
      else{
         dima+=b[t2];
         t2--;
       }
    }
}
cout<<serega<<" "<<dima;
return 0;
}