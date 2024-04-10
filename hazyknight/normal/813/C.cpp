#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 200005;

int n,x;
int ans;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int id,first[MAXN];
int fa[MAXN][20];
int depth[MAXN];

vector<int> le;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now)
{
	for (int i = 1;i <= 18;i++)
		fa[now][i] = fa[fa[now][i - 1]][i - 1];
	bool ok = false;
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa[now][0])
		{
			ok = true;
			fa[edge[i].to][0] = now;
			depth[edge[i].to] = depth[now] + 1;
			dfs(edge[i].to);
		}
	if (!ok)
		le.push_back(now);
}

int LCA(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	for (int i = 18;i >= 0;i--)
		if (depth[fa[u][i]] >= depth[v])
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 18;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> x;
	for (int u,v,i = 1;i < n;i++)
		cin >> u >> v,addE(u,v),addE(v,u);
	dfs(1);
	for (int i = 0;i < le.size();i++)
	{
		int lca = LCA(x,le[i]);
		if (depth[x] - depth[lca] >= depth[lca])
			continue;
		ans = max(ans,depth[le[i]] << 1);
	}
	cout << ans << endl;
	return 0;
}