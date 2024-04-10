#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 150005;
const ll MOD = 998244353;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,q,id,cc;
int first[MAXN];
int fa[MAXN];
int dfn[MAXN];
int R[MAXN];
int sz[MAXN];
int bel[MAXN];
int top[MAXN];
int hson[MAXN];

ll Inv;
ll tot[MAXN];
ll sum[MAXN];

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

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void modify(int p,ll v)
{
	while (p <= n)
	{
		(sum[p] += v) %= MOD;
		p += p & -p;
	}
}

ll query(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		(res += sum[p]) %= MOD;
		p -= p & -p;
	}
	return res;
}

void dfs(int u)
{
	dfn[u] = ++id;
	sz[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u])
		{
			fa[edge[i].to] = u;
			dfs(edge[i].to);
			sz[u] += sz[edge[i].to];
			if (sz[edge[i].to] > sz[hson[u]])
				hson[u] = edge[i].to;
		}
	if (!hson[u])
		top[bel[u] = ++cc] = u;
	else
		top[bel[u] = bel[hson[u]]] = u;
	R[u] = id;
}

int main()
{
	scanf("%d%d",&n,&q);
	Inv = power(n,MOD - 2);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	id = 0;
	dfs(1);
	for (int tp,u,d,i = 1;i <= q;i++)
	{
		scanf("%d",&tp);
		if (tp == 1)
		{
			scanf("%d%d",&u,&d);
			ll val = (ll)sz[u] * d % MOD;
			modify(1,val);
			modify(dfn[u],-val);
			modify(R[u] + 1,val);
			if (hson[u])
			{
				val = (ll)(n - sz[hson[u]]) * d % MOD;
				modify(dfn[hson[u]],val);
				modify(R[hson[u]] + 1,-val);
			}
			(tot[u] += d) %= MOD;
		}
		else
		{
			scanf("%d",&u);
			ll ans = (query(dfn[u]) + tot[u] * n) % MOD;
			while (u)
			{
				u = top[bel[u]];
				(ans += tot[fa[u]] * (n - sz[u])) %= MOD;
				u = fa[u];
			}
			printf("%lld\n",(ans * Inv % MOD + MOD) % MOD);
		}
	}
	return 0;
}