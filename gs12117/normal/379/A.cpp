#include<stdio.h>
int n,m;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	printf("%d",(n*m-1)/(m-1));
	return 0;
}