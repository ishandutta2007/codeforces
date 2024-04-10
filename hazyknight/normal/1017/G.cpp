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

const int MAXN = 100005;
const int INF = 1e9;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

struct Node
{
	int sum,maxl,laz;
}node[MAXN << 2];

int n,q,id,cc;
int v[MAXN];
int fa[MAXN];
int sz[MAXN];
int L[MAXN];
int top[MAXN];
int bel[MAXN];
int pos[MAXN];
int hson[MAXN];
int first[MAXN];
int len[MAXN << 2];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u)
{
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		dfs1(edge[i].to);
		sz[u] += sz[edge[i].to];
		if (sz[edge[i].to] > sz[hson[u]])
			hson[u] = edge[i].to;
	}
}

void dfs2(int u)
{
	L[u] = id + 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != hson[u])
			dfs2(edge[i].to);
	if (!hson[u])
		pos[top[bel[u] = ++cc] = u] = ++id;
	else
	{
		dfs2(hson[u]);
		pos[top[bel[u] = bel[hson[u]]] = u] = ++id;
	}
}

void setv(int o,int v)
{
	node[o].maxl = node[o].laz = v;
	node[o].sum = v * len[o];
}

Node merge(const Node &a,const Node &b)
{
	Node r;
	r.laz = INF;
	r.sum = a.sum + b.sum;
	r.maxl = max(a.maxl,a.sum + b.maxl);
	return r;
}

void pushdown(int o)
{
	if (node[o].laz != INF)
	{
		setv(o << 1,node[o].laz);
		setv(o << 1 | 1,node[o].laz);
		node[o].laz = INF;
	}
}

void buildtree(int o,int l,int r)
{
	len[o] = r - l + 1;
	node[o].laz = INF;
	if (l == r)
	{
		setv(o,-1);
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	node[o] = merge(node[o << 1],node[o << 1 | 1]);
}

void modify(int o,int l,int r,int x,int y,int v)
{
	if (l >= x && r <= y)
	{
		setv(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	node[o] = merge(node[o << 1],node[o << 1 | 1]);
}

Node query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return node[o];
	pushdown(o);
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return merge(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

Node jump(int u)
{
	return fa[top[bel[u]]] ? merge(query(1,1,n,pos[u],pos[top[bel[u]]]),jump(fa[top[bel[u]]])) : query(1,1,n,pos[u],pos[top[bel[u]]]);
}

int main()
{
	scanf("%d%d",&n,&q);
	for (int i = 2;i <= n;i++)
	{
		scanf("%d",&fa[i]);
		addE(fa[i],i);
	}
	id = 0;
	dfs1(1);
	dfs2(1);
	buildtree(1,1,n);
	while (q--)
	{
		int tp,u;
		scanf("%d%d",&tp,&u);
		if (tp == 1)
		{
			Node res = query(1,1,n,pos[u],pos[u]);
			modify(1,1,n,pos[u],pos[u],res.sum + 1);
		}
		if (tp == 2)
		{
			Node res = query(1,1,n,pos[u],pos[u]),res2 = jump(u);
			modify(1,1,n,L[u],pos[u],-1);
			modify(1,1,n,pos[u],pos[u],res2.maxl >= 0 ? res.sum - res2.maxl - 1 : res.sum);
		}
		if (tp == 3)
		{
			Node res = jump(u);
			puts(res.maxl >= 0 ? "black" : "white");
		}
	}
	return 0;
}