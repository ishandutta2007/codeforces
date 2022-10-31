#include<stdio.h>
char t[128];
int main(){
	scanf("%s",t);
	int U=0;
	int L=0;
	for(int i=0;t[i];i++)if('A'<=t[i]&&t[i]<='Z')U++;else L++;
	if(U>L)for(int i=0;t[i];i++)t[i]=t[i]&(~32);
	else for(int i=0;t[i];i++)t[i]=t[i]|32;
	printf("%s\n",t);
}