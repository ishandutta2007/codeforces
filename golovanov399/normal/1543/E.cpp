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

using uint = unsigned int;

uint mult(uint x, uint y) {
	uint res = 0;
	while (y) {
		res ^= x << __builtin_ctz(y);
		y &= y - 1;
	}
	return res;
}

void solve() {
	int n = nxt();
	const int nn = 1 << n;
	vector<vector<int>> a(nn);
	const int m = (n << (n - 1));
	for (int i = 0; i < m; ++i) {
		int u = nxt(), v = nxt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<int> p(nn);
	vector<char> used(nn);
	vector<int> layer = {0};
	for (int it = 0; it < n; ++it) {
		for (int x : layer) {
			used[x] = 1;
		}
		set<int> new_layer;
		if (layer == vector{0}) {
			for (int i = 0; i < n; ++i) {
				p[a[0][i]] = 1 << i;
			}
		}
		for (int u : layer) {
			for (int v : a[u]) {
				if (!used[v]) {
					new_layer.insert(v);
					p[v] |= p[u];
				}
			}
		}
		layer = {all(new_layer)};
	}
	vector<int> q(nn);
	for (int i = 0; i < nn; ++i) {
		q[p[i]] = i;
	}
	for (int x : q) {
		cout << x << " ";
	}
	cout << "\n";

	if (n & (n - 1)) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < nn; ++i) {
		int x = 0;
		for (int j = 0; j < n; ++j) {
			if (p[i] & (1 << j)) {
				x ^= j;
			}
		}
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}