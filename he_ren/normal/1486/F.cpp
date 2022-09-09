#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXP = 3e5 + 5;
const int MAXN = 9e5 + 5;
const int MAXM = 3e5 + 5;

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

int anc[MAXP], dep[MAXP], siz[MAXP], son[MAXP], top[MAXP], dfn[MAXP], seq[MAXP], cur_dfn = 0;
void dfs_siz(int u,int fa)
{
	anc[u] = fa;
	siz[u] = 1; son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs_siz(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs_top(int u,int fa)
{
	dfn[u] = ++cur_dfn; seq[dfn[u]] = u;
	if(son[u] != -1) top[son[u]] = top[u], dfs_top(son[u], u);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		top[v] = v; dfs_top(v,u);
	}
}

inline int lca(int u,int v)
{
	while(top[u] != top[v])
	{
		if(dep[top[u]] > dep[top[v]]) u = anc[top[u]];
		else v = anc[top[v]];
	}
	return dep[u] > dep[v]? v: u;
}

inline int get_sub(int u,int v)
{
	while(1)
	{
		if(anc[u] == v) return u;
		if(u == top[u]) u = anc[u];
		if(dep[top[u]] > dep[v]) u = top[u];
		if(top[u] == top[v]) return seq[dfn[v] + 1];
	}
}

ll ans = 0;
int tag[MAXN];
vector<pii> vecs[MAXN];

void dfs_ans(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_ans(v,u);
		tag[u] += tag[v];
	}
	
	vector<pii> &vec = vecs[u];
	static int cnt[MAXN];
	map<pii,int> t;
	for(int i=0; i<(int)vec.size(); ++i)
	{
		int &v1 = vec[i].first, &v2 = vec[i].second;
		--tag[v1]; --tag[v2]; tag[u] -= 2;
		if(v1 > v2) swap(v1, v2);
		
		ans += i - cnt[v1] - cnt[v2] + t[vec[i]];
		++t[vec[i]]; ++cnt[v1]; ++cnt[v2];
	}
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		
		ans += (ll)tag[v] * ((int)vec.size() - cnt[v]);
	}
	
	for(int i=0; i<(int)vec.size(); ++i)
		cnt[vec[i].first] = cnt[vec[i].second] = 0;
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
	
	dfs_siz(1,0);
	top[1] = 1; dfs_top(1,0);
	
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		
		int uv = lca(u,v);
		int su = uv == u? n+1: get_sub(u, uv);
		++n; add(u, n); add(n, u); u = n;
		
		int sv = uv == v? n+1: get_sub(v,uv);
		++n; add(v, n); add(n, v); v = n;
		
//		printf("uv = %d, su = %d, sv = %d, u = %d, v = %d\n",uv,su,sv,u,v);
		
		++tag[u]; ++tag[v];
		vecs[uv].push_back(make_pair(su, sv));
	}
	
	dfs_ans(1,0);
	
	printf("%lld",ans);
	return 0;
}