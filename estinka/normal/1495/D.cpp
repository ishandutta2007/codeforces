#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > g(n);
	for (int i = 0, a, b; i < m; i++) cin >> a >> b, g[--a].push_back(--b), g[b].push_back(a);
	vector<vector<int> > dist(n, vector<int>(n, -1)), cnt(n + 1, vector<int>(n + 1, 0));
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++)
	{
		queue<int> q; q.push(i);
		dist[i][i] = 0;
		while (!q.empty())
		{
			int v = q.front(); q.pop();
			for (int j : g[v])
			{
				if (dist[i][j] == -1)
				{
					q.push(j);
					dist[i][j] = dist[i][v] + 1;
				}
			}
		}
	}
	vector<int> seen(n + 1, 0);
	for (int u = 0; u < n; u++)
	{
		for (int v = 0; v < n; v++)
		{
			for (int i = 0; i < n + 1; i++) seen[i] = 0;
			dp[u][v] = 1;
			for (int i = 0; i < n; i++)
			{
				if (dist[u][v] == dist[u][i] + dist[v][i])
				{
					seen[dist[u][i]]++;
				}
				cnt[dist[u][i]][dist[v][i]]++;
			}
			for (int i = 0; i <= dist[u][v]; i++)
			{
				if (seen[i] != 1) dp[u][v] = 0;
				seen[i] = 0;
			}
			if (dp[u][v])
			{
				for (int i = 0; i < n; i++)
				{
					if (dist[u][v] == dist[u][i] + dist[v][i]) continue;
					int cnt = 0;
					for (int j : g[i])
					{
						if (dist[u][j] + 1 == dist[u][i] && dist[v][j] + 1 == dist[v][i]) cnt++;
					}
					dp[u][v] = (dp[u][v] * 1ll * cnt) % mod;
				}
			}
			for (int i = 0; i < n; i++)
			{
				cnt[dist[u][i]][dist[v][i]] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << dp[i][j] << " ";
		cout << "\n";
	}
	return 0;
}