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

struct Edge
{
	int to;
	int w;
	int nxt;
}edge[MAXN << 1];

int n,id,SIZE,G;
int first[MAXN];
int size[MAXN];
int MAX[MAXN];

ll MOD,ans;
ll pw[MAXN];
ll inv[MAXN];

bool mark[MAXN];

map<ll,int> cnt;

void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return;
	}
	exgcd(b,a % b,y,x);
	y -= a / b * x;
}

ll getinv(ll a)
{
	ll x,y;
	exgcd(a,MOD,x,y);
	return (x % MOD + MOD) % MOD;
}

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void getroot(int u,int fa)
{
	size[u] = 1;
	MAX[u] = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getroot(edge[i].to,u);
			size[u] += size[edge[i].to];
			MAX[u] = max(MAX[u],size[edge[i].to]);
		}
	MAX[u] = max(MAX[u],SIZE - size[u]);
	if (MAX[u] < MAX[G])
		G = u;
}

void getsize(int u,int fa)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getsize(edge[i].to,u);
			size[u] += size[edge[i].to];
		}
}

void dfsdn(int u,int fa,int dp,ll v)
{
	cnt[v]++;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
			dfsdn(edge[i].to,u,dp + 1,(v + edge[i].w * pw[dp]) % MOD);
}

void dfsup(int u,int fa,int dp,ll v,int val)
{
	ans += val * cnt[(MOD - v) * inv[dp] % MOD];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
			dfsup(edge[i].to,u,dp + 1,(v * 10 + edge[i].w) % MOD,val);
}

void calc(int u)
{
	cnt.clear();
	dfsdn(u,0,0,0);
	dfsup(u,0,0,0,1);
	ans--;
	for (int i = first[u];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			cnt.clear();
			dfsdn(edge[i].to,u,1,edge[i].w % MOD);
			dfsup(edge[i].to,u,1,edge[i].w % MOD,-1);
		}
}

void solve(int u)
{
	calc(u);
	mark[u] = 1;
	getsize(u,0);
	for (int i = first[u];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			SIZE = size[edge[i].to];
			G = 0;
			getroot(edge[i].to,u);
			solve(G);
		}
}

int main()
{
	scanf("%d%lld",&n,&MOD);
	pw[0] = inv[0] = 1;
	for (int i = 1;i <= n;i++)
	{
		pw[i] = pw[i - 1] * 10 % MOD;
		inv[i] = getinv(pw[i]);
	}
	for (int u,v,w,i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		u++,v++;
		addE(u,v,w);
		addE(v,u,w);
	}
	SIZE = n;
	MAX[G = 0] = n;
	getroot(1,0);
	solve(G);
	printf("%lld\n",ans);
	return 0;
}