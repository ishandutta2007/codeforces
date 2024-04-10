#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int ret=0;
	for(int i=0;i<a;i++){
		int b,c,d;
		scanf("%d%d%d",&b,&c,&d);
		if(b+c+d>=2)ret++;
	}
	printf("%d\n",ret);
}