#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int n;
vector <int> g[MAXN];

void read() {
	cin >> n;
 	for (int i = 0; i < n - 1; ++i) {
 	 	int u, v;
 	 	cin >> u >> v;
 	 	--u; --v;
 	 	g[u].push_back(v);
 	 	g[v].push_back(u);
 	}
}

struct Node {
	int x;
	Node *l, *r;

	Node (int x_) {
	  	x = x_;
	  	l = r = NULL;
	}

	~Node () {
	 	if (l) delete l;
	 	if (r) delete r;
	}
};

void push(Node *t) {
	if (!t->l) t->l = new Node(0);
	if (!t->r) t->r = new Node(0);
}

void relax(Node *t) {
	t->x = max(t->l->x, t->r->x);
}

Node *add(Node *t, int tl, int tr, int p) {
 	if (tl == tr) {
 		++t->x;
 		return t;
 	}	
 	int tm = (tl + tr) / 2;
 	push(t);
 	if (p <= tm) t->l = add(t->l, tl, tm, p);
 	else t->r = add(t->r, tm + 1, tr, p);
 	relax(t);
 	return t;
}

int get(Node *t, int tl, int tr) {
	if (tl == tr) return tl;
	int tm = (tl + tr) / 2;
	push(t);
	if (t->l->x == t->x) return get(t->l, tl, tm);
	else return get(t->r, tm + 1, tr);
}

Node *t[MAXN];
vector <int> d[MAXN];

int ans[MAXN], cnt[MAXN], h[MAXN];

void dfs(int u, int parent, int depth) {
	h[u] = depth;
	cnt[u] = 1;
	int mx = -1;
	for (int v : g[u]) {
	 	if (v == parent) continue;
	 	dfs(v, u, depth + 1);
		cnt[u] += cnt[v];
		if (mx == -1 || cnt[mx] < cnt[v]) mx = v;
	}

	if (mx != -1) {
		swap(d[u], d[mx]);
		swap(t[u], t[mx]);
	}
	else {
	 	t[u] = new Node(0);
	}
	
	d[u].push_back(h[u]);
	//cout << u + 1 << " add " << h[u] << '\n';
	t[u] = add(t[u], 0, MAXN, h[u]);

	for (int v : g[u]) {
	 	if (v == parent) continue;
	 	if (v == mx) continue;
	 	for (int nh : d[v]) {
	 	 	d[u].push_back(nh);
	 	 	t[u] = add(t[u], 0, MAXN, nh);
	 	 	//cout << u + 1 << " add " << nh << '\n';
	 	}
	}

	ans[u] = get(t[u], 0, MAXN) - h[u];

	for (int v : g[u]) {
	 	if (v == parent) continue;
	 	delete t[v];
	}
}

void solve() {
	dfs(0, 0, 0);
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
	cout << '\n';			
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	read();
	solve();

    return 0;
}