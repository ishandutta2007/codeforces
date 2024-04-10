#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int mod;

inline int get_phi(int x)
{
	int res = 1;
	for(int i=2; i*i<=x; ++i) if(x%i == 0)
	{
		res *= i-1; x /= i;
		while(x%i == 0) res *= i, x /= i;
	}
	if(x>1) res *= x-1;
	return res;
}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}
ll pw10[MAXN], ipw10[MAXN];

struct Edge
{
	int next,to,w;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot]=(Edge){ head[u],v,w};
	head[u]=etot;
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

vector<int> node;
int dep[MAXN], up[MAXN], down[MAXN];
void dfs_node(int u,int fa)
{
	node.push_back(u);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		
		dep[v] = dep[u] + 1;
		down[v] = ((ll)down[u] * 10 + e[i].w) %mod;
		up[v] = (up[u] + pw10[dep[u]] * e[i].w) %mod;
		
		dfs_node(v,u);
	}
}

ll ans = 0;
void divid(int u)
{
	dfs_siz(u,0);
	tot_siz = siz[root = u];
	dfs_root(u,0);
	vis[u = root] = 1;
	
	map<int,int> need, t;
	dep[u] = up[u] = down[u] = 0;
	need[0] = 1; t[0] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int cur = e[i].to;
		if(vis[cur]) continue;
		
		node.clear();
		dep[cur] = 1; up[cur] = down[cur] = e[i].w;
		dfs_node(cur,u);
		
		for(int k=0; k<(int)node.size(); ++k)
		{
			int v = node[k];
			if(need.find(up[v]) != need.end()) ans += need[up[v]];
			
			int x = ipw10[dep[v]] * (mod - down[v]) %mod;
			if(t.find(x) != t.end()) ans += t[x];
		}
		for(int k=0; k<(int)node.size(); ++k)
		{
			int v = node[k];
			++t[up[v]]; ++need[ipw10[dep[v]] * (mod - down[v]) %mod];
		}
	}
	t = need = map<int,int>();
	
	for(int i=head[u]; i; i=e[i].next)
		if(!vis[e[i].to]) divid(e[i].to);
}

int main(void)
{
	int n;
	scanf("%d%d",&n,&mod);
	if(mod == 1) return printf("%lld",(ll)n * (n-1)), 0;
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		++u; ++v; w %= mod;
		add(u,v,w); add(v,u,w);
	}
	
	pw10[0] = 1;
	for(int i=1; i<MAXN; ++i) pw10[i] = pw10[i-1] * 10 %mod;
	ipw10[MAXN-1] = pw(pw10[MAXN-1], get_phi(mod) - 1);
	for(int i=MAXN-2; i>=0; --i) ipw10[i] = ipw10[i+1] * 10 %mod;
	
	divid(1);
	
	printf("%lld",ans);
	return 0;
}