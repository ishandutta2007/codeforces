#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

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

int son_cnt[MAXN];
int f[MAXN], g[MAXN];

void dfs_f(int u,int fa)
{
	f[u] = g[u] = 1;
	
	int cnt = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_f(v,u);
		++cnt;
	}	
	son_cnt[u] = cnt;
	
	int st=0, nd=0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa) continue;
		
		f[u] = max(f[u], f[v] + cnt-1 + 1);
		
		if(f[v] > st) nd = st, st = f[v];
		else if(f[v] > nd) nd = f[v];
	}
	
	if(cnt<=1) g[u] = f[u];
	else g[u] = max(f[u], st + nd + cnt-2 + 1);
}

int ans = 0;
void dfs_ans(int u,int fa)
{
	ans = max(ans, g[u] + (bool)fa);
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_ans(v,u);
	}
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) head[i] = 0;
	etot = 0;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_f(1,0);
	ans = 0;
	dfs_ans(1,0);
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}