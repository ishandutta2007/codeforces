#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
const int N = 100001;
int p[N], q[N], d[N], ans1[N], ans2[N];
vector<pair<int,int>> adj[N];

void trace(int u, int* ans)
{
	ans[u] = max(ans[u], q[u]);
	for (pair<int,int> e : adj[u])
		if (e.first != p[u])
		{
			q[e.first] = max(q[e.first], q[u]);
			trace(e.first, ans);
		}
}

int dfs(int u, int* ans = nullptr, bool reset = true)
{
	if (reset)
	{
		d[u] = 0;
		fill(p, p + N, 0);
		fill(q, q + N, 0);
	}
	int res = u;
	for (pair<int,int> e : adj[u])
		if (e.first != p[u])
		{
			d[e.first] = d[p[e.first] = u] + e.second;
			int tmp = dfs(e.first, ans, false);
			if (d[tmp] > d[res])
			    swap(res, tmp);
			q[u] = max(q[u], d[tmp] - d[u]);
		}
	if (ans != nullptr)
	{
		ans[u] = d[res] - d[u];
		if (reset)
			trace(u, ans);
	}
	return res;
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<int> path;
	for (int i = dfs(dfs(dfs(1), ans1), ans2); i != 0; i = p[i])
		path.push_back(i);
	if (path.size() > k)
	{
		int ans = 1e9;
		for (int i = k; i <= path.size(); ++i)
			ans = min(ans, max(ans1[path[i - 1]], ans2[path[i - k]]));
		cout << ans;
	}
	else 
		cout << max(ans1[path.back()], ans2[path.front()]);
	return 0;
}