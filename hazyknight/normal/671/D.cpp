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

typedef long long ll;

const int MAXN = 300005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

struct Node
{
	int lch,rch;
	int to,size;
	ll laz,val;
}node[MAXN];

int n,m,id;
int first[MAXN];
int dfn[MAXN];
int sum[MAXN];
int R[MAXN];
int rt[MAXN];
int depth[MAXN];

ll ans;

void modify(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += p & -p;
	}
}

int query(int p)
{
	int res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= p & -p;
	}
	return res;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int u,ll v)
{
	if (u)
	{
		node[u].val += v;
		node[u].laz += v;
	}
}

void pushdown(int u)
{
	if (node[u].laz)
	{
		add(node[u].lch,node[u].laz);
		add(node[u].rch,node[u].laz);
		node[u].laz = 0;
	}
}

int merge(int u,int v)
{
	if (!u || !v)
		return u | v;
	pushdown(u);
	pushdown(v);
	if (node[u].val > node[v].val)
		swap(u,v);
	node[u].rch = merge(node[u].rch,v);
	if (node[node[u].lch].size < node[node[u].rch].size)
		swap(node[u].lch,node[u].rch);
	node[u].size = node[node[u].lch].size + 1 + node[node[u].rch].size;
	return u;
}

void pop(int &r)
{
	pushdown(r);
	r = merge(node[r].lch,node[r].rch);
}

void dfs1(int u,int fa)
{
	dfn[u] = ++id;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			depth[edge[i].to] = depth[u] + 1;
			dfs1(edge[i].to,u);
		}
	R[u] = id;
}

void dfs2(int u,int fa)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs2(edge[i].to,u);
			rt[u] = merge(rt[u],rt[edge[i].to]);
		}
	while (rt[u] && depth[node[rt[u]].to] >= depth[u])
		pop(rt[u]);
	if (u != 1 && query(R[u]) == query(dfn[u] - 1))
	{
		if (!rt[u])
		{
			puts("-1");
			exit(0);
		}
		modify(dfn[u],1);
		modify(dfn[node[rt[u]].to],-1);
		ans += node[rt[u]].val;
		add(rt[u],-node[rt[u]].val);
		pop(rt[u]);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	id = 0;
	dfs1(1,0);
	for (int u,v,w,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		node[i].to = v;
		node[i].val = w;
		rt[u] = merge(rt[u],i);
	}
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}