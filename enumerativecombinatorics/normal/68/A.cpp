#include<stdio.h>
int main(){
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ret=0;
	for(int i=e;i<=f;i++)if(i%a%b%c%d==i)ret++;
	printf("%d\n",ret);
}