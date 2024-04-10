#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int inf = 1e9;

void solve() {
	int n = nxt(), m = nxt();
	vector<int> d(n, inf);
	d[n - 1] = 0;
	vector<vector<int>> a(n);
	vector<int> outer(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[v].push_back(u);
		outer[u] += 1;
	}
	set<pair<int, int>> S;
	for (int i = 0; i < n; ++i) {
		S.insert({d[i], i});
	}
	while (!S.empty()) {
		auto [val, v] = *S.begin();
		S.erase(S.begin());
		for (int x : a[v]) {
			// d[x] = min(d[x], d[v] + 1 + nondeleted)
			--outer[x];
			int nv = val + 1 + outer[x];
			if (nv < d[x]) {
				S.erase({d[x], x});
				d[x] = nv;
				S.insert({d[x], x});
			}
		}
	}
	cout << d[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}