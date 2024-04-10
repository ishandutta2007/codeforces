#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int a[MAXN][2];
ll f[MAXN][2];

void dfs_f(int u,int fa)
{
	f[u][0] = f[u][1] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_f(v, u);
		
		for(int j=0; j<=1; ++j)
			f[u][j] += max(f[v][0] + abs(a[u][j] - a[v][0]), f[v][1] + abs(a[u][j] - a[v][1]));
	}
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i][0],&a[i][1]);
	etot = 0;
	memset(head, 0, (n+1)<<2);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_f(1,0);
	
	printf("%lld\n",max(f[1][0],f[1][1]));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}