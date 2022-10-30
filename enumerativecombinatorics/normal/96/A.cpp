#include<stdio.h>
char str[128];
int main(){
	scanf("%s",str);
	int c=0;
	char now='2';
	for(int i=0;str[i];i++){
		if(now==str[i]){
			c++;
			if(c==7){printf("YES\n");return 0;}
		}else {
			now=str[i];
			c=1;
		}
	}
	printf("NO\n");
}