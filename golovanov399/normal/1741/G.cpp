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

using u64 = uint64_t;

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	int m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> d(n, -1);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	vector<int> order;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		order.push_back(v);
		for (int x : a[v]) {
			if (d[x] == -1) {
				d[x] = d[v] + 1;
				q.push(x);
			}
		}
	}
	
	vector<int> car(n);
	vector<int> friends(nxt());
	for (auto& x : friends) {
		x = nxt() - 1;
		car[x] += 1;
	}
	vector<int> lohs(nxt());
	for (auto& x : lohs) {
		x = friends[nxt() - 1];
		car[x] -= 1;
	}
	const int cnt = lohs.size();

	vector<u64> masks(n, 0);
	for (int v : order) {
		int guarantee = 0;
		for (int i = 0; i < cnt; ++i) {
			if (lohs[i] == v) {
				guarantee |= 1 << i;
			}
		}
		masks[v] |= 1ll << guarantee;
		for (int x : a[v]) {
			if (d[x] != d[v] - 1) {
				continue;
			}
			for (auto m = masks[x]; m > 0; m &= m - 1) {
				masks[v] |= 1ll << (__builtin_ctzll(m) | guarantee);
			}
		}
		// cerr << v + 1 << ": " << bitset<16>(masks[v]) << "\n";
	}

	u64 can = 1;
	for (int i = 0; i < n; ++i) {
		for ([[maybe_unused]] int it = 0; it < car[i]; ++it) {
			u64 nw = 0;
			for (int m1 = 0; m1 < 64; ++m1) {
				for (int m2 = 0; m2 < 64; ++m2) {
					if ((can & (1ll << m1)) && (masks[i] & (1ll << m2))) {
						nw |= 1ll << (m1 | m2);
					}
				}
			}
			can = nw;
		}
	}
	int ans = cnt;
	for (auto m = can; m; m &= m - 1) {
		ans = min(ans, cnt - __builtin_popcountll(__builtin_ctzll(m)));
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}