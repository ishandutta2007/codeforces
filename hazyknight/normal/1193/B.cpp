#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>
 
using namespace std;

typedef long long ll;

const int MAXN = 100005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

struct Node
{
	int lch,rch;
	ll laz,add;
}node[MAXN << 6];

int n,m,id,MX;
int first[MAXN];
int d[MAXN];
int w[MAXN];
int rt[MAXN];

queue<int> Q;

int newnode()
{
	if (Q.empty())
		return ++id;
	int r = Q.front();
	Q.pop();
	return r;
}

void recycle(int u)
{
	Q.push(u);
	node[u].lch = node[u].rch = node[u].laz = node[u].add = 0;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int o,ll v)
{
	node[o].add += v;
	node[o].laz += v;
}

void laz(int o,ll v)
{
	node[o].laz = max(node[o].laz,v);
}

void pushdown(int u)
{
	if (!node[u].lch)
		node[u].lch = ++id;
	if (!node[u].rch)
		node[u].rch = ++id;
	add(node[u].lch,node[u].add);
	add(node[u].rch,node[u].add);
	node[u].add = 0;
	laz(node[u].lch,node[u].laz);
	laz(node[u].rch,node[u].laz);
	node[u].laz = 0;
}

int merge(int u,int v,int l,int r)
{
	if (!u || !v)
		return u | v;
	if (l == r)
	{
		add(u,node[v].laz);
		recycle(v);
		return u;
	}
	if (!node[u].lch && !node[u].rch)
	{
		pushdown(v);
		add(v,node[u].laz);
		recycle(u);
		return v;
	}
	if (!node[v].lch && !node[v].rch)
	{
		pushdown(u);
		add(u,node[v].laz);
		recycle(v);
		return u;
	}
	pushdown(u);
	pushdown(v);
	int mid = l + r >> 1;
	node[u].lch = merge(node[u].lch,node[v].lch,l,mid);
	node[u].rch = merge(node[u].rch,node[v].rch,mid + 1,r);
	recycle(v);
	return u;
}

int modify(int o,int l,int r,int p,ll v)
{
	if (!o)
		o = newnode();
	if (l >= p)
	{
		laz(o,v);
		return o;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= p)
		node[o].lch = modify(node[o].lch,l,mid,p,v);
	node[o].rch = modify(node[o].rch,mid + 1,r,p,v);
	return o;
}

ll query(int o,int l,int r,int p)
{
	if (!o)
		return 0;
	if (l == r)
		return node[o].laz;
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= p)
		return max(node[o].laz,query(node[o].lch,l,mid,p));
	return max(node[o].laz,query(node[o].rch,mid + 1,r,p));
}

void dfs(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
	{
		dfs(edge[i].to);
		rt[u] = merge(rt[u],rt[edge[i].to],1,MX);
	}
	if (d[u])
	{
		ll newval = query(rt[u],1,MX,d[u]) + w[u];
		rt[u] = modify(rt[u],1,MX,d[u],newval);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&MX);
	for (int fa,i = 2;i <= n;i++)
	{
		scanf("%d",&fa);
		addE(fa,i);
	}
	id = 0;
	for (int u,i = 1;i <= m;i++)
	{
		scanf("%d",&u);
		scanf("%d%d",&d[u],&w[u]);
	}
	dfs(1);
	printf("%lld\n",query(rt[1],1,MX,MX));
	return 0;
}