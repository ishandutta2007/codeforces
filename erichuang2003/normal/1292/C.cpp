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

const int MAXN = 3005;

struct Edge
{
	int to;
	int id;
	int nxt;
}edge[MAXN << 1];

int n,id;
int first[MAXN];
int u[MAXN];
int v[MAXN];
int Dis[MAXN][MAXN];
int sz[MAXN][MAXN];

ll ans;
ll f[MAXN][MAXN];

vector<pair<int,int> > dis[MAXN];

void addE(int u,int v,int ID)
{
	edge[++id] = (Edge){v,ID,first[u]};
	first[u] = id;
}

void dfs(int u,int fa,int st,int d)
{
	if (d)
	{
		Dis[u][st] = Dis[st][u] = d;
		dis[d].push_back(make_pair(u,st));
	}
	sz[st][u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u,st,d + 1);
			sz[st][u] += sz[st][edge[i].to];
		}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i < n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		addE(u[i],v[i],i);
		addE(v[i],u[i],i);
	}
	for (int i = 1;i <= n;i++)
		dfs(i,0,i,0);
	for (int i = 0;i < dis[1].size();i++)
	{
		int u = dis[1][i].first,v = dis[1][i].second;
		f[u][v] = f[v][u] = sz[u][v] * sz[v][u];
		ans = max(ans,f[u][v]);
	}
	for (int i = 1;i <= n - 1;i++)
		for (int j = 0;j < dis[i].size();j++)
		{
			int u = dis[i][j].first,v = dis[i][j].second;
			ans = max(ans,f[u][v]);
			for (int k = first[u];k;k = edge[k].nxt)
				if (Dis[edge[k].to][v] > i)
					f[edge[k].to][v] = f[v][edge[k].to] = max(f[edge[k].to][v],f[u][v] + sz[v][edge[k].to] * sz[u][v]);
			for (int k = first[v];k;k = edge[k].nxt)
				if (Dis[edge[k].to][u] > i)
					f[u][edge[k].to] = f[edge[k].to][u] = max(f[u][edge[k].to],f[u][v] + sz[v][u] * sz[u][edge[k].to]);
		}
	printf("%lld\n",ans);
	return 0;
}