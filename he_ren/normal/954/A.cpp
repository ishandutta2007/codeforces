#include<cstdio>
const int MAXN = 1e2 + 5;

char s[MAXN];

int main(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	
	int ans=n;
	for(int i=1; i<n; ++i)
		if(s[i]!=s[i+1])
		{
			--ans;
			++i;
			continue;
		}
	printf("%d",ans);
	return 0;
}