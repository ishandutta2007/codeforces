#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
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

const int MAXN = 1005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id,tot;
int fa[MAXN];
int dfn[MAXN];
int size[MAXN];
int first[MAXN];

bool f[MAXN][MAXN];

pair<int,int> sz[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void getsize(int u,int faa)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != faa)
		{
			getsize(edge[i].to,u);
			size[u] += size[edge[i].to];
		}
}

void dfs(int u,int &ID,int inc)
{
	ID += inc;
	dfn[u] = ID;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			dfs(edge[i].to,ID,inc);
		}
}

void solve(int u)
{
	tot = 0;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (size[edge[i].to] < size[u])
			sz[++tot] = make_pair(size[edge[i].to],edge[i].to);
		else
			sz[++tot] = make_pair(n - size[u],edge[i].to);
	}
	for (int i = 0;i <= tot;i++)
	{
		f[i][0] = 1;
		for (int j = 1;j <= n;j++)
			f[i][j] = 0;
	}
	for (int i = 1;i <= tot;i++)
		for (int j = 1;j <= n;j++)
		{
			f[i][j] = f[i - 1][j];
			if (j >= sz[i].first)
				f[i][j] |= f[i - 1][j - sz[i].first];
		}
	int pos = -1;
	for (int j = 0;j <= n;j++)
		if (f[tot][j] && (j + 1) * (n - j) - 1 >= 2 * n * n / 9)
		{
			pos = j;
			break;
		}
	if (pos == -1)
		return;
	int id1 = 0,id2 = 0,t = pos + 1;
	for (int i = tot;i >= 1;i--)
	{
		fa[sz[i].second] = u;
		if (f[i - 1][pos])
			dfs(sz[i].second,id2,t);
		else
		{
			dfs(sz[i].second,id1,1);
			pos -= sz[i].first;
		}
	}
	for (int i = 1;i <= n;i++)
		if (i != u)
			printf("%d %d %d\n",fa[i],i,dfn[i] - dfn[fa[i]]);
	exit(0);
}

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	getsize(1,0);
	for (int i = 1;i <= n;i++)
		solve(i);
	assert(0);
	return 0;
}