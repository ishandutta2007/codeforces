#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
int A[MAXN], B[MAXN];
vector<int> adj[MAXN];
int sz[MAXN];
int heavy[MAXN];

void dfs_sz(int n, int p) {
	sz[n] = 1;
	for (int v : adj[n]) if (v != p) {
		dfs_sz(v, n);
		sz[n] += sz[v];
		if (heavy[n] == -1 || sz[v] > sz[heavy[n]])
			heavy[n] = v;
	}
}

#define MAXLC 100013
#define INF (1LL<<60)

inline LL f(LL m, LL b, int x) {
	return m * x + b;
}

struct lc_node {
	LL m = 0, b = INF;
	lc_node *l = nullptr, *r = nullptr;

	void add_line(LL nm, LL nb, int lo=-MAXLC, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		bool bl = f(nm, nb, lo) < f(m, b, lo);
		bool bm = f(nm, nb, mid) < f(m, b, mid);
		bool bh = f(nm, nb, hi) < f(m, b, hi);
		if (bm) {
			swap(nm, m);
			swap(nb, b);
		}
		if (lo == hi || nb == INF)
			return;
		else if (bl != bm) {
			if (!l) l = new lc_node;
			l->add_line(nm, nb, lo, mid - 1);
		}
		else if (bh != bm) {
			if (!r) r = new lc_node;
			r->add_line(nm, nb, mid + 1, hi);
		}
	}

	LL get(int x, int lo=-MAXLC, int hi=MAXLC) {
		int mid = (lo + hi) / 2;
		LL ret = f(m, b, x);
		if (l && x < mid)
			ret = min(ret, l->get(x, lo, mid - 1));
		if (r && x > mid)
			ret = min(ret, r->get(x, mid + 1, hi));
		return ret;
	}
};

LL ans[MAXN];

void merge(lc_node* n, lc_node* m) {
	// n <- m
	if (!m) return;
	n->add_line(m->m, m->b);
	merge(n, m->l);
	merge(n, m->r);
	delete m;
}

lc_node* dfs(int n, int p) {
	lc_node* tree;
	if (heavy[n] == -1)
		tree = new lc_node;
	else {
		tree = dfs(heavy[n], n);
		for (int v : adj[n]) if (v != p && v != heavy[n]) {
			merge(tree, dfs(v, n));
		}
		ans[n] = tree->get(A[n]);
	}
	tree->add_line(B[n], ans[n]);
	return tree;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(heavy, -1, sizeof heavy);
	dfs_sz(0, -1);
	dfs(0, -1);

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;
	return 0;
}