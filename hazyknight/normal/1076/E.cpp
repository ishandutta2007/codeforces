#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 300005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,id;
int first[MAXN];
int depth[MAXN];

ll sum[MAXN];
ll ans[MAXN];

vector<pair<int,int> > query[MAXN];

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void add(int p,int v)
{
	while (p <= n)
	{
		sum[p] += v;
		p += (p & -p);
	}
}

ll SUM(int p)
{
	ll res = 0;
	while (p >= 1)
	{
		res += sum[p];
		p -= (p & -p);
	}
	return res;
}

void dfs(int now,int fa)
{
	depth[now] = depth[fa] + 1;
	for (int i = 0;i < query[now].size();i++)
		add(min(n,depth[now] + query[now][i].first),query[now][i].second);
	ans[now] = SUM(n) - SUM(depth[now] - 1);
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
			dfs(edge[i].to,now);
	for (int i = 0;i < query[now].size();i++)
		add(min(n,depth[now] + query[now][i].first),-query[now][i].second);
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
	scanf("%d",&m);
	for (int v,d,x,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&v,&d,&x);
		query[v].push_back(make_pair(d,x));
	}
	dfs(1,0);
	for (int i = 1;i <= n;i++)
		printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}