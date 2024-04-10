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

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int to;
	int next;
	pair<ll,ll> sum;
}edge[MAXN << 1];

int n,id = 1;
int a[MAXN];
int first[MAXN];

ll ans;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u],make_pair(0,0)};
	first[u] = id;
}

pair<ll,ll> dfs1(int now,int fa)
{
	pair<ll,ll> res = make_pair(0,a[now]);
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			if (!edge[i].sum.first)
			{
				edge[i].sum = dfs1(edge[i].to,now);
				edge[i].sum.first += edge[i].sum.second;
			}
			res.first += edge[i].sum.first;
			res.second += edge[i].sum.second;
		}
	return res;
}

void dfs2(int now,int fa)
{
	pair<ll,ll> res = make_pair(0,a[now]);
	for (int i = first[now];i;i = edge[i].next)
	{
		res.first += edge[i].sum.first;
		res.second += edge[i].sum.second;
	}
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
		{
			res.first -= edge[i].sum.first;
			res.second -= edge[i].sum.second;
			edge[i ^ 1].sum = make_pair(res.first + res.second,res.second);
			res.first += edge[i].sum.first;
			res.second += edge[i].sum.second;
			dfs2(edge[i].to,now);
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int u,v,i = 1;i < n;i++)
	{
		cin >> u >> v;
		addE(u,v);
		addE(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for (int i = 1;i <= n;i++)
	{
		ll sum = 0;
		for (int j = first[i];j;j = edge[j].next)
			sum += edge[j].sum.first;
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;
}