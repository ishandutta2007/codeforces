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
const ll MOD = 1000000007;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN];

int n,D,id;
int first[MAXN];

ll ans;
ll f[MAXN][MAXN];
ll C[MAXN][MAXN];
ll sum[MAXN][MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	for (int i = 1;i <= n;i++)
		f[u][i] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
	{
		dfs(edge[i].to);
		for (int j = 1;j <= n;j++)
			(f[u][j] *= sum[edge[i].to][j]) %= MOD;
	}
	for (int i = 1;i <= n;i++)
		sum[u][i] = (sum[u][i - 1] + f[u][i]) % MOD;
}

ll power(ll a,ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
			(res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

ll bigC(ll x,ll y)
{
	if (x < y)
		return 0;
	ll res = 1;
	for (ll i = 1;i <= y;i++)
		(res *= i) %= MOD;
	res = power(res,MOD - 2);
	for (ll i = x;i >= x - y + 1;i--)
		(res *= i) %= MOD;
	return res;
}

int main()
{
	scanf("%d%d",&n,&D);
	for (int p,i = 1;i < n;i++)
	{
		scanf("%d",&p);
		addE(p,i + 1);
	}
	dfs(1);
	C[0][0] = 1;
	for (int i = 1;i <= n;i++)
	{
		C[i][0] = 1;
		for (int j = 1;j <= i;j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < i;j++)
			(f[1][i] -= f[1][j] * C[i - 1][j - 1]) %= MOD;
	for (int i = 1;i <= n;i++)
		(ans += bigC(D,i) * f[1][i]) %= MOD;
	printf("%lld\n",(ans + MOD) % MOD);
	return 0;
}