#include<stdio.h>
int b[100000];
int c[4];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	int ret=0;
	for(int i=0;i<a;i++)c[b[i]-1]++;
	ret+=c[3];
	c[0]-=c[2];
	ret+=c[2];
	ret+=c[1]/2;
	if(c[1]%2){
		ret++;
		c[0]-=2;
	}
	if(c[0]<0)c[0]=0;
	ret+=(c[0]+3)/4;
	printf("%d\n",ret);
}