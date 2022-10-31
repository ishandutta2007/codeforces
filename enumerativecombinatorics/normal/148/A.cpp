#include<stdio.h>
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int ret=0;
	for(int i=1;i<=e;i++)if(i%a==0||i%b==0||i%c==0||i%d==0)ret++;
	printf("%d\n",ret);
}