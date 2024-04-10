#include <cstdio>
#include <algorithm>
using namespace std;
 int num[105];
 int main(){
     int n;
     scanf("%d",&n);
     int sum=0;
     for(int i=1;i<=n;i++){
         scanf("%d",&num[i]);
         sum+=num[i];
     }
     int a,b;
     scanf("%d %d",&a,&b);
     int eo=0;
    while(1){   
      if(a==b) break;  
       eo+=num[a];     
    a++;      
   if(a==n+1) a=1; 
    }   
  printf("%d\n",min(sum-eo,eo));  
   return 0;
 }