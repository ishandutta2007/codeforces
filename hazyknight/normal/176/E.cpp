#pragma GCC optimize(2)
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

int n,q,id,x;
int fa[MAXN][17];
int first[MAXN];
int len[MAXN];
int dfn[MAXN];
int pos[MAXN];

ll ans;
ll depth[MAXN];

char tp;

set<int> S;

void addE(int u,int v,int w)
{
	edge[++id] = (Edge){v,w,first[u]};
	first[u] = id;
}

void dfs(int u)
{
	pos[dfn[u] = ++id] = u;
	for (int i = 1;i <= 16;i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa[u][0])
		{
			fa[edge[i].to][0] = u;
			depth[edge[i].to] = depth[u] + edge[i].w;
			len[edge[i].to] = len[u] + 1;
			dfs(edge[i].to);
		}
}

ll dis(int u,int v)
{
	if (!u || v == n + 1 || !v || u == n + 1)
		return 0;
	u = pos[u];
	v = pos[v];
	if (len[u] < len[v])
		swap(u,v);
	int U = u,V = v;
	int dif = len[u] - len[v];
	for (int i = 16;i >= 0;i--)
		if (dif >> i & 1)
			u = fa[u][i];
	if (u == v)
		return depth[U] + depth[V] - 2 * depth[u];
	for (int i = 16;i >= 0;i--)
		if (fa[u][i] != fa[v][i])
		{
			u = fa[u][i];
			v = fa[v][i];
		}
	return depth[U] + depth[V] - 2 * depth[fa[u][0]];
}

int main()
{
	scanf("%d",&n);
	for (int u,v,w,i = 1;i < n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		addE(u,v,w);
		addE(v,u,w);
	}
	id = 0;
	dfs(1);
	scanf("%d",&q);
	S.insert(0);
	S.insert(n + 1);
	while (q--)
	{
		tp = getchar();
		while (tp != '+' && tp != '-' && tp != '?')
			tp = getchar();
		if (tp == '+')
		{
			scanf("%d",&x);
			x = dfn[x];
			set<int>::iterator nxt = S.upper_bound(x),pre = nxt;
			pre--;
			ans -= dis(*pre,*nxt);
			ans += dis(*pre,x);
			ans += dis(x,*nxt);
			S.insert(x);
		}
		if (tp == '-')
		{
			scanf("%d",&x);
			x = dfn[x];
			set<int>::iterator cur = S.find(x),pre = cur,nxt = cur;
			nxt++;
			pre--;
			ans -= dis(*pre,*cur);
			ans -= dis(*cur,*nxt);
			ans += dis(*pre,*nxt);
			S.erase(cur);
		}
		if (tp == '?')
		{
			set<int>::iterator pre = S.begin(),nxt = S.end();
			pre++;
			nxt--;
			nxt--;
			printf("%lld\n",(ans + dis(*pre,*nxt)) / 2);
		}
	}
	return 0;
}