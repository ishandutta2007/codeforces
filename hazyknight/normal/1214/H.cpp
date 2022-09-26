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

int n,m,id;
int first[MAXN];
int f[MAXN];
int g[MAXN];
int ans[MAXN];

vector<int> d;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u,int fa)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs1(edge[i].to,u);
			f[u] = max(f[u],f[edge[i].to]);
		}
	f[u]++;
}

void dfs2(int u,int fa)
{
	g[u]++;
	int MAX = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && f[edge[i].to] > f[MAX])
			MAX = edge[i].to;
	int MX = g[u];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && edge[i].to != MAX)
		{
			g[edge[i].to] = max(g[u],f[MAX] + 1);
			MX = max(MX,f[edge[i].to] + 1);
		}
	g[MAX] = MX;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			dfs2(edge[i].to,u);
}

pair<int,int> dfs(int u,int fa)
{
	pair<int,int> res = make_pair(0,u);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			pair<int,int> ret = dfs(edge[i].to,u);
			if (ret.first > res.first)
				res = ret;
		}
	res.first++;
	return res;
}

bool get(int u,int T,int fa)
{
	if (u == T)
	{
		d.push_back(u);
		return 1;
	}
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && get(edge[i].to,T,u))
		{
			d.push_back(u);
			return 1;
		}
	return 0;
}

void fill(int u,int v,int dv)
{
	if (ans[u])
		return;
	if (!v)
		v = m;
	if (v == m + 1)
		v = 1;
	ans[u] = v;
	for (int i = first[u];i;i = edge[i].nxt)
		fill(edge[i].to,v + dv,dv);
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
	dfs1(1,0);
	dfs2(1,0);
	for (int i = 1;i <= n;i++)
	{
		int MAX1 = 0,MAX2 = 0,MAX3 = 0;
		for (int j = first[i];j;j = edge[j].nxt)
		{
			int dep = f[edge[j].to] > f[i] ? g[i] - 1 : f[edge[j].to];
			if (dep >= MAX1)
			{
				MAX3 = MAX2;
				MAX2 = MAX1;
				MAX1 = dep;
			}
			else if (dep >= MAX2)
			{
				MAX3 = MAX2;
				MAX2 = dep;
			}
			else if (dep > MAX3)
				MAX3 = dep;
		}
		if (MAX3 && MAX2 + MAX3 + 1 >= m && m > 2)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	int key = dfs(1,0).second,nxt = dfs(key,0).second;
	get(key,nxt,0);
	int t = 0;
	for (int i = 0;i < d.size();i++)
	{
		t= t % m + 1;
		ans[d[i]] = t;
	}
	for (int i = 0;i < d.size();i++)
		for (int j = first[d[i]];j;j = edge[j].nxt)
		{
			if (i >= d.size() - i)
				fill(edge[j].to,ans[d[i]] + 1,1);
			else
				fill(edge[j].to,ans[d[i]] - 1,-1);
		}
	for (int i = 1;i <= n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}