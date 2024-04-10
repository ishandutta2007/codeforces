#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

struct UF {
	int fa[100010], dep[100010], tg[100010];
	vector <int> OP;
	int n, path;
	void init(int n) {
		for (int i = 0; i <= n; i++) {
			fa[i] = i, dep[i] = 0, tg[i] = 0;
		}
		OP.clear();
	}
	int find(int x) {return x == fa[x] ? x : (path ^= tg[x], find(fa[x]));}
	bool merge(int x, int y) {
		path = 1;
		x = find(x), y = find(y);
		if (x == y && path) return 0;
		if (dep[x] > dep[y]) swap(x, y);
		OP.push_back(x << 1 | (dep[x] == dep[y]));
		fa[x] = y, dep[y] += dep[x] == dep[y], tg[x] = path;
		return 1;
	}
	void cancel() {
		int x = OP.back() >> 1, y = fa[x];
		fa[x] = x, dep[y] -= OP.back() & 1, tg[x] = 0;
		OP.pop_back();
	}
}uf;

int ans[100010];
int X[100010], Y[100010];

struct Segment_tree {
	vector <int> T[400010];
	void Add_edge(int now, int l, int r, int L, int R, int x) {
		if (l == L && r == R) {
			T[now].push_back(x);
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Add_edge(now << 1, l, mid, L, R, x);
		else if (L > mid) Add_edge(now << 1 | 1, mid + 1, r, L, R, x);
		else Add_edge(now << 1, l, mid, L, mid, x), Add_edge(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
	void solve(int now, int l, int r) {
		int real = 0;
		for (int i = 0; i < T[now].size(); i++) {
			int x = X[T[now][i]], y = Y[T[now][i]];
			if (!uf.merge(x, y)) {
				while (real--) uf.cancel();
				return ;
			}
			real++;
		}
		if (l == r) ans[l] = 1;
		else {
			int mid = l + r >> 1;
			solve(now << 1, l, mid), solve(now << 1 | 1, mid + 1, r);
		}
		while (real--) uf.cancel();
	}
	void get_ans(int n, int q) {
		uf.init(n);
		solve(1, 1, q);
	}
}seg;

map <pii, int> lst;

int main () {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		if (lst.count(mp(X[i], Y[i]))) {
			int x = lst[mp(X[i], Y[i])];
			seg.Add_edge(1, 1, q, x, i - 1, x);
			lst.erase(mp(X[i], Y[i]));
		} else lst[mp(X[i], Y[i])] = i;
	}
	for (map <pii, int> :: iterator it = lst.begin(); it != lst.end(); it++) {
		seg.Add_edge(1, 1, q, it->se, q, it->se);
	}
	seg.get_ans(n, q);
	for (int i = 1; i <= q; i++) {
		printf(ans[i] ? "YES\n" : "NO\n");
	}
	return 0;
}