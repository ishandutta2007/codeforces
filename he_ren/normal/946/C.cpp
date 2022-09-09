#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;

char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	char now='a';
	for(int i=1; i<=n; ++i)
		if(now >= s[i])
		{
			s[i]=now;
			++now;
			if(now>'z') break;
		}
	if(now<='z') printf("-1");
	else printf("%s",s+1);
	return 0;
}