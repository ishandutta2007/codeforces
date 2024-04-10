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
	string s;
	cin >> s;
	vector<vector<int>> layers = {{0}};
	vector<vector<int>> comps;
	for (int i = 0; i < 2 * n; ++i) {
		if (s[i] == ')') {
			comps.push_back(layers.back());
			layers.pop_back();
		} else {
			layers.push_back({});
		}
		layers.back().push_back(i + 1);
	}
	comps.push_back(layers[0]);

	Dsu dsu(2 * n);
	for (auto v : comps) {
		for (int i = 1; i < (int)v.size(); ++i) {
			dsu.merge(v[0], v[i] - 1);
			if (i < (int)v.size() - 1) {
				dsu.merge(v[0], v[i]);
			}
		}
	}
	set<int> S;
	for (int i = 0; i < 2 * n; ++i) {
		S.insert(dsu.get(i));
	}
	cout << S.size() << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}