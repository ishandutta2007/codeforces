#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int sx, sy, fx, fy;
	cin >> sx >> sy >> fx >> fy;
	vector<int> x(m), y(m);
	for (int i = 0; i < m; ++i) {
		cin >> x[i] >> y[i];
	}
	vector<vector<pair<int, int>>> g(m + 2);
	vector<int> p(m);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int i, int j) {
		return x[i] < x[j];
	});
	for (int i = 0; i + 1 < m; ++i) {
		int l = p[i];
		int r = p[i + 1];
		int dist = min(abs(x[l] - x[r]), abs(y[l] - y[r]));
		++l;
		++r;
		g[l].emplace_back(dist, r);
		g[r].emplace_back(dist, l);
	}
	sort(p.begin(), p.end(), [&](int i, int j) {
		return y[i] < y[j];
	});
	for (int i = 0; i + 1 < m; ++i) {
		int l = p[i];
		int r = p[i + 1];
		int dist = min(abs(x[l] - x[r]), abs(y[l] - y[r]));
		++l;
		++r;
		g[l].emplace_back(dist, r);
		g[r].emplace_back(dist, l);
	}
	for (int i = 1; i <= m; ++i) {
		int dist = min(abs(x[i - 1] - sx), abs(y[i - 1] - sy));
		g[0].emplace_back(dist, i);
	}
	for (int i = 1; i <= m; ++i) {
		int dist = abs(x[i - 1] - fx) + abs(y[i - 1] - fy);
		g[i].emplace_back(dist, m + 1);
	}
	vector<ll> dist(m + 2, INF);
	dist[0] = 0;
	set<pair<ll, int>> set;
	for (int i = 0; i <= m + 1; ++i) {
		set.insert({dist[i], i});
	}
	while (!set.empty()) {
		int v = set.begin()->second;
		set.erase(set.begin());
		for (auto&[w, u]: g[v]) {
			if (dist[v] + w < dist[u]) {
				set.erase({dist[u], u});
				dist[u] = dist[v] + w;
				set.insert({dist[u], u});
			}
		}
	}
	cout << min(dist[m + 1], 1ll * (abs(fx - sx) + abs(fy - sy)));
	return 0;
}