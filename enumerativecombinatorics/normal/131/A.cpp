#include<stdio.h>
char str[128];
int main(){
	scanf("%s",str);
	bool ok=true;
	for(int i=1;str[i];i++)if((str[i]|32)==str[i])ok=false;
	if(ok){
		for(int i=0;str[i];i++)str[i]^=32;
	}
	printf("%s\n",str);
}