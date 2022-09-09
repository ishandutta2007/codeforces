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

bool vis[MAXN];
int siz[MAXN], mx_siz[MAXN];
void dfs_siz(int u,int fa)
{
	siz[u] = 1; mx_siz[u] = 0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		dfs_siz(v,u);
		siz[u] += siz[v]; mx_siz[u] = max(mx_siz[u], siz[v]);
	}
}

int root, tot_siz;
void dfs_root(int u,int fa)
{
	mx_siz[u] = max(mx_siz[u], tot_siz - siz[u]);
	if(mx_siz[u] < mx_siz[root]) root = u;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v != fa && !vis[v]) dfs_root(v,u);
	}
}

char dep[MAXN];
void divid(int u,int cur_dep)
{
	dfs_siz(u,0);
	tot_siz = siz[root = u];
	dfs_root(u,0);
	vis[u = root] = 1;
	dep[u] = cur_dep;
	
	for(int i=head[u]; i; i=e[i].next)
		if(!vis[e[i].to]) divid(e[i].to, cur_dep+1);
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
	
	divid(1,0);
	
	for(int i=1; i<=n; ++i) printf("%c ",dep[i] + 'A');
	return 0;
}