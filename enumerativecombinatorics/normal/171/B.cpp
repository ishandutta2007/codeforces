#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	int ret=1;
	for(int i=1;i<a;i++)ret+=i*12;
	printf("%d\n",ret);
}