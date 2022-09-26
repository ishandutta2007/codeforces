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

const int MAXN = 300005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,q,id,x,y,tp;
int fa[MAXN];
int ans[MAXN];
int first[MAXN];
int depth[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

void dfs(int u,int bel)
{
	fa[u] = bel;
	int MAX = 0,MAX2 = 0;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (fa[edge[i].to])
			continue;
		dfs(edge[i].to,bel);
		if (depth[edge[i].to] + 1 >= MAX)
		{
			MAX2 = MAX;
			MAX = depth[edge[i].to] + 1;
		}
		else if (depth[edge[i].to] + 1 > MAX2)
			MAX2 = depth[edge[i].to] + 1;
	}
	depth[u] = MAX;
	ans[bel] = max(ans[bel],MAX + MAX2);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		if (!fa[i])
			dfs(i,i);
	while (q--)
	{
		scanf("%d",&tp);
		if (tp == 1)
		{
			scanf("%d",&x);
			printf("%d\n",ans[getroot(x)]);
		}
		else
		{
			scanf("%d%d",&x,&y);
			x = getroot(x);
			y = getroot(y);
			if (x == y)
				continue;
			ans[x] = max(ans[x],(ans[x] + 1) / 2 + (ans[y] + 1) / 2 + 1);
			ans[x] = max(ans[x],ans[y]);
			fa[y] = x;
		}
	}
	return 0;
}