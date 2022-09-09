#include<cstdio>
const int MAXN = 2e5 + 5;

int p[MAXN],ans[MAXN];
bool vis[MAXN];
void dfs(int fa,int u,int dep)
{
	vis[u]=1;
	if(p[u] == fa)
	{
		ans[u]=dep;
		return;
	}
	dfs(fa,p[u],dep+1);
	ans[u] = ans[p[u]];
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	for(int i=1; i<=n; ++i)
		vis[i]=0, ans[i]=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i]) dfs(i,i,1);
	for(int i=1; i<=n; ++i) printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int Q;
	scanf("%d",&Q);
	while(Q--) solve();
	return 0;
}