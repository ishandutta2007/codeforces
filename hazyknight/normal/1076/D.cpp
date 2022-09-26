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
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const ll INF = (1ll << 60) - 1;

struct Edge
{
	int to;
	int len;
	int next;
}edge[MAXN << 1];

int n,m,k,id;
int first[MAXN];

ll dis[MAXN];

bool mark[MAXN];

pair<int,int> pre[MAXN];
priority_queue<pair<ll,int> > Q;

void addE(int u,int v,int c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
}

void Dijkstra()
{
	Q.push(make_pair(0,1));
	for (int i = 2;i <= n;i++)
		dis[i] = INF;
	while (!Q.empty())
	{
		int now = Q.top().second;
		ll D = -Q.top().first;
		Q.pop();
		if (mark[now])
			continue;
		mark[now] = true;
		for (int i = first[now];i;i = edge[i].next)
			if (dis[edge[i].to] > D + edge[i].len)
			{
				pre[edge[i].to] = make_pair((i + 1) / 2,now);
				Q.push(make_pair(-(dis[edge[i].to] = D + edge[i].len),edge[i].to));
			}
	}
}

void dfs(int now)
{
	for (int i = first[now];k && i;i = edge[i].next)
	{
		k--;
		printf("%d ",edge[i].len);
		dfs(edge[i].to);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int u,v,c,i = 1;i <= m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		addE(u,v,c);
		addE(v,u,c);
	}
	Dijkstra();
	memset(first,0,sizeof(first));
	id = 0;
	for (int i = 2;i <= n;i++)
		addE(pre[i].second,i,pre[i].first);
	memset(mark,0,sizeof(mark));
	printf("%d\n",min(n - 1,k));
	dfs(1);
	printf("\n");
	return 0;
}