#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,q,id,cc;
int u[MAXN];
int v[MAXN];
int R[MAXN];
int up[MAXN];
int dn[MAXN];
int par[MAXN];
int dfn[MAXN];
int low[MAXN];
int bel[MAXN];
int depth[MAXN];
int first[MAXN];
int fa[MAXN][20];

bool vis[MAXN];

stack<int> S;
set<pair<int,int> > Es;

int getroot(int u)
{
	return u == par[u] ? u : par[u] = getroot(par[u]);
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void modify(int *arr,int p,int v)
{
	while (p <= cc)
	{
		arr[p] += v;
		p += p & -p;
	}
}

int query(int *arr,int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += arr[p];
		p -= p & -p;
	}
	return res;
}

int getlca(int u,int v)
{
	if (depth[u] < depth[v])
		swap(u,v);
	int dif = depth[u] - depth[v];
	for (int i = 19;i >= 0;i--)
		if (dif >> i & 1)
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 19;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

void dfs(int u,int par)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	S.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (i == par)
			continue;
		if (!dfn[edge[i].to])
		{
			dfs(edge[i].to,i ^ 1);
			low[u] = min(low[u],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[u] = min(low[u],dfn[edge[i].to]);
	}
	if (dfn[u] == low[u])
	{
		cc++;
		while (S.top() != u)
		{
			bel[S.top()] = cc;
			vis[S.top()] = 0;
			S.pop();
		}
		bel[u] = cc;
		vis[u] = 0;
		S.pop();
	}
}

void getinfo(int u)
{
	dfn[u] = ++id;
	for (int i = 1;i < 20;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			fa[edge[i].to][0] = u;
			depth[edge[i].to] = depth[u] + 1;
			getinfo(edge[i].to);
		}
	R[u] = id;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++)
		par[i] = i;
	id = 1;
	for (int i = 1;i <= m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		addE(u[i],v[i]);
		addE(v[i],u[i]);
		par[getroot(u[i])] = getroot(v[i]);
	}
	id = 0;
	for (int i = 1;i <= n;i++)
		if (!dfn[i])
			dfs(i,0);
	memset(first,0,sizeof(first));
	id = 0;
	for (int i = 1;i <= m;i++)
		if (bel[u[i]] != bel[v[i]] && Es.find(make_pair(bel[u[i]],bel[v[i]])) == Es.end())
		{
			addE(bel[u[i]],bel[v[i]]);
			addE(bel[v[i]],bel[u[i]]);
			Es.insert(make_pair(bel[u[i]],bel[v[i]]));
			Es.insert(make_pair(bel[v[i]],bel[u[i]]));
		}
	id = 0;
	memset(dfn,0,sizeof(dfn));
	for (int i = 1;i <= cc;i++)
		if (!dfn[i])
			getinfo(i);
	for (int i = 1;i <= q;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		if (getroot(u[i]) != getroot(v[i]))
		{
			puts("No");
			return 0;
		}
		u[i] = bel[u[i]];
		v[i] = bel[v[i]];
		int lca = getlca(u[i],v[i]);
		u[i] = dfn[u[i]];
		v[i] = dfn[v[i]];
		lca = dfn[lca];
		modify(up,u[i],1);
		modify(up,lca,-1);
		modify(dn,v[i],1);
		modify(dn,lca,-1);
	}
	for (int i = 1;i <= cc;i++)
		if (query(up,R[i]) > query(up,dfn[i] - 1) && query(dn,R[i]) > query(dn,dfn[i] - 1))
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	return 0;
}