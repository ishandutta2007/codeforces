#include<stdio.h>
char str[51];
int main(){
	int a;
	scanf("%d%s",&a,str);
	int ret=0;
	for(int i=1;i<a;i++)if(str[i]==str[i-1])ret++;
	printf("%d\n",ret);
}