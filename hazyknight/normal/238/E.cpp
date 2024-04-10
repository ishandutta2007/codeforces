#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int MAXN = 105;
const int INF = (1 << 30);

int n,m,a,b,t;
int from[MAXN],to[MAXN];
int dist[MAXN][MAXN];
int isp[MAXN][MAXN];
int g[MAXN],f[MAXN];

bool vis[MAXN];

int dfs(int cur,int aim)
{
	if (cur == aim)
		return f[cur];
	if (vis[cur])
		return g[cur];
	vis[cur] = true;
	g[cur] = 0;
	for (int i = 1;i <= n;i++)
		if (dist[cur][i] + dist[i][aim] == dist[cur][aim] && dist[cur][aim] == dist[i][aim] + 1)
			g[cur] = max(g[cur],dfs(i,aim));
	return g[cur] = min(g[cur],f[cur]);
}

int main()
{
	cin >> n >> m >> a >> b;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++)
			if (i != j)
				dist[i][j] = INF;
	for (int i = 1,u,v;i <= m;i++)
	{
		cin >> u >> v;
		dist[u][v] = 1;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				if (i != j && j != k && k != i && dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
	cin >> t;
	for (int k = 1;k <= t;k++)
	{
		cin >> from[k] >> to[k];
		int S = from[k],T = to[k];
		if (dist[S][T] == INF)
			continue;
		for (int i = 1;i <= n;i++)
			if (dist[S][i] + dist[i][T] == dist[S][T])
			{
				bool flag = true;
				for (int j = 1;j <= n && flag;j++)
				{
					if (j == i)
						continue;
					if (dist[S][j] + dist[j][T] == dist[S][T])
						if (dist[S][j] == dist[S][i])
							flag = false;
				}
				if (flag == true)
					isp[k][i] = 1;
			}
	}
	for (int i = 1;i <= n;i++)
		f[i] = INF;
	f[b] = 0;
	while (1)
	{
		bool ok = false;
		for (int i = 1;i <= t;i++)
		{
			if (dist[from[i]][to[i]] == INF)
				continue;
			memset(vis,0,sizeof(vis));
			for (int j = 1;j <= n;j++)
				if (isp[i][j])
				{
					int ret = dfs(j,to[i]) + 1;
					if (ret < f[j])
					{
						f[j] = ret;
						ok = true;
					}
				}
		}
		if (ok == false)
			break;
	}
	cout << ((f[a] >= INF) ? -1 : f[a]) << endl;
    return 0;
}