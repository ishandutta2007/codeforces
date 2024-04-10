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
const ll MOD = 1000000007;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,K,X,id;
int first[MAXN];

ll ans;
ll g[15];
ll f[MAXN][15][3];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
			dfs(edge[i].to,u);
	f[u][0][0] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			memset(g,0,sizeof(g));
			for (int j = 0;j <= X;j++)
				for (int k = 0;j + k <= X;k++)
					(g[j + k] += (f[edge[i].to][j][0] * m + f[edge[i].to][j][1] * K) % MOD * f[u][k][0]) %= MOD;
			for (int j = 0;j <= X;j++)
				f[u][j][0] = g[j];
		}
	f[u][0][1] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			memset(g,0,sizeof(g));
			for (int j = 0;j <= X;j++)
				for (int k = 0;j + k <= X;k++)
					(g[j + k] += (f[edge[i].to][j][0] * m + f[edge[i].to][j][1] * K + f[edge[i].to][j][2]) % MOD * f[u][k][1]) %= MOD;
			for (int j = 0;j <= X;j++)
				f[u][j][1] = g[j];
		}
	for (int i = 0;i <= X;i++)
		(f[u][i][1] -= f[u][i][0]) %= MOD;
	f[u][1][2] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			memset(g,0,sizeof(g));
			for (int j = 0;j <= X;j++)
				for (int k = 0;j + k <= X;k++)
					(g[j + k] += (f[edge[i].to][j][0] * K + f[edge[i].to][j][1] * K) % MOD * f[u][k][2]) %= MOD;
			for (int j = 0;j <= X;j++)
				f[u][j][2] = g[j];
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	m--;
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	scanf("%d%d",&K,&X);
	K--;
	dfs(1,0);
	for (int i = 0;i <= X;i++)
		(ans += f[1][i][0] * m + f[1][i][1] * K + f[1][i][2]) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}