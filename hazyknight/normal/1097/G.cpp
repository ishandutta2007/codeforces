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

typedef long long ll;

const int MAXN = 100005;
const int MAXK = 205;
const ll MOD = 1000000007;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,m,id;
int size[MAXN];
int first[MAXN];

ll ans;
ll cnt[MAXK];
ll s[MAXK][MAXK];
ll g[MAXN][MAXK];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int now,int fa)
{
	g[now][0] = 2;
	for (int i = first[now];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,now);
			for (int j = min(m,size[now] + size[edge[i].to] + 1);j >= 0;j--)
			{
				ll sum = 0;
				for (int k = max(0,j - size[now] - 1);k <= min(min(m,j),size[edge[i].to]);k++)
				{
					(sum += g[now][j - k] * g[edge[i].to][k]) %= MOD;
					if (j != k)
						(sum += g[now][j - k - 1] * (g[edge[i].to][k] - (k == 0))) %= MOD;
				}
				g[now][j] = sum;
			}
			size[now] += size[edge[i].to] + 1;
		}
	for (int i = 1;i <= min(m,size[now]);i++)
		(cnt[i] += g[now][i]) %= MOD;
	for (int i = 1;i <= min(m,size[now]);i++)
		for (int j = first[now];j;j = edge[j].nxt)
			if (edge[j].to != fa)
				(cnt[i] -= g[edge[j].to][i - 1] - (i == 1) + g[edge[j].to][i]) %= MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	s[1][1] = 1;
	for (int i = 2;i <= m;i++)
		for (int j = 1;j <= i;j++)
			s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % MOD;
	ll fac = 1;
	for (int i = 1;i <= m;i++)
	{
		(fac *= i) %= MOD;
		(ans += cnt[i] * fac % MOD * s[m][i]) %= MOD;
	}
	cout << (ans + MOD) % MOD << endl;
	return 0;
}