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
#include <assert.h>

using namespace std;

const int MAXN = 500005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,q,id,key,far;
int u[MAXN];
int v[MAXN];
int c[MAXN];
int t[MAXN];
int first[MAXN];
int dfn[MAXN];
int R[MAXN];
int fa[MAXN];
int nod[MAXN];
int ans[MAXN];
int depth[MAXN];
int MAX[MAXN << 2][2];

bool rev[MAXN << 2];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int f,int d)
{
	if (d > far)
	{
		far = d;
		key = u;
	}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != f)
			dfs(edge[i].to,u,d + 1);
}

void getinfo(int u)
{
	nod[dfn[u] = ++id] = u;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			depth[edge[i].to] = depth[u] + 1;
			getinfo(edge[i].to);
		}
	R[u] = id;
}

void merge(int o)
{
	MAX[o][0] = max(MAX[o << 1][0],MAX[o << 1 | 1][0]);
	MAX[o][1] = max(MAX[o << 1][1],MAX[o << 1 | 1][1]);
}

void buildtree(int o,int l,int r)
{
	rev[o] = MAX[o][0] = MAX[o][1] = 0;
	if (l == r)
	{
		MAX[o][0] = depth[nod[l]];
		return;
	}
	int mid = l + r >> 1;
	buildtree(o << 1,l,mid);
	buildtree(o << 1 | 1,mid + 1,r);
	merge(o);
}

void Rev(int o)
{
	rev[o] ^= 1;
	swap(MAX[o][0],MAX[o][1]);
}

void pushdown(int o)
{
	if (rev[o])
	{
		Rev(o << 1);
		Rev(o << 1 | 1);
		rev[o] = 0;
	}
}

void modify(int o,int l,int r,int x,int y)
{
	if (l >= x && r <= y)
	{
		Rev(o);
		return;
	}
	pushdown(o);
	int mid = l + r >> 1;
	if (mid >= x)
		modify(o << 1,l,mid,x,y);
	if (mid + 1 <= y)
		modify(o << 1 | 1,mid + 1,r,x,y);
	merge(o);
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&c[i]);
		addE(u[i],v[i]);
		addE(v[i],u[i]);
	}
	scanf("%d",&q);
	for (int i = 1;i <= q;i++)
		scanf("%d",&t[i]);
	far = -1;
	dfs(1,0,0);
	id = 0;
	getinfo(key);
	buildtree(1,1,n);
	for (int i = 1;i < n;i++)
		if (c[i])
		{
			if (u[i] == fa[v[i]])
				modify(1,1,n,dfn[v[i]],R[v[i]]);
			else
				modify(1,1,n,dfn[u[i]],R[u[i]]);
		}
	for (int i = 1;i <= q;i++)
	{
		int p = t[i];
		if (u[p] == fa[v[p]])
			modify(1,1,n,dfn[v[p]],R[v[p]]);
		else
			modify(1,1,n,dfn[u[p]],R[u[p]]);
		ans[i] = max(ans[i],MAX[1][0]);
	}
	far = -1;
	dfs(key,0,0);
	id = 0;
	fa[key] = depth[key] = 0;
	getinfo(key);
	buildtree(1,1,n);
	for (int i = 1;i < n;i++)
		if (c[i])
		{
			if (u[i] == fa[v[i]])
				modify(1,1,n,dfn[v[i]],R[v[i]]);
			else
				modify(1,1,n,dfn[u[i]],R[u[i]]);
		}
	for (int i = 1;i <= q;i++)
	{
		int p = t[i];
		if (u[p] == fa[v[p]])
			modify(1,1,n,dfn[v[p]],R[v[p]]);
		else
			modify(1,1,n,dfn[u[p]],R[u[p]]);
		ans[i] = max(ans[i],MAX[1][0]);
	}
	for (int i = 1;i <= q;i++)
		printf("%d\n",ans[i]);
	return 0;
}