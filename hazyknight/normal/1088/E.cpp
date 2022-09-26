#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <assert.h>

using namespace std;

typedef long long ll;

inline char gc()
{
	static char buf[262144],*p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf,1,262144,stdin),p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int v = 0;
	bool mark = false;
	char c = gc();
	while ((c < '0' || c > '9') && c != '-')
		c = gc();
	if (c == '-')
	{
		mark = true;
		c = gc();
	}
	while (c >= '0' && c <= '9')
	{
		v = v * 10 + c - '0';
		c = gc();
	}
	if (mark)
		return -v;
	return v;
}

const int MAXN = 300005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,id;
int first[MAXN];

ll MAX = -(1ll << 60);
ll a[MAXN];

pair<ll,int> ans;
pair<ll,int> f[MAXN];
pair<ll,int> g[MAXN];

bool flag;

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

ll dfs1(int now,int fa)
{
	ll sum = a[now];
	for (int i = first[now];i;i = edge[i].next)
		if (edge[i].to != fa)
			sum += dfs1(edge[i].to,now);
	MAX = max(MAX,sum);
	return max(sum,0ll);
}

void dfs2(int now,int fa)
{
	f[now] = make_pair(a[now] - MAX,1);
	g[now] = make_pair(0,0);
	pair<ll,int> trans;
	for (int i = first[now];i;i = edge[i].next)
	{
		int to = edge[i].to;
		if (to == fa)
			continue;
		dfs2(to,now);
		trans = max(f[to],g[to]);
		g[now].first += trans.first;
		g[now].second += trans.second;
		trans = max(trans,make_pair(f[to].first + MAX,f[to].second - 1));
		f[now].first += trans.first;
		f[now].second += trans.second;
	}
	ans = max(ans,f[now]);
	if (g[now].second)
		ans = max(ans,g[now]);
}

int main()
{
	n = read();
	for (int i = 1;i <= n;i++)
		a[i] = read();
	for (int u,v,i = 1;i < n;i++)
	{
		u = read(),v = read();
		addE(u,v);
		addE(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%I64d %d\n",ans.first + ans.second * MAX,ans.second);
	return 0;
}