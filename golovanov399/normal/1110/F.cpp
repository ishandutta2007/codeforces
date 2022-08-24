#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const long long inf = LLONG_MAX / 10;

struct SegTree {
	int n;
	vector<long long> a;
	vector<long long> to_add;

	SegTree(const vector<long long>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.assign(n + n, inf);
		to_add.assign(n + n, 0);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = ar[i];
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = min(a[i + i], a[i + i + 1]);
		}
	}

	void push(int v) {
		if (v >= n) {
			return;
		}

		for (int x : {v + v, v + v + 1}) {
			to_add[x] += to_add[v];
			a[x] += to_add[v];
		}
		to_add[v] = 0;
	}

	long long get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return inf;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		push(v);
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	long long get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void add(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v] += x;
			to_add[v] += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = min(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, long long x) {
		add(1, 0, n, l, r, x);
	}
};

struct Edge {
	int to;
	long long w;
};

const int N = 511111;
vector<Edge> a[N];
int tin[N], tout[N];
long long level[N];
vector<int> order;

void dfs(int v) {
	tin[v] = order.size();
	order.push_back(v);
	for (auto e : a[v]) {
		level[e.to] = level[v] + e.w;
		dfs(e.to);
	}
	tout[v] = order.size();
}

vector<int> qrs[N];
long long ans[N];
vector<array<int, 3>> queries;

void dfsAns(int v, SegTree& tree) {
	for (auto i : qrs[v]) {
		ans[i] = tree.get(queries[i][1], queries[i][2]);
	}
	for (auto e : a[v]) {
		tree.add(0, order.size(), e.w);
		tree.add(tin[e.to], tout[e.to], -2 * e.w);
		dfsAns(e.to, tree);
		tree.add(0, order.size(), -e.w);
		tree.add(tin[e.to], tout[e.to], 2 * e.w);
	}
}

int main() {
	int n = nxt(), q = nxt();
	for (int i = 1; i < n; ++i) {
		int u = nxt() - 1, x = nxt();
		a[u].push_back({i, x});
	}

	dfs(0);
	vector<long long> levels(n, inf);
	for (int i = 0; i < n; ++i) {
		if (a[i].empty()) {
			levels[tin[i]] = level[i];
		}
	}

	SegTree tree(levels);
	for (int i = 0; i < q; ++i) {
		int v = order[nxt() - 1], l = nxt() - 1, r = nxt();
		queries.push_back({v, l, r});
		qrs[v].push_back(i);
	}

	dfsAns(0, tree);

	for (int i = 0; i < q; ++i) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}