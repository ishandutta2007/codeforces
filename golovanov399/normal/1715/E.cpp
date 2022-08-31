#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const long long inf = 1e18;

void remin(long long& x, long long y) {
	x = (x < y) ? x : y;
}

using T = pair<long long, int>;

bool f(long long x1, long long y1, long long x2, long long y2) {
	return (__int128_t)x1 * y2 <= (__int128_t)x2 * y1;
}

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	vector<vector<pair<int, int>>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}

	vector<long long> d(n, inf);
	d[0] = 0;
	auto ans = d;

	for (int it = 0; it <= k; ++it) {
		priority_queue<T, vector<T>, greater<T>> pq;
		for (int i = 0; i < n; ++i) {
			pq.push({d[i], i});
		}
		while (!pq.empty()) {
			auto [val, i] = pq.top();
			pq.pop();
			if (d[i] != val) {
				continue;
			}
			if (val >= inf) {
				break;
			}
			for (auto [j, w] : a[i]) {
				if (auto nv = val + w; nv < d[j]) {
					d[j] = nv;
					pq.push({nv, j});
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			remin(ans[i], d[i]);
		}

		for (int i = 0; i < n; ++i) {
			d[i] += 1ll * i * i;
		}

		vector<pair<int, long long>> ch;
		for (int i = 0; i < n; ++i) {
			while ((int)ch.size() >= 2 && f(
					ch.end()[-1].first - ch.end()[-2].first,
					ch.end()[-1].second - ch.end()[-2].second,
					i - ch.back().first,
					d[i] - ch.back().second
			)) {
				ch.pop_back();
			}
			ch.push_back({i, d[i]});
		}
		vector<long long> nd(n);
		for (int i = 0, j = 0; i < n; ++i) {
			while (j + 1 < (int)ch.size() && ch[j + 1].second - 2ll * i * ch[j + 1].first <= ch[j].second - 2ll * i * ch[j].first) {
				++j;
			}
			nd[i] = ch[j].second - 2ll * i * ch[j].first + 1ll * i * i;
		}
		// nd[i] = min {d[j] - 2 * i * j} + i^2
		d = nd;
	}
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}