#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,k,id;
int first[MAXN];

bool vis[MAXN];

vector<int> path;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	vis[u] = 1;
	path.push_back(u);
	for (int i = first[u];i;i = edge[i].nxt)
		if (!vis[edge[i].to])
		{
			dfs(edge[i].to);
			path.push_back(u);
		}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int u,v,i = 1;i <= m;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1);
	for (int i = 1;i <= k;i++)
	{
		int c = min((int)path.size(),(2 * n + k - 1) / k);
		if (c == 0)
		{
			printf("1 1\n");
			continue;
		}
		printf("%d ",c);
		for (int j = 1;j <= c;j++)
		{
			printf("%d ",path.back());
			path.pop_back();
		}
		puts("");
	}
	return 0;
}