#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int to;
	int w;
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt();
	vector<vector<Edge>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, -w});
	}

	pair<int, vector<int>> ans = {-1, {}};
	for (int z = 0; z < n; ++z) {
		vector<pair<int, int>> range(n, {-2 * n, 2 * n});
		range[z] = {0, 0};
		set<pair<int, int>> S;
		for (int i = 0; i < n; ++i) {
			S.insert({range[i].second - range[i].first, i});
		}
		auto upd = [&](int i, int l, int r) {
			if (range[i].first >= l && range[i].second <= r) {
				return;
			}
			S.erase({range[i].second - range[i].first, i});
			range[i].first = max(range[i].first, l);
			range[i].second = min(range[i].second, r);
			S.insert({range[i].second - range[i].first, i});
		};
		bool broken = false;
		while (!S.empty()) {
			int v = S.begin()->second;
			S.erase(S.begin());
			if (range[v].first > range[v].second) {
				broken = true;
				break;
			}
			for (auto [to, w] : a[v]) {
				if (w) {
					upd(to, range[v].first + w, range[v].second + w);
				} else {
					upd(to, range[v].first - 1, range[v].second + 1);
				}
			}
		}
		if (broken) {
			continue;
		}
		vector<int> vals(n);
		for (int i = 0; i < n; ++i) {
			vals[i] = range[i].second;
		}
		for (int i = 0; i < n; ++i) {
			for (auto [to, w] : a[i]) {
				if (w && vals[to] != vals[i] + w) {
					broken = true;
					break;
				} else if (!w && abs(vals[to] - vals[i]) != 1) {
					broken = true;
					break;
				}
			}
		}
		if (!broken) {
			ans = max(ans, {*max_element(all(vals)), vals});
		}
	}

	if (ans.first == -1) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << ans.first << "\n";
	for (auto x : ans.second) {
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}