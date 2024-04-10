#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
		if(s[i]=='1') ++cnt;
	for(int i=1; i<=n; ++i)
	{
		if(s[i]=='2')
			while(--cnt>=0) putchar('1');
		if(s[i]!='1') putchar(s[i]);
	}
	while(--cnt>=0)  putchar('1');
	return 0;
}