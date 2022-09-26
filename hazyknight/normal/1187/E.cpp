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

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id;
int fa[MAXN];
int size[MAXN];
int first[MAXN];

ll ans;
ll f[MAXN];
ll g[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs1(int u)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			dfs1(edge[i].to);
			size[u] += size[edge[i].to];
			f[u] += f[edge[i].to];
		}
	f[u] += size[u];
}

void dfs2(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			g[edge[i].to] = f[u] - size[u] - f[edge[i].to] + g[u] + n - size[edge[i].to];
			dfs2(edge[i].to);
		}
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
	dfs1(1);
	dfs2(1);
	for (int i = 1;i <= n;i++)
	{
		ll cur = n + g[i];
		for (int j = first[i];j;j = edge[j].nxt)
			if (edge[j].to != fa[i])
				cur += f[edge[j].to];
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}