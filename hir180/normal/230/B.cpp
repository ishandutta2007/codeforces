#include <stdio.h>
#include <math.h>
  int main(){
long long n,i,j,a=0,num=0;
double c;
scanf("%I64d",&n);
for(i=0;i<n;i++){
	scanf("%lf",&c);
	c=pow(c,0.5);
	 int d=c;
 for(j=2;j*j<=d;j++){
  if(d%j==0) {num=1; goto qq;}
 }qq: 
if(num==0){if(c-d==0){if(d!=1&&d!=0){
	printf("YES\n"); goto q;}
}}printf("NO\n");
q:;
num=0;
	  }
	  return 0;
  }