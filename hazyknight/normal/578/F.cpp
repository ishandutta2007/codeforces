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

const int MAXN = 405;

int n,m,N;
int match[MAXN * MAXN];
int fa[MAXN * MAXN];

ll MOD;
ll a[MAXN][MAXN];

char s[MAXN][MAXN];

int id(int x,int y)
{
	return (x - 1) * (m + 1) + y;
}

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

bool link(int u,int v)
{
	if (getroot(u) == getroot(v))
		return 0;
	fa[getroot(u)] = getroot(v);
	return 1;
}

void addE(int u,int v)
{
	u = match[getroot(u)];
	v = match[getroot(v)];
	a[u][v]--;
	a[v][u]--;
	a[u][u]++;
	a[v][v]++;
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

ll Gauss()
{
	N--;
	for (int i = 1;i <= N;i++)
		for (int j = 1;j <= N;j++)
			a[i][j] %= MOD;
	ll res = 1;
	for (int i = 1;i <= N;i++)
	{
		if (!a[i][i])
		{
			for (int j = i + 1;j <= N;j++)
				if (a[j][i])
				{
					res *= -1;
					swap(a[i],a[j]);
					break;
				}
		}
		if (!a[i][i])
			return 0;
		ll Inv = power(a[i][i],MOD - 2);
		for (int j = i + 1;j <= N;j++)
		{
			if (!a[j][i])
				continue;
			ll v = Inv * a[j][i] % MOD;
			for (int k = i;k <= N;k++)
				(a[j][k] -= a[i][k] * v) %= MOD;
		}
	}
	for (int i = 1;i <= N;i++)
		(res *= a[i][i]) %= MOD;
	return res;
}

ll solve(bool op)
{
	N = 0;
	memset(a,0,sizeof(a));
	memset(match,0,sizeof(match));
	for (int i = 1;i <= n + 1;i++)
		for (int j = 1;j <= m + 1;j++)
			if (((i + j) & 1) == op)
				fa[id(i,j)] = id(i,j);
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			if (s[i][j] == '/' && ((i + j) & 1) != op && !link(id(i + 1,j),id(i,j + 1)))
				return 0;
			if (s[i][j] == '\\' && ((i + j) & 1) == op && !link(id(i,j),id(i + 1,j + 1)))
				return 0;
		}
	for (int i = 1;i <= n + 1;i++)
		for (int j = 1;j <= m + 1;j++)
		{
			if (match[getroot(id(i,j))] || ((i + j) & 1) != op)
				continue;
			match[getroot(id(i,j))] = ++N;
		}
	if (N > 401)
		return 0;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
			if (s[i][j] == '*')
			{
				if (((i + j) & 1) == op)
					addE(id(i,j),id(i + 1,j + 1));
				else
					addE(id(i + 1,j),id(i,j + 1));
			}
	return Gauss();
}

int main()
{
	scanf("%d%d%lld",&n,&m,&MOD);
	for (int i = 1;i <= n;i++)
		scanf("%s",s[i] + 1);
	printf("%lld\n",(solve(0) + solve(1) + MOD + MOD) % MOD);
	return 0;
}