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

const int MAXN = 100005;

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN << 1];

struct Node
{
	int lch,rch;
	int size;
	
	void clear()
	{
		lch = rch = 0;
		size = 1;
	}
}node[MAXN];

int n,q,id,ans;
int first[MAXN];

ll L;
ll f[MAXN];
ll g[MAXN];

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

int merge(int u,int v)
{
	if (!u || !v)
		return u | v;
	if (f[u] < f[v])
		swap(u,v);
	node[u].rch = merge(node[u].rch,v);
	if (node[node[u].rch].size > node[node[u].lch].size)
		swap(node[u].lch,node[u].rch);
	node[u].size = node[node[u].lch].size + node[node[u].rch].size + 1;
	return u;
}

void dfs1(int u,int fa)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs1(edge[i].to,u);
			f[u] = max(f[u],f[edge[i].to] + edge[i].w);
		}
}

void dfs2(int u,int fa)
{
	stack<int> S;
	ll MAX = g[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			g[edge[i].to] = MAX + edge[i].w;
			MAX = max(MAX,f[edge[i].to] + edge[i].w);
			S.push(i);
		}
	MAX = 0;
	while (!S.empty())
	{
		int i = S.top();
		S.pop();
		g[edge[i].to] = max(g[edge[i].to],MAX + edge[i].w);
		MAX = max(MAX,f[edge[i].to] + edge[i].w);
		dfs2(edge[i].to,u);
	}
	f[u] = max(f[u],g[u]);
}

int dfs(int u,int fa,ll L)
{
	int cur = u;
	node[cur].clear();
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			cur = merge(cur,dfs(edge[i].to,u,L));
	while (cur && f[cur] - f[u] > L)
		cur = merge(node[cur].lch,node[cur].rch);
	ans = max(ans,node[cur].size);
	return cur;
}

int main()
{
	scanf("%d",&n);
	for (int u,v,w,i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addE(u,v,w);
		addE(v,u,w);
	}
	dfs1(1,0);
	dfs2(1,0);
	int rt = 1;
	for (int i = 2;i <= n;i++)
		if (f[i] <= f[rt])
			rt = i;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%lld",&L);
		ans = 0;
		dfs(rt,0,L);
		printf("%d\n",ans);
	}
	return 0;
}