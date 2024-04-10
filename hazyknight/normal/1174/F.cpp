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

int n,id,dans;
int fa[MAXN];
int size[MAXN];
int hson[MAXN];
int first[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

int dis(int u)
{
	printf("d %d\n",u);
	fflush(stdout);
	int res = 0;
	scanf("%d",&res);
	return res;
}

int nxt(int u)
{
	printf("s %d\n",u);
	fflush(stdout);
	int res = 0;
	scanf("%d",&res);
	return res;
}

void answer(int u)
{
	printf("! %d\n",u);
	fflush(stdout);
	exit(0);
}

void dfs(int u)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			dfs(edge[i].to);
			size[u] += size[edge[i].to];
			if (size[edge[i].to] > size[hson[u]])
				hson[u] = edge[i].to;
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
	dans = dis(1);
	dfs(1);
	int cur = 1,dep = 0;
	while (1)
	{
		while (hson[cur])
		{
			cur = hson[cur];
			dep++;
		}
		int toans = dis(cur);
		if (toans + dans == dep)
		{
			while (toans)
			{
				cur = fa[cur];
				toans--;
			}
			answer(cur);
		}
		int lca = (dans + dep - toans) / 2;
		while (dep > lca)
		{
			cur = fa[cur];
			dep--;
		}
		cur = nxt(cur);
		dep++;
	}
	return 0;
}