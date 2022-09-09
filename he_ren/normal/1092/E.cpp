#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

vector<int> g[MAXN];

int anc[MAXN], dep[MAXN], mxdep;
bool vis[MAXN];
void dfs_tree(int u,int fa)
{
	vis[u] = 1; anc[u] = fa;
	if(dep[u] > dep[mxdep]) mxdep = u;
	for(int v: g[u]) if(v != fa)
	{
		dep[v] = dep[u] + 1;
		dfs_tree(v, u);
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	vector<pii> p;
	auto getfar = [&] (int rt)
	{
		dep[rt] = 0; mxdep = rt;
		dfs_tree(rt, 0);
		return mxdep;
	};
	for(int k=1; k<=n; ++k) if(!vis[k])
	{
		int u1 = getfar(k);
		int u2 = getfar(u1), len = dep[u2];
		
		int c = u2;
		while(dep[c] != len / 2) c = anc[c];
		p.emplace_back(len, c);
	}
	
	vector<pii> res;
	int pos = max_element(p.begin(), p.end()) - p.begin();
	for(int i=0; i<(int)p.size(); ++i) if(i != pos)
	{
		int u = p[i].second, v = p[pos].second;
		res.emplace_back(u, v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	int tmp = getfar(1);
	tmp = getfar(tmp);
	
	printf("%d\n",dep[tmp]);
	for(pii x: res) printf("%d %d\n",x.first,x.second);
	return 0;
}