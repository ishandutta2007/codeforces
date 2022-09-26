#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int n,m,q,id,tot;
int first[MAXN];
int p[MAXN];
int pre[MAXN];
int a[MAXN];
int rb[MAXN];
int lst[MAXN];
int L[MAXN];
int R[MAXN];
int MAX[MAXN << 2];
int laz[MAXN << 2];

bool vis[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	vis[u] = 1;
	L[u] = tot + 1;
	if (!first[u])
		tot++;
	for (int i = first[u];i;i = edge[i].nxt)
		dfs(edge[i].to);
	R[u] = tot;
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

void modify(int o,int l,int r,int x,int y,int v)
{
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

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= n;i++)
		scanf("%d",&p[i]);
	pre[p[1]] = p[n];
	for (int i = 2;i <= n;i++)
		pre[p[i]] = p[i - 1];
	for (int i = 1;i <= m;i++)
		scanf("%d",&a[i]);
	for (int i = 1;i <= m;i++)
	{
		if (lst[pre[a[i]]])
			addE(lst[pre[a[i]]],i);
		lst[a[i]] = i;
	}
	for (int i = 1;i <= m;i++)
		if (!vis[i])
			dfs(i);
	for (int i = 1,j = 0;i <= m;i++)
	{
		while (MAX[1] < n && j + 1 <= m)
		{
			j++;
			modify(1,1,tot,L[j],R[j],1);
		}
		if (MAX[1] < n)
			rb[i] = m + 1;
		else
			rb[i] = j;
		modify(1,1,tot,L[i],R[i],-1);
	}
	for (int l,r,i = 1;i <= q;i++)
	{
		scanf("%d%d",&l,&r);
		if (r >= rb[l])
			putchar('1');
		else
			putchar('0');
	}
	puts("");
	return 0;
}