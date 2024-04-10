#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		std::iota(p.begin(), p.end(), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

void solve() {
	int n = nxt();
	vector<int> p(n);
	for (auto& x : p) {
		x = nxt() - 1;
	}
	Dsu dsu(n);
	for (int i = 0; i < n; ++i) {
		dsu.merge(i, p[i]);
	}
	vector<vector<int>> eds(n);
	for (int i = 0; i + 1 < n; ++i) {
		if (dsu.merge(i, i + 1)) {
			eds[i].push_back(i + 1);
			eds[i + 1].push_back(i);
		}
	}
	vector<int> q;
	function<void(int, int)> rec = [&](int v, int par) {
		int u = v;
		do {
			for (int x : eds[u]) {
				if (x == par) {
					continue;
				}
				rec(x, u);
			}
			q.push_back(u);
			u = p[u];
		} while (u != v);
	};
	rec(0, -1);
	reverse(all(q));
	for (auto x : q) {
		cout << x + 1 << " ";
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