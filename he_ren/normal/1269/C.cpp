#include<cstdio>
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d%s",&n,&d,s+1);
	
	bool flag=1;
	for(int i=d+1; i<=n; ++i)
		if(s[i-d]!=s[i])
		{
			flag = (s[i-d]>=s[i]);
			break;
		}
	if(flag)
	{
		for(int i=d+1; i<=n; ++i)
			s[i]=s[i-d];
		printf("%d\n%s",n,s+1);
		return 0;
	}
	
	for(int i=d; i>=1; --i)
	{
		if(s[i]!='9'){ ++s[i]; break;}
		else s[i]='0';
	}
	for(int i=d+1; i<=n; ++i) s[i]=s[i-d];
	printf("%d\n%s",n,s+1);
	return 0;
}