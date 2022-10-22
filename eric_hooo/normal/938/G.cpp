#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;

int n, m;
int OP[200010], X[200010], Y[200010], ans[200010];

struct BASE {
	int a[40];
	vector <int> op;
	void init() {memset(a, 0, sizeof(a));}
	void insert(int x) {
		if (x == -1) {
			op.push_back(-1);
			return ;
		}
		for (int i = 29; i >= 0; i--) {
			if (x >> i & 1) {
				if (a[i]) x ^= a[i];
				else {
					a[i] = x, op.push_back(i);
					return ;
				}
			}
		}
		op.push_back(-1);
	}
	void Cancel() {
		int x = op.back(); op.pop_back();
		if (x != -1) a[x] = 0;
	}
	int Query(int x) {
		for (int i = 29; i >= 0; i--) {
			if (x >> i & 1) {
				if (a[i]) x ^= a[i];
			}
		}
		return x;
	}
}bas;

struct DSU {
	int fa[200010], wei[200010], dep[200010];
	vector <int> op;
	void init() {
		for (int i = 1; i <= n; i++) {
			fa[i] = i, wei[i] = 0, dep[i] = 0;
		}
	}
	int find(int x) {
		while (fa[x] != x) x = fa[x];
		return x;
	}
	int GetWei(int x) {
		int sum = 0;
		while (fa[x] != x) sum ^= wei[x], x = fa[x];
		return sum;
	}
	void Merge(int x, int y, int w) {
		w ^= GetWei(x) ^ GetWei(y);
		x = find(x), y = find(y);
		if (x == y) {
			op.push_back(-1);
			bas.insert(w);
			return ;
		}
		bas.insert(-1);
		if (dep[x] < dep[y]) swap(x, y);
		op.push_back(y << 1 | (dep[x] == dep[y]));
		fa[y] = x, dep[x] += dep[x] == dep[y], wei[y] = w;
	}
	void Cancel() {
		bas.Cancel();
		int t = op.back(); op.pop_back();
		if (t == -1) return ;
		int y = t >> 1, x = fa[y]; t &= 1;
		dep[x] -= t, fa[y] = y, wei[y] = 0;
	}
}dsu;

struct Segment_tree {
	vector <ppi> T[800010];
	Segment_tree() {T[1].clear();}
	void Build(int now, int l, int r) {
		if (now > 1) T[now].clear();
		if (l == r) return ;
		int mid = l + r >> 1; Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void AddEdge(int now, int l, int r, int L, int R, ppi x) {
		if (l == L && r == R) {
			T[now].push_back(x);
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) AddEdge(now << 1, l, mid, L, R, x);
		else if (L > mid) AddEdge(now << 1 | 1, mid + 1, r, L, R, x);
		else AddEdge(now << 1, l, mid, L, mid, x), AddEdge(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
	void Solve(int now, int l, int r) {
		for (auto it : T[now]) {
			dsu.Merge(it.fi.fi, it.fi.se, it.se);
		}
		if (l == r) {
			if (OP[l] == 3) {
				int x = X[l], y = Y[l], w = dsu.GetWei(x) ^ dsu.GetWei(y);
				ans[l] = bas.Query(w);
			}
		} else {
			int mid = l + r >> 1;
			Solve(now << 1, l, mid), Solve(now << 1 | 1, mid + 1, r);
		}
		for (auto it : T[now]) {
			dsu.Cancel();
		}
	}
}seg;

map <pii, pii> all;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		all[mp(x, y)] = mp(w, 1);
	}
	int q; scanf("%d", &q);
	seg.Build(1, 1, q);
	for (int i = 1; i <= q; i++) {
		int op, x, y, w; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			scanf("%d", &w);
			all[mp(x, y)] = mp(w, i);
		} else if (op == 2) {
			pii tmp = all[mp(x, y)]; all.erase(mp(x, y));
			seg.AddEdge(1, 1, q, tmp.se, i, mp(mp(x, y), tmp.fi));
		} else {
			OP[i] = 3, X[i] = x, Y[i] = y;
		}
	}
	for (auto it : all) {
		seg.AddEdge(1, 1, q, it.se.se, q, mp(it.fi, it.se.fi));
	}
	dsu.init(), bas.init();
	seg.Solve(1, 1, q);
	for (int i = 1; i <= q; i++) {
		if (OP[i] == 3) {
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}