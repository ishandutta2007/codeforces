#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

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

int ans = 0;
int dep[MAXN], f[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = inf;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs_f(v,u);
		if(fa) ans = max(ans, f[v] - dep[u] + 1);
		f[u] = min(f[u], f[v]);
	}
	if(f[u] == inf) f[u] = dep[u];
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	etot = 0;
	for(int i=1; i<=n; ++i) head[i] = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	ans = 0;
	dfs_f(1,0);
	
	int fir = 0, sec = 0;
	for(int i=head[1]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(f[v] >= fir) sec = fir, fir = f[v];
		else if(f[v] > sec) sec = f[v];
	}
	ans = max(ans, sec + 1);
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}