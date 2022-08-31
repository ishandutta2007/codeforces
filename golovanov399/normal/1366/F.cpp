#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int mod = 1000000007;

long long apsum(int n, long long a, long long d) {
	a %= mod;
	d %= mod;
	return (a + a + d * (n - 1)) % mod * n % mod * (mod + 1) / 2 % mod;
}

struct Edge {
	int to, w;
};

const int N = 2222;
vector<Edge> a[N];

void remax(int& x, int y) {
	x = max(x, y);
}

void solve() {
	int n = nxt(), m = nxt(), q = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		a[u].push_back({v, w});
		a[v].push_back({u, w});
	}
	vector<int> cur(n, -1);
	cur[0] = 0;
	vector<int> vals;
	for (int i = 0; i < n; ++i) {
		vector<int> tmp(n, -1);
		for (int j = 0; j < n; ++j) {
			for (auto e : a[j]) {
				if (cur[e.to] > -1) {
					remax(tmp[j], cur[e.to] + e.w);
				}
			}
		}
		tmp.swap(cur);
		vals.push_back(*max_element(all(cur)));
	}
	vector<int> max_edge(n);
	for (int i = 0; i < n; ++i) {
		for (auto e : a[i]) {
			remax(max_edge[i], e.w);
		}
	}
	vector<pair<long long, long long>> slopes;
	for (int i = 0; i < n; ++i) {
		if (cur[i] == -1) {
			continue;
		}
		slopes.push_back({cur[i], max_edge[i]});
	}
	sort(all(slopes), [](const pair<int, int>& p, const pair<int, int>& q) {
		return make_pair(p.second, -p.first) < make_pair(q.second, -q.first);
	});
	vector<pair<long long, long long>> st = {slopes[0]};
	vector<long long> bends = {0ll};
	for (int i = 1; i < (int)slopes.size(); ++i) {
		// cerr << slopes[i].first << " " << slopes[i].second << " --\n";
		while (!st.empty()) {
			auto p = st.back(), q = slopes[i];
			// p.first + p.second * k <= q.first + q.second * k
			// p.first - q.first <= k * (q.second - p.second)
			if (q.second == p.second) {
				break;
			}
			if (p.first - q.first + q.second - p.second - 1 <= 0) {
				st.pop_back();
				bends.pop_back();
				continue;
			}
			long long k = (p.first - q.first + q.second - p.second - 1) / (q.second - p.second);
			if (k <= bends.back()) {
				st.pop_back();
				bends.pop_back();
				continue;
			} else {
				st.push_back(q);
				bends.push_back(k);
				break;
			}
		}
		if (st.empty()) {
			st.push_back(slopes[i]);
			bends.push_back(0);
		}
	}
	// for (int i = 0; i < (int)st.size(); ++i) {
	// 	cerr << "(" << st[i].first << ", " << st[i].second << "): " << bends[i] << "...\n";
	// }


	if (q <= (int)vals.size()) {
		cout << accumulate(vals.begin(), vals.begin() + q, 0ll) % mod << "\n";
	} else {
		long long ans = accumulate(all(vals), 0ll) % mod;
		q -= n;
		for (int i = 0; i < (int)st.size(); ++i) {
			long long mn = max(bends[i], 1ll);
			long long mx = (i == (int)st.size() - 1) ? 1e18 : bends[i + 1];
			if (mn > q) {
				break;
			}
			if (mx > q) {
				mx = q + 1;
			}
			ans += apsum(mx - mn, st[i].first + st[i].second * mn, st[i].second);
		}
		cout << ans % mod << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}