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

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,d,id,cc,ans;
int dfn[MAXN];
int L[MAXN];
int R[MAXN];
int val[MAXN];
int depth[MAXN];
int first[MAXN];
int MAX[MAXN << 2];
int laz[MAXN << 2];

bool vis[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int o,int v)
{
	MAX[o] += v;
	laz[o] += v;
}

void pushdown(int o)
{
	if (laz[o])
	{
		add(o << 1,laz[o]);
		add(o << 1 | 1,laz[o]);
		laz[o] = 0;
	}
}

void buildtree(int o,int l,int r)
{
	if (l == r)
	{
		MAX[o] = val[l];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	MAX[o] = max(MAX[o << 1],MAX[o << 1 | 1]);
}

void modify(int o,int l,int r,int x,int y,int v)
{
	if (x > y)
		return;
	if (l >= x && r <= y)
	{
		add(o,v);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y,v);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y,v);
	MAX[o] = max(MAX[o << 1],MAX[o << 1 | 1]);
}

int query(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
		return MAX[o];
	pushdown(o);
	int mid = l + r >> 1;
	if (mid < x)
		return query(o << 1 | 1,mid + 1,r,x,y);
	if (mid + 1 > y)
		return query(o << 1,l,mid,x,y);
	return min(query(o << 1,l,mid,x,y),query(o << 1 | 1,mid + 1,r,x,y));
}

void dfs1(int u,int fa)
{
	L[u] = cc + 1;
	if (vis[u])
		val[dfn[u] = ++cc] = depth[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			depth[edge[i].to] = depth[u] + 1;
			dfs1(edge[i].to,u);
		}
	R[u] = cc;
}

void dfs2(int u,int fa)
{
	if (query(1,1,m,1,m) <= d)
		ans++;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			modify(1,1,m,L[edge[i].to],R[edge[i].to],-2);
			modify(1,1,m,1,m,1);
			dfs2(edge[i].to,u);
			modify(1,1,m,L[edge[i].to],R[edge[i].to],2);
			modify(1,1,m,1,m,-1);
		}
}

int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for (int u,i = 1;i <= m;i++)
	{
		scanf("%d",&u);
		vis[u] = 1;
	}
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs1(1,0);
	buildtree(1,1,m);
	dfs2(1,0);
	printf("%d\n",ans);
	return 0;
}