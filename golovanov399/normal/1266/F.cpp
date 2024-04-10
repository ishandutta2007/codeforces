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

const int N = 555555;
vector<int> a[N];
vector<int> depth[N];
int par_idx[N];

int dfsDown(int v, int p = -1) {
	int res = 0;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			par_idx[v] = i;
			continue;
		}
		int x = dfsDown(a[v][i], v);
		res = max(res, x + 1);
		depth[v][i] = x;
	}
	return res;
}

void dfsUp(int v, int up = 0, int p = -1) {
	vector<int> pref_max(a[v].size(), 0);
	vector<int> suf_max(a[v].size(), 0);
	for (int i = 0; i < (int)a[v].size() - 1; ++i) {
		pref_max[i + 1] = max(pref_max[i], a[v][i] == p ? 0 : (1 + depth[v][i]));
	}
	for (int i = (int)a[v].size() - 1; i > 0; --i) {
		suf_max[i - 1] = max(suf_max[i], a[v][i] == p ? 0 : (1 + depth[v][i]));
	}
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			continue;
		}
		int x = depth[a[v][i]][par_idx[a[v][i]]] = max({up, pref_max[i], suf_max[i]});
		dfsUp(a[v][i], x + 1, v);
	}
}

struct Node {
	int val;
	int add;
};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
	}

	void push(int v) {
		for (int t : {0, 1}) {
			a[2 * v + t].val += a[v].add;
			a[2 * v + t].add += a[v].add;
		}
		a[v].add = 0;
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].val += x;
			a[v].add += x;
			return;
		}
		int mid = (l1 + r1) / 2;
		push(v);
		add(v + v, l1, mid, l, r, x);
		add(v + v + 1, mid, r1, l, r, x);
		a[v].val = max(a[v + v].val, a[v + v + 1].val);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	int get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return a[v].val;
		}
		int mid = (l1 + r1) / 2;
		push(v);
		return max(get(v + v, l1, mid, l, r), get(v + v + 1, mid, r1, l, r));
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		depth[i].resize(a[i].size());
	}
	memset(par_idx, -1, sizeof(par_idx));
	dfsDown(0);
	dfsUp(0);

	vector<int> ans(n, 1);
	for (int i = 0; i < n; ++i) {
		ans[0] = max(ans[0], 1 + (int)a[i].size());
	}
	int diam = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			diam = max(diam, depth[i][j] + 1);
		}
	}
	for (int i = 0; i < diam; ++i) {
		ans[i] = max(ans[i], 2);
	}

	SegTree verts_tree(n);
	SegTree edges_tree(n - 1);

	vector<int> led(n, -1), red(n, -1), ped(n, -1);
	{
		int cur = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i = 0; i < (int)a[v].size(); ++i) {
				if (i == par_idx[v]) {
					continue;
				}
				if (led[v] == -1) {
					led[v] = cur;
				}
				red[v] = cur + 1;
				ped[a[v][i]] = cur;
				q.push(a[v][i]);
				++cur;
			}
		}
	}

	vector<array<int, 3>> eds;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			eds.push_back({{depth[i][j], i, a[i][j]}});
		}
	}
	sort(all(eds));

	// for (int i = 0; i < n; ++i) {
	// 	cerr << ped[i] << " " << led[i] << " " << red[i] << "\n";
	// }

	for (int x = diam / 2; x > 0; --x) {
		while (!eds.empty() && eds.back()[0] >= x - 1) {
			// cerr << "depth[" << eds.back()[1] + 1 << "][" << eds.back()[2] + 1 << "] is at least " << x - 1 << "\n";
			int u = eds.back()[1];
			eds.pop_back();
			verts_tree.add(u, u + 1, 1);
			if (ped[u] > -1) {
				edges_tree.add(ped[u], ped[u] + 1, 1);
			}
			edges_tree.add(led[u], red[u], 1);
		}
		auto val = verts_tree.get(0, n);
		if (val >= 3) {
			if (2 * x <= n) {
				ans[2 * x - 1] = max(ans[2 * x - 1], val);
			}
			if (2 * x - 1 <= n) {
				ans[2 * x - 2] = max(ans[2 * x - 2], val);
			}
		}
		if (2 * x <= n) {
			ans[2 * x - 1] = max(ans[2 * x - 1], edges_tree.get(0, n - 1) - 2);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++i) {
			ans[1] = max(ans[1], (int)a[i].size() + (int)a[a[i][j]].size() - 2);
		}
	}
	for (int i = 0; i < n; ++i) {
		vector<int> depths = depth[i];
		sort(all(depths));
		int r = 0;
		for (int j = 0; j < (int)depths.size(); ++j) {
			while (r < (int)depths.size() && depths[r] <= depths[j]) {
				++r;
			}
			int x = depths[j] + 2;
			if (2 * x - 1 <= n && r < (int)depths.size()) {
				ans[2 * x - 2] = max(ans[2 * x - 2], 1 + (int)depths.size() - r);
			}
		}
	}

	for (auto x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}