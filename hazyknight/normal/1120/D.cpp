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
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct Edge
{
	int to;
	int nxt;
}edge[MAXN << 1];

struct EDGE
{
	int u,v,w,id;
	bool operator < (const EDGE &p)const
	{
		return w < p.w;
	}
}e[MAXN];

int n,m,id,tot;
int c[MAXN];
int first[MAXN];
int pre[MAXN];

ll ans;

vector<int> cont;

int getroot(int u)
{
	return u == pre[u] ? u : pre[u] = getroot(pre[u]);
}

void addE(int u,int v)
{
	edge[++id] = (Edge){v,first[u]};
	first[u] = id;
}

void dfs(int u,int fa)
{
	int ch = 0,L = tot + 1;
	for (int i = first[u];i;i = edge[i].nxt)
		if (edge[i].to != fa)
		{
			ch++;
			dfs(edge[i].to,u);
		}
	if (!ch)
		tot++;
	e[++m] = (EDGE){L - 1,tot,c[u],u};
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
		scanf("%d",&c[i]);
	for (int u,v,i = 1;i < n;i++)
	{
		scanf("%d%d",&u,&v);
		addE(u,v);
		addE(v,u);
	}
	dfs(1,0);
	sort(e + 1,e + m + 1);
	for (int i = 0;i <= tot;i++)
		pre[i] = i;
	for (int i = 1;i <= m;i++)
		if (getroot(e[i].u) != getroot(e[i].v))
		{
			pre[getroot(e[i].u)] = getroot(e[i].v);
			ans += e[i].w;
		}
	sort(c + 1,c + n + 1);
	n = unique(c + 1,c + n + 1) - c - 1;
	for (int i = 0;i <= tot;i++)
		pre[i] = i;
	for (int i = 1,j = 1;i <= n;i++)
	{
		int k = j;
		while (e[j].w == c[i])
		{
			if (getroot(e[j].u) != getroot(e[j].v))
				cont.push_back(e[j].id);
			j++;
		}
		for (int l = k;l < j;l++)
			pre[getroot(e[l].u)] = getroot(e[l].v);
	}
	sort(cont.begin(),cont.end());
	printf("%I64d %d\n",ans,(int)cont.size());
	for (int i = 0;i < cont.size();i++)
		printf("%d ",cont[i]);
	printf("\n");
	return 0;
}