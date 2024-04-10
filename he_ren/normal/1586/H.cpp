#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;
const int LB = 17 + 2;
const int inf = 0x3f3f3f3f;

int lb[MAXN];

vector<int> g[MAXN], gw[MAXN];
array<int,4> es[MAXN];

int dep[MAXN], anc[MAXN][LB], mxw[MAXN][LB];
void dfs_tree(int u,int fa)
{
	for(int i=1; i<=lb[dep[u]]; ++i)
		anc[u][i] = anc[anc[u][i-1]][i-1],
		mxw[u][i] = max(mxw[u][i-1], mxw[anc[u][i-1]][i-1]);
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i], w = gw[u][i];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		anc[v][0] = u; mxw[v][0] = w;
		dfs_tree(v, u);
	}
}

inline int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	while(dep[u] > dep[v]) u = anc[u][lb[dep[u] - dep[v]]];
	if(u == v) return u;
	for(int i=lb[dep[u]]; anc[u][0] != anc[v][0]; --i)
		if(i <= lb[dep[u]] && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

inline int get_mxw_anc(int u,int v)// v is anc of u
{
	int res = 0;
	while(dep[u] > dep[v])
	{
		int k = lb[dep[u] - dep[v]];
		res = max(res, mxw[u][k]); u = anc[u][k];
	}
	return res;
}
inline int get_mxw(int u,int v)
{
	int uv = lca(u,v);
	return max(get_mxw_anc(u,uv), get_mxw_anc(v,uv));
}

int a[MAXN];
array<int,3> qry[MAXQ];
pii res[MAXQ];

int fa[MAXN];
int mxa[MAXN], pt[MAXN], val[MAXN];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v)
{
	u = find(u); v = find(v);
	if(u == v) return;
	if(mxa[u] < mxa[v]) swap(u, v);
	if(mxa[u] == mxa[v])
	{
		val[u] = max(val[u], val[v]);
		val[u] = max(val[u], get_mxw(pt[u], pt[v]));
	}
	fa[v] = u;
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v,c,w;
		scanf("%d%d%d%d",&u,&v,&c,&w);
		es[i] = {c,u,v,w};
		g[u].push_back(v); gw[u].push_back(w);
		g[v].push_back(u); gw[v].push_back(w);
	}
	for(int i=1; i<=Q; ++i)
		scanf("%d%d",&qry[i][0],&qry[i][1]), qry[i][2] = i;
	
	dfs_tree(1,0);
	
	sort(es+1,es+n); reverse(es+1,es+n);
	sort(qry+1,qry+Q+1); reverse(qry+1,qry+Q+1);
	es[n] = {-inf, -1, -1, -1};
	
	for(int i=1; i<=n; ++i)
	{
		fa[i] = i;
		mxa[i] = a[i]; pt[i] = i;
		val[i] = 0;
	}
	
	for(int i=1,j=1; i<=n; ++i)
	{
		for(; j<=Q && qry[j][0] > es[i][0]; ++j)
		{
			int u = qry[j][1], id = qry[j][2];
			int fu = find(u);
			res[id].first = mxa[fu];
			res[id].second = max(val[fu], get_mxw(u, pt[fu]));
		}
		if(i < n) connect(es[i][1], es[i][2]);
	}
	
	for(int i=1; i<=Q; ++i) printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}