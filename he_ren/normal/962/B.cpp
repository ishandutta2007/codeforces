#include<cstdio>
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	int n,a,b;
	scanf("%d%d%d%s",&n,&a,&b,s+1);
	
	int ans=0;
	for(int i=1; i<=n && (a||b); ++i)
	{
		if(s[i]=='*') continue;
		if(s[i-1]=='A' && b) s[i]='B', --b, ++ans;
		if(s[i-1]=='B' && a) s[i]='A', --a, ++ans;
		if(s[i-1]<'A' || s[i-1]>'Z')
		{
			if(a>b) s[i]='A', --a, ++ans;
			else s[i]='B', --b, ++ans;
		}
	}
	printf("%d",ans);
	return 0;
}