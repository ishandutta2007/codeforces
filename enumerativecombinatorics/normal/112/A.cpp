#include<stdio.h>
char s[128];
char t[128];
int main(){
	scanf("%s%s",s,t);
	for(int i=0;s[i];i++){
		s[i]|=32;
		t[i]|=32;
		if(s[i]>t[i]){
			printf("1\n");return 0;
		}
		if(s[i]<t[i]){
			printf("-1\n");return 0;
		}
	}
	printf("0\n");
}