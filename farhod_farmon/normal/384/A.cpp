#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int a,i,j,d;
scanf("%d",&a);
if(a%2==0){
   d=(a*a)/2;
 }
else{
   d=(a*a)/2+1;
 }
printf("%d\n",d);
for( i=1; i<=a; i++ ){
   for( j=1; j<=a; j++ ){
      if(i%2==0){
         if(j%2==0){
            printf("C");
          }
         else{
            printf(".");
          }
       }
      else{
         if(j%2==0){
            printf(".");
          }
         else{
            printf("C");
          }
       }
    }
   printf("\n");
 }
return 0;
}