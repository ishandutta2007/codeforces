#include<stdio.h>
char str[200001];
int main(){
	int a;
	scanf("%d%s",&a,str);
	int ok=0;
	for(int i=0;i<a;i++)if(str[i]=='I')ok++;
	if(ok>1)printf("0\n");
	else if(ok==1){
		int ret=0;
		for(int i=0;i<a;i++)if(str[i]=='I')ret++;
		printf("%d\n",ret);
	}else{
		int ret=0;
		for(int i=0;i<a;i++)if(str[i]=='A')ret++;
		printf("%d\n",ret);
	}
}