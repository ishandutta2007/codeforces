#include<stdio.h>
int n,t,digit;
int main(){
	scanf("%d%d",&n,&t);
	int i,tt=t;
	for(digit=0;tt>0;digit++){
		tt/=10;
	}
	if(digit>n)printf("-1");
	else{
		printf("%d",t);
		for(i=0;i<n-digit;i++){
			printf("0");
		}
	}
}