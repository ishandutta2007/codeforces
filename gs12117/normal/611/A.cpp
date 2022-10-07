#include<stdio.h>
int n;
char s[100];
char w[100];
int main(){
	scanf("%d%s%s",&n,s,w);
	if(w[0]=='m'){
		if(n<=29)printf("12");
		else if(n==30)printf("11");
		else if(n==31)printf("7");
	}
	else{
		if(n==5||n==6)printf("53");
		else printf("52");
	}
}