#include<stdio.h>
#include<string.h>
char a[1024];
char b[1024];
int main(){
	scanf("%s%s",a,b);
	int A=0;
	int B=0;
	for(int i=0;a[i];i++)if(a[i]=='1')A++;
	for(int i=0;b[i];i++)if(b[i]=='1')B++;
	if(A+1<B)printf("NO\n");
	else if(A>=B)printf("YES\n");
	else if(A%2==1)printf("YES\n");
		else printf("NO\n");
}