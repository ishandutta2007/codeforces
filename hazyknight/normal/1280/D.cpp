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
const ll INF = 1ll << 60;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int T,n,m,id;
int first[MAXN];
int val[MAXN];
int b[MAXN];
int sz[MAXN];

pair<int,ll> g[MAXN];
pair<int,ll> f[MAXN][MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

pair<int,ll> operator + (const pair<int,ll> &a,const pair<int,ll> &b)
{
	return make_pair(a.first + b.first,a.second + b.second);
}

void dfs(int u,int fa)
{
	for (int i = 1;i < m;i++)
		f[u][i] = make_pair(0,-INF);
	f[u][0] = make_pair(0,0);
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs(v,u);
		for (int j = 0;j < sz[u];j++)
		{
			g[j] = f[u][j];
			f[u][j] = make_pair(0,-INF);
		}
		for (int j = 0;j < sz[u];j++)
			for (int k = 0;k < sz[v];k++)
			{
				f[u][j + k] = max(f[u][j + k],g[j] + f[v][k]);
				pair<int,ll> alter = f[v][k];
				alter.first += alter.second > 0;
				alter.second = 0;
				if (j + k + 1 < sz[u] + sz[v])
					f[u][j + k + 1] = max(f[u][j + k + 1],g[j] + alter);
			}
		sz[u] += sz[v];
	}
	for (int i = 0;i < sz[u];i++)
		f[u][i].second += val[u];
}
 
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i = 1;i <= n;i++)
			first[i] = 0;
		id = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d",&b[i]);
		for (int w,i = 1;i <= n;i++)
		{
			scanf("%d",&w);
			val[i] = w - b[i];
		}
		for (int u,v,i = 1;i < n;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
			addE(v,u);
		}
		dfs(1,0);
		printf("%d\n",f[1][m - 1].first + (f[1][m - 1].second > 0));
	}
	return 0;
}