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

const int N = 111111;
vector<int> a[N];
int par[N];
vector<int> order;

void dfs_par(int v) {
	for (int x : a[v]) {
		if (x == par[v]) {
			continue;
		}
		par[x] = v;
		dfs_par(x);
	}
	order.push_back(v);
}

struct TwoMax {
	int x, y;

	TwoMax() { x = y = 0; }

	void relax(itn z) {
		if (z > x) {
			y = x;
			x = z;
		} else if (z > y) {
			y = z;
		}
	}
};

void maxPath(int n, int len, int& ans) {
	vector<int> tmp(n);
	for (auto v : order) {
		TwoMax tm;
		for (int x : a[v]) {
			if (x == par[v]) {
				continue;
			}
			tm.relax(tmp[x]);
		}
		if (tm.x + tm.y >= len) {
			++ans;
		} else {
			tmp[v] = tm.x + 1;
		}
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	par[0] = -1;
	dfs_par(0);

	vector<int> ans(n);
	function<void(int, int, int, int)> fill = [&](int l, int r, int u, int d) {
		if (u == d) {
			for (int i = l; i < r; ++i) {
				ans[i] = d;
			}
			return;
		}
		if (l >= r) {
			return;
		}
		int m = (l + r) / 2;
		maxPath(n, m, ans[m]);
		fill(l, m, u, ans[m]);
		fill(m + 1, r, ans[m], d);
	};

	fill(0, n, n, 0);

	for (int i = 0; i < n; ++i) {
		printf("%d\n", ans[i]);
	}

	return 0;
}