#include<cstdio>
const int MAXN = 1e2 + 5;

char s[MAXN];

void solve(void)
{
	int n;
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=(n>>1); ++i)
	{
		int j=n-i+1;
		if(s[i]==s[j]) continue;
		if(s[i]+1==s[j]-1) continue;
		if(s[i]-1==s[j]+1) continue;
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}