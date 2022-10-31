#include<stdio.h>
char str[128];
int main(){
	scanf("%s",str);
	for(int i=0;str[i];i++){
		if(str[i]=='H'||str[i]=='Q'||str[i]=='9'){
			printf("YES\n");return 0;
		}
	}
	printf("NO\n");return 0;
}