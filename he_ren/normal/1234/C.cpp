#include<cstdio>
const int MAXN = 2e5 + 5;

int n;
char s[3][MAXN];
int a[3][MAXN];

inline void dfs(int i,int j,int d)
{
	if(j>n)
	{
		if(i) printf("YES\n");
		else printf("NO\n");
		return;
	}
	
	if(a[i][j])
	{
		if(d) dfs(i,j+1,0);
		else dfs(i^1,j,1);
	}
	else
	{
		if(d)
		{
			printf("NO\n");
			return;
		}
		dfs(i,j+1,d);
	}
}

inline void solve(void)
{
	scanf("%d%s%s",&n,s[0]+1,s[1]+1);
	for(int i=0; i<=1; ++i)
		for(int j=1; j<=n; ++j)
			a[i][j] = (s[i][j]>'2');
	
	dfs(0,1,0);
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}