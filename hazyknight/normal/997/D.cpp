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

const int MAXN = 4005;
const int MAXK = 80;
const int INF = (1 << 30) - 1;
const ll MOD = 998244353;

int N;

ll ans;
ll C[MAXK][MAXK];

struct Tree
{
	struct Edge
	{
		int to;
		int nxt;
	}edge[MAXN << 1];
	
	int n,id,G,SIZE;
	int first[MAXN];
	int size[MAXN];
	int MAX[MAXN];
	
	ll ans[MAXK];
	ll f[MAXN][MAXK];
	ll g[MAXN][MAXK];
	
	bool mark[MAXN];
	
	void addE(int u,int v)
	{
		edge[++id] = (Edge){v,first[u]};
		first[u] = id;
	}
	
	void ReadEdge()
	{
		for (int u,v,i = 1;i < n;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
			addE(v,u);
		}
	}
	
	void getsize(int u,int fa)
	{
		size[u] = 1;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to] && edge[i].to != fa)
			{
				getsize(edge[i].to,u);
				size[u] += size[edge[i].to];
			}
	}
	
	void getG(int u,int fa)
	{
		size[u] = 1;
		MAX[u] = 0;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to] && edge[i].to != fa)
			{
				getG(edge[i].to,u);
				size[u] += size[edge[i].to];
				MAX[u] = max(MAX[u],size[edge[i].to]);
			}
		MAX[u] = max(MAX[u],SIZE - size[u]);
		if (MAX[u] < MAX[G])
			G = u;
	}
	
	void dfs(int u,int fa,int j)
	{
		f[u][j] = g[u][j] = 0;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to])
				(f[u][j] += f[edge[i].to][j - 1]) %= MOD;
		if (fa)
		{
			for (int i = first[u];i;i = edge[i].nxt)
				if (!mark[edge[i].to])
					(g[u][j] += g[edge[i].to][j - 1]) %= MOD;
		}
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to] && edge[i].to != fa)
				dfs(edge[i].to,u,j);
	}
	
	void summary(int u,int fa)
	{
		int tmp = ans[N];
		for (int i = 0;i <= N;i++)
			if (g[u][i])
				for (int j = 0;i + j <= N;j++)
					if (f[u][j])
						(ans[i + j] += g[u][i] * f[u][j]) %= MOD;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to] && edge[i].to != fa)
				summary(edge[i].to,u);
	}
	
	void work(int u)
	{
		f[u][0] = g[u][0] = 1;
		for (int i = 1;i <= N;i++)
			dfs(u,0,i);
		summary(u,0);
	}
	
	void solve(int u)
	{
		work(u);
		getsize(u,0);
		mark[u] = 1;
		for (int i = first[u];i;i = edge[i].nxt)
			if (!mark[edge[i].to])
			{
				SIZE = size[edge[i].to];
				G = 0;
				getG(edge[i].to,u);
				solve(G);
			}
	}
	
	void calc()
	{
		MAX[G = 0] = INF;
		SIZE = n;
		getG(1,0);
		solve(G);
	}
}T[2];

int main()
{
	scanf("%d%d%d",&T[0].n,&T[1].n,&N);
	T[0].ReadEdge();
	T[1].ReadEdge();
	T[0].calc();
	T[1].calc();
	C[0][0] = 1;
	for (int i = 1;i <= N;i++)
	{
		C[i][0] = 1;
		for (int j = 1;j <= i;j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	for (int i = 0;i <= N;i++)
		(ans += T[0].ans[i] * T[1].ans[N - i] % MOD * C[N][i]) %= MOD;
	printf("%lld\n",ans);
	return 0;
}