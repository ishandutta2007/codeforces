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

const int MAXN = 200005;
const ll MOD = 998244353;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

int n,id;
int first[MAXN];

ll f[MAXN];
ll fac[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void init()
{
	fac[0] = 1;
	for (int i = 1;i <= n;i++)
		fac[i] = fac[i - 1] * i % MOD;
}

void dfs(int u,int fa)
{
	f[u] = 1;
	int deg = (u != 1);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			(f[u] *= f[edge[i].to]) %= MOD;
			deg++;
		}
	(f[u] *= fac[deg]) %= MOD;
}

int main()
{
	scanf("%d",&n);
	init();
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	printf("%lld\n",f[1] * n % MOD);
	return 0;
}