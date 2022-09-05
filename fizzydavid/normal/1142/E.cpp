//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 100111;
int n, m;
bool vis[maxn];
int dfn[maxn], dtot, low[maxn];
int g[maxn], gtot, st[maxn], stn;
vector<int> ncon[maxn];
vector<int> con[maxn];
int deg[maxn];
vector<int> G[maxn];
void tarjan(int x)
{
	dfn[x] = low[x] = ++dtot; st[stn++] = x;
	for (auto u : con[x])
	{
		if (!dfn[u])
		{
			tarjan(u);
			low[x] = min(low[x], low[u]);
		}
		else if (!g[u])
		{
			low[x] = min(low[x], dfn[u]);
		}
	}
	if (low[x]==dfn[x])
	{
		gtot++;
		while (true)
		{
			int u = st[--stn];
			g[u] = gtot;
			G[gtot].PB(u);
			if (u==x) break;
		}
	}
}
void prework()
{
	for (int i=1; i<=n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i);
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (auto u : con[i])
		{
			if (g[i]!=g[u])
			{
				ncon[g[i]].PB(g[u]);
				deg[g[u]]++;
			}
		}
	}
//	for (int i=1; i<=n; i++) cerr<<g[i]<<" "; cerr<<endl;
}
int comp_node(int x, int y)
{
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	if (ret==-1) exit(0);
	if (ret==0) return y; else return x;
}
vector<int> v;
void pop_back(int x)
{
	G[v[x]].pop_back();
	if (G[v[x]].size()==0)
	{
		for (auto u : ncon[v[x]])
		{
			deg[u]--;
			if (deg[u]==0) v.PB(u);
		}
		swap(v[x], v.back());
		v.pop_back();
	}
}
void solve()
{
	for (int i=1; i<=gtot; i++)
	{
		if (deg[i]==0) v.PB(i);
	}
	assert(v.size()>0);
	assert(G[v[0]].size()>0);
	int x = G[v[0]].back();
	while (v.size()>1)
	{
//		cerr<<"solve x="<<x<<endl;
//		for (auto t : v) cerr<<t<<" "; cerr<<endl;
		for (int i=0; i<v.size(); i++)
		{
			if (v[i]!=g[x])
			{
				assert(G[v[i]].size()>0);
				int y = G[v[i]].back();
				int nxt = comp_node(x, y);
				if (nxt==x)
				{
					pop_back(i);
				}
				else
				{
					swap(v[0], v[i]);
					pop_back(i);
				}
				x = nxt;
				break;
			}
		}
	}
	printf("! %d\n", x);
	fflush(stdout);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		con[x].PB(y);
	}
	prework();
	solve();
	return 0;
}