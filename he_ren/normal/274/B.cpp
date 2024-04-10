#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

inline ll Abs(ll x){ return x<0? -x: x;}

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

int a[MAXN];

ll f[MAXN], g[MAXN];
void dfs_fg(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		dfs_fg(v,u);
		f[u] = max(f[u], f[v]);
		g[u] = max(g[u], g[v]);
	}
	
	ll x = a[u] + f[u] - g[u];
	if(x > 0) g[u] += x;
	else f[u] += -x;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	dfs_fg(1,0);
	
	cout << f[1] + g[1];
	return 0;
}