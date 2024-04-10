#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Vertex {
	int level;
	int val;

	Vertex() {}
	Vertex(int l, int v): level(l), val(v) {}

	bool operator <(const Vertex& ot) const {
		return level < ot.level;
	}
};

const int INF = 1e9 + 10;

struct SegTree {
	int n;
	vector<vector<Vertex>> a;
	vector<vector<int>> res;

	SegTree(const vector<int>& level, const vector<int>& vals) {
		n = 1;
		while (n < (int)level.size()) {
			n *= 2;
		}
		a.resize(n + n);
		res.resize(n + n);
		for (int i = 0; i < (int)level.size(); ++i) {
			a[n + i] = {{level[i], vals[i]}};
			res[n + i] = {INF, vals[i]};
		}
		for (int i = n - 1; i > 0; --i) {
			a[i].resize(a[i + i].size() + a[i + i + 1].size());
			merge(all(a[i + i]), all(a[i + i + 1]), a[i].begin());
			res[i].resize(a[i].size() + 1, INF);
			for (int j = 0; j < (int)a[i].size(); ++j) {
				res[i][j + 1] = min(res[i][j], a[i][j].val);
			}
		}
	}

	int _get(int v, int l1, int r1, int l, int r, int maxk) {
		if (l >= r1 || l1 >= r) {
			return INF;
		}
		if (l <= l1 && r >= r1) {
			int idx = lower_bound(all(a[v]), Vertex(maxk + 1, 0)) - a[v].begin();
			return res[v][idx];
		}
		int mid = (l1 + r1) / 2;
		return min(_get(v + v, l1, mid, l, r, maxk),
				   _get(v + v + 1, mid, r1, l, r, maxk));
	}

	int get(int l, int r, int maxk) {
		return _get(1, 0, n, l, r, maxk);
	}
};

const int N = 111111;
int tin[N], tout[N], level[N];
int timer = 0;
vector<int> a[N];
int val[N];
vector<int> levels, vals;

void dfs(int v, int p = -1) {
	tin[v] = timer++;
	levels.push_back(level[v]);
	vals.push_back(val[v]);
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		level[x] = level[v] + 1;
		dfs(x, v);
	}
	tout[v] = timer;
}

int main() {
	int n = nxt(), root = nxt() - 1;
	for (int i = 0; i < n; ++i) {
		val[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(root);

	SegTree tree(levels, vals);
	int q = nxt();
	int last = 0;
	while (q--) {
		int p1 = nxt(), p2 = nxt();
		int x = (p1 + last) % n;
		int k = (p2 + last) % n;

		last = tree.get(tin[x], tout[x], level[x] + k);
		printf("%d\n", last);
	}

	return 0;
}