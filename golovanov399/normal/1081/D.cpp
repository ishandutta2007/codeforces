#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Dsu {
	int n;
	vector<int> p;
	vector<int> rk;
	vector<int> cn;

	Dsu(int _n): n(_n), p(_n), rk(_n), cn(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	int merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return cn[u];
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		cn[u] += cn[v];
		return cn[u];
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), k = nxt();
	Dsu dsu(n);
	for (int i = 0; i < k; ++i) {
		dsu.cn[nxt() - 1] = 1;
	}
	vector<array<int, 3>> ed(m);
	for (int i = 0; i < m; ++i) {
		ed[i][1] = nxt() - 1;
		ed[i][2] = nxt() - 1;
		ed[i][0] = nxt();
	}
	sort(all(ed));
	for (auto v : ed) {
		if (dsu.merge(v[1], v[2]) == k) {
			for (int i = 0; i < k; ++i) {
				printf("%d ", v[0]);
			}
			printf("\n");
			return 0;
		}
	}

	return 0;
}