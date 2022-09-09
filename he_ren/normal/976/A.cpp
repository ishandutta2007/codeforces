#include<cstdio>
const int MAXN = 1e2 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	if(n==1){ printf("%s",s+1); return 0;}
	
	putchar('1');
	for(int i=1; i<=n; ++i)
		if(s[i]=='0') putchar('0');
	return 0;
}