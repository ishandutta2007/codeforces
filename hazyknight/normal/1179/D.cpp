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

const int MAXN = 500005;
const int INF = (1 << 30) - 1;
const ll INFL = (1ll << 60) - 1;

struct Edge
{
	int to;
	int sz;
	int nxt;
}edge[MAXN << 1];

int n,id = 1;
int G,SIZE,tot;
int first[MAXN];
int size[MAXN];
int MAX[MAXN];
int q[MAXN];

ll ans;
ll MN[MAXN];

bool vis[MAXN];
bool mark[MAXN];

ll C(ll v)
{
	return v * (v - 1) / 2;
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,0,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	size[u] = 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			dfs(edge[i].to,u);
			edge[i].sz = size[edge[i].to];
			edge[i ^ 1].sz = n - edge[i].sz;
			size[u] += size[edge[i].to];
		}
}

void getG(int u,int fa)
{
	size[u] = 1;
	MAX[u] = 0;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
		{
			getG(edge[i].to,u);
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

ll getpath(int u,int fa,ll all,ll sz)
{
	ll res = all + C(sz);
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa && !mark[edge[i].to])
			res = min(res,getpath(edge[i].to,u,all + C(sz - edge[i].sz),edge[i].sz));
	return res;
}

void calc(int u)
{
	for (int i = first[u];i;i = edge[i].nxt)
		if (!mark[edge[i].to])
		{
			ll res = getpath(edge[i].to,u,0,edge[i].sz);
			if (MN[edge[i].sz] != INFL)
				ans = min(ans,MN[edge[i].sz] + res + C(n - edge[i].sz * 2));
			MN[edge[i].sz] = min(MN[edge[i].sz],res);
			ans = min(ans,MN[edge[i].sz] + C(n - edge[i].sz));
			if (!vis[edge[i].sz])
			{
				vis[edge[i].sz] = 1;
				q[++tot] = edge[i].sz;
			}
		}
	for (int i = 1;i <= tot;i++)
		for (int j = i + 1;j <= tot;j++)
			ans = min(ans,MN[q[i]] + MN[q[j]] + C(n - q[i] - q[j]));
	for (int i = 1;i <= tot;i++)
	{
		vis[q[i]] = 0;
		MN[q[i]] = INFL;
	}
	tot = 0;
}

void solve(int u)
{
	calc(u);
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

int main()
{
	scanf("%d",&n);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	for (int i = 1;i <= n;i++)
		MN[i] = INFL;
	dfs(1,0);
	MAX[G = 0] = INF;
	ans = INFL;
	SIZE = n;
	getG(1,0);
	solve(G);
	printf("%lld\n",(ll)n * (n - 1) - ans);
	return 0;
}