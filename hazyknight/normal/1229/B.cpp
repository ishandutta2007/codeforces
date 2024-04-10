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

int n,id;
int first[MAXN];

ll ans;
ll v[MAXN];

map<ll,int> cnt[MAXN];

ll gcd(ll a,ll b)
{
	return b ? gcd(b,a % b) : a;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int u,ll x,int v)
{
	cnt[u][x] += v;
	(ans += x * v) %= MOD;
}

void dfs(int u,int fa)
{
	add(u,v[u],1);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			for (map<ll,int>::iterator j = cnt[u].begin();j != cnt[u].end();j++)
				add(edge[i].to,gcd(v[edge[i].to],j->first),j->second);
			dfs(edge[i].to,u);
		}
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%lld",&v[i]);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}