#include<stdio.h>
int n,m;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1");
	}
	else if(m*2>n){
		printf("%d",m-1);
	}
	else{
		printf("%d",m+1);
	}
	return 0;
}