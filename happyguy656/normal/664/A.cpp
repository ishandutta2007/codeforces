#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>

char a[103],b[103];
int main(void) {
	scanf("%s%s",a,b);
	if(!strcmp(a,b))puts(a);
	else puts("1");
	return 0;
}