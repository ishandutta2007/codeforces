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
	int t;
	
	bool operator < (const Edge &p)const
	{
		return t < p.t;
	}
};

int n;

ll f[MAXN][4];
ll pre[MAXN];
ll suf[MAXN];

vector<Edge> e[MAXN];

void addE(int u,int v,int t)
{
	e[u].push_back((Edge){v,t});
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

void dfs(int u,int fa,int t)
{
	int sz = e[u].size(),pos = 0;
	for (int i = 1;i < sz;i++)
		if (e[u][i].to == fa)
		{
			pos = i;
			sz--;
			e[u].erase(e[u].begin() + i);
			break;
		}
	for (int i = 1;i < sz;i++)
		dfs(e[u][i].to,u,e[u][i].t);
	pre[0] = 1;
	for (int i = 1;i < sz;i++)
		pre[i] = pre[i - 1] * (f[e[u][i].to][0] + f[e[u][i].to][1]) % MOD;
	suf[sz] = 1;
	for (int i = sz - 1;i >= 1;i--)
		suf[i] = suf[i + 1] * (f[e[u][i].to][0] + f[e[u][i].to][2] + f[e[u][i].to][3]) % MOD;
	f[u][3] = 1;
	for (int i = 1;i < sz;i++)
		(f[u][3] *= f[e[u][i].to][0] + f[e[u][i].to][1]) %= MOD;
	for (int i = 1;i < sz;i++)
		(f[u][(e[u][i].t > t) * 2] += pre[i - 1] * (f[e[u][i].to][2] + f[e[u][i].to][3]) % MOD * suf[i + 1]) %= MOD;
	if (pos)
		(f[u][1] += pre[pos - 1] * suf[pos]) %= MOD;
}
 
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		e[i].push_back((Edge){0,0});
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v,i);
		addE(v,u,i);
	}
	for (int i = 1;i <= n;i++)
		sort(e[i].begin(),e[i].end());
	dfs(1,0,0);
	printf("%lld\n",(f[1][2] + f[1][3]) % MOD);
	return 0;
}