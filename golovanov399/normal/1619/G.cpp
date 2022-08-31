#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Mine {
	int x, y;
	int t;
};

void solve() {
	int n = nxt(), k = nxt();
	map<int, vector<pair<int, int>>> by_x;
	map<int, vector<pair<int, int>>> by_y;
	vector<Mine> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].t;
		by_x[a[i].x].push_back({a[i].y, i});
		by_y[a[i].y].push_back({a[i].x, i});
	}
	for (auto& p : by_x) {
		sort(all(p.second));
	}
	for (auto& p : by_y) {
		sort(all(p.second));
	}
	vector<vector<int>> to(n);
	for (int i = 0; i < n; ++i) {
		int x = a[i].x;
		int y = a[i].y;
		const auto& vx = by_x[x];
		const auto& vy = by_y[y];
		{
			auto it = lower_bound(all(vx), pair{y, i});
			if (auto nit = next(it); nit != vx.end() && nit->first - y <= k) {
				to[i].push_back(nit->second);
			}
			if (it != vx.begin() && y - prev(it)->first <= k) {
				to[i].push_back(prev(it)->second);
			}
		}
		{
			auto it = lower_bound(all(vy), pair{x, i});
			if (auto nit = next(it); nit != vy.end() && nit->first - x <= k) {
				to[i].push_back(nit->second);
			}
			if (it != vy.begin() && x - prev(it)->first <= k) {
				to[i].push_back(prev(it)->second);
			}
		}
	}
	vector<int> times;
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		times.push_back(INT_MAX);
		vector<int> st = {i};
		used[i] = true;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			times.back() = min(times.back(), a[v].t);
			for (int x : to[v]) {
				if (!used[x]) {
					used[x] = 1;
					st.push_back(x);
				}
			}
		}
	}
	sort(all(times));
	for (int i = 1; i < (int)times.size(); ++i) {
		if (times[(int)times.size() - 1 - i] <= i - 1) {
			cout << i - 1 << "\n";
			return;
		}
	}
	cout << (int)times.size() - 1 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}