#include<stdio.h>
#include<string.h>
char s[100100];
int n;
int main(){
	int i;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++){
		if(s[i]!='a')break;
	}
	if(i==n){
		s[n-1]='z';
	}
	else{
		for(;i<n;i++){
			if(s[i]=='a')break;
			s[i]--;
		}
	}
	puts(s);
	return 0;
}