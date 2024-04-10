#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAXN = 1005;

struct Edge
{
	int to;
	int next;
}edge[MAXN << 1];

int n,m,s,t,id,ans;
int first[MAXN];
int diss[MAXN],dist[MAXN];

bool inqueue[MAXN];

bool mark[MAXN][MAXN];

int main()
{
	cin >> n >> m >> s >> t;
	for (int i = 1;i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		mark[u][v] = mark[v][u] = true;
		edge[++id] = (Edge){v,first[u]};
		first[u] = id;
		edge[++id] = (Edge){u,first[v]};
		first[v] = id;
	}
	for (int i = 1;i <= n;i++)
		diss[i] = dist[i] = (1 << 30) - 2;
	queue<int> Q;
	Q.push(s);
	diss[s] = 0;
	inqueue[s] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		inqueue[now] = false; 
		for (int i = first[now];i;i = edge[i].next)
			if (diss[now] + 1 < diss[edge[i].to])
			{
				diss[edge[i].to] = diss[now] + 1;
				if (!inqueue[edge[i].to])
					Q.push(edge[i].to),inqueue[edge[i].to] = true;
			}
	}
	Q.push(t);
	dist[t] = 0;
	inqueue[t] = true;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		inqueue[now] = false; 
		for (int i = first[now];i;i = edge[i].next)
			if (dist[now] + 1 < dist[edge[i].to])
			{
				dist[edge[i].to] = dist[now] + 1;
				if (!inqueue[edge[i].to])
					Q.push(edge[i].to),inqueue[edge[i].to] = true;
			}
	}
//	for (int i = 1;i <= n;i++)
//		cout << diss[i] << ' ' << dist[i] << endl;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (i != j && !mark[i][j] && diss[i] + 1 + dist[j] >= diss[t] && dist[i] + 1 + diss[j] >= diss[t])
			{
			//	cout << i << ' ' << j << endl;
				ans++;
			}
	cout << ans / 2 << endl;
	return 0;
}