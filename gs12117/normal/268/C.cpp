#include<stdio.h>
int main(){
	int a,b,i;
	scanf("%d%d",&a,&b);
	if(b<a)a=b;
	printf("%d\n",a+1);
	for(i=0;i<=a;i++){
		printf("%d %d\n",i,a-i);
	}
}