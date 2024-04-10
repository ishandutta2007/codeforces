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

const int MAXN = 2005;
const int MAXM = 4005;
const ll INF = (1ll << 60) - 1;

struct Edge
{
	int to;
	ll cap;
	int next;
}edge[MAXM << 1];

int n,m,id = 1,S,T;
int first[MAXN];
int cur[MAXN];
int level[MAXN];

ll ans;

queue<int> Q;

void addE(int u,int v,ll c)
{
	edge[++id] = (Edge){v,c,first[u]};
	first[u] = id;
	edge[++id] = (Edge){u,0,first[v]};
	first[v] = id;
}

bool bfs()
{
	memset(level,0,sizeof(level));
	level[S] = 1;
	Q.push(S);
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		for (int i = first[now];i;i = edge[i].next)
			if (edge[i].cap > 0 && !level[edge[i].to])
			{
				level[edge[i].to] = level[now] + 1;
				Q.push(edge[i].to);
			}
	}
	return level[T];
}

ll dfs(int now,ll flow)
{
	if (now == T)
		return flow;
	ll res = 0;
	for (int &i = cur[now];i;i = edge[i].next)
		if (edge[i].cap > 0 && level[edge[i].to] == level[now] + 1)
		{
			ll ret = dfs(edge[i].to,min(edge[i].cap,flow));
			flow -= ret;
			res += ret;
			edge[i].cap -= ret;
			edge[i ^ 1].cap += ret;
			if (!flow)
				break;
		}
	return res;
}

ll Dinic()
{
	ll res = 0;
	while (bfs())
	{
		memcpy(cur,first,sizeof(cur));
		res += dfs(S,INF);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	S = 0,T = n + m + 1;
	for (int a,i = 1;i <= n;i++)
	{
		cin >> a;
		addE(m + i,T,a);
	}
	for (int u,v,c,i = 1;i <= m;i++)
	{
		cin >> u >> v >> c;
		addE(S,i,c);
		addE(i,m + u,INF);
		addE(i,m + v,INF);
		ans += c;
	}
	cout << ans - Dinic() << endl;
	return 0;
}