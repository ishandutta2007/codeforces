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

const int MAXN = 1000005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int T,n,m,id,cc;
int first[MAXN];
int dfn[MAXN];
int low[MAXN];
int u[MAXN];
int v[MAXN];
int bel[MAXN];
int deg[MAXN];

bool vis[MAXN];

stack<int> S;
vector<int> a,b;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++id;
	vis[u] = 1;
	S.push(u);
	for (int i = first[u];i;i = edge[i].nxt)
	{
		if (!dfn[edge[i].to])
		{
			dfs(edge[i].to);
			low[u] = min(low[u],low[edge[i].to]);
		}
		else if (vis[edge[i].to])
			low[u] = min(low[u],dfn[edge[i].to]);
	}
	if (dfn[u] == low[u])
	{
		++cc;
		while (S.top() != u)
		{
			vis[S.top()] = 0;
			bel[S.top()] = cc;
			S.pop();
		}
		vis[u] = 0;
		bel[u] = cc;
		S.pop();
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		id = 0;
		for (int i = 1;i <= n;i++)
			first[i] = dfn[i] = deg[i] = 0;
		for (int i = 1;i <= m;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			addE(u[i],v[i]);
		}
		cc = id = 0;
		for (int i = 1;i <= n;i++)
			if (!dfn[i])
				dfs(i);
		if (cc == 1)
		{
			puts("No");
			continue;
		}
		for (int i = 1;i <= m;i++)
			if (bel[u[i]] != bel[v[i]])
				deg[bel[u[i]]]++;
		a.clear();
		b.clear();
		for (int i = 1;i <= cc;i++)
			if (!deg[i])
			{
				puts("Yes");
				for (int j = 1;j <= n;j++)
					if (bel[j] != i)
						a.push_back(j);
					else
						b.push_back(j);
				printf("%d %d\n",(int)b.size(),(int)a.size());
				for (int j = 0;j < b.size();j++)
					printf("%d ",b[j]);
				printf("\n");
				for (int j = 0;j < a.size();j++)
					printf("%d ",a[j]);
				printf("\n");
				break;
			}
	}
	return 0;
}