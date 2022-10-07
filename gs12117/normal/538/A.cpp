#include<stdio.h>
#include<string.h>
char a[110];
int al;
char b[110]="CODEFORCES";
int bl;
int main(){
	int i;
	scanf("%s",a);
	al=strlen(a);
	bl=strlen(b);
	for(i=0;i<bl;i++){
		if(a[i]!=b[i])break;
	}
	for(;i<bl;i++){
		if(a[i+al-bl]!=b[i])break;
	}
	if(i==bl){
		printf("YES");
	}
	else{
		printf("NO");
	}
}