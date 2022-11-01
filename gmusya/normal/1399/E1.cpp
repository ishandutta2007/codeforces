#include <iostream>
#include <vector>
#include <queue>
#include <set>

typedef long long ll;

using namespace std;

void dfs(int v, int p, vector <ll> &sz, vector <vector <pair <int, int>>> &g, vector <pair <ll, ll>> &edges) {
	int cnt = 0;
	for (auto e : g[v]) {
		if (e.first == p) continue;
		cnt++;
		dfs(e.first, v, sz, g, edges);
		sz[v] += sz[e.first];
		edges.push_back({ sz[e.first], e.second });
	}
	if (!cnt) sz[v] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		ll s;
		cin >> s;
		vector <vector <pair <int, int>>> g(n);
		for (int i = 1; i < n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			g[u].push_back({ v, w });
			g[v].push_back({ u, w });
		}
		vector <ll> sz(n);
		vector <pair <ll, ll>> edges;
		dfs(0, -1, sz, g, edges);
		int cnt = 0;
		multiset <pair <ll, pair <ll, ll>>> se;
		ll sum = 0;
		for (int i = 0; i < edges.size(); i++) {
			while (edges[i].first * edges[i].second > s) {
				cnt++;
				edges[i].second /= 2;
			}
			se.insert({ edges[i].first * (edges[i].second - edges[i].second / 2), {edges[i].first, edges[i].second} });
			sum += edges[i].first * edges[i].second;
		}
		while (sum > s) {
			auto x = *se.rbegin();
			cnt++;
			se.erase(se.find(x));
			sum -= x.first;
			x.second.second /= 2;
			se.insert({ x.second.first * (x.second.second - x.second.second / 2), x.second });
		}
		cout << cnt << '\n';
	}
	return 0;
}