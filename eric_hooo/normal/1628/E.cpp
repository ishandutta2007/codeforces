#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

struct DSU {
	int fa[300010], rt[300010];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = rt[i] = i;
		}
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
}dsu;

struct BIT {
	int T[600010];
	BIT() {clear();}
	void clear() {memset(T, 0, sizeof(T));}
	void modify(int x, int v) {
		while (x <= 600005) T[x] += v, x += x & -x;
	}
	int query(int x) {
		int res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}
}bit;

int n, q;
vector <pip> edge;
vector <int> G[600010];
int a[600010], dep[600010], dfn[600010], sz[600010], TOT;
int fa[600010][20];
int N;

int GetLca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

void dfs(int x, int last) {
	fa[x][0] = last, dfn[x] = ++TOT, sz[x] = 1;
	for (auto v : G[x]) {
		dep[v] = dep[x] + 1, dfs(v, x), sz[x] += sz[v];
	}
}

struct Segment_tree {
	int T[1200010];
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now] = l;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		T[now] = GetLca(T[now << 1], T[now << 1 | 1]);
	}
	int Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return GetLca(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

map <pii, int> Mem;

set <pii> S;

void Modify(int op, int l, int r) {
	if (op == 1) {
		auto it = S.lower_bound(mp(l - 1, -1));
		while (it != S.end() && it->se <= r + 1) {
			int ll = it->se, rr = it->fi;
			l = min(l, ll), r = max(r, rr);
			bit.modify(dfn[Mem[mp(ll, rr)]], -1);
			it = S.erase(it);
		}
		int lca = seg.Query(1, 1, n, l, r);
		Mem[mp(l, r)] = lca, bit.modify(dfn[lca], 1);
		S.insert(mp(r, l));
	} else {
		auto it = S.lower_bound(mp(l, -1));
		vector <pii> NeedIns;
		while (it != S.end() && it->se <= r) {
			int ll = it->se, rr = it->fi;
			bit.modify(dfn[Mem[mp(ll, rr)]], -1);
			if (ll < l) NeedIns.push_back(mp(ll, l - 1));
			if (rr > r) NeedIns.push_back(mp(r + 1, rr));
			it = S.erase(it);
		}
		for (auto it : NeedIns) {
			int l = it.fi, r = it.se;
			int lca = seg.Query(1, 1, n, l, r);
			Mem[mp(l, r)] = lca, bit.modify(dfn[lca], 1);
			S.insert(mp(r, l));
		}
	}
}

int Query(int x) {
	int qwq = bit.query(N);
	if (bit.query(dfn[x] + sz[x] - 1) - bit.query(dfn[x] - 1) == qwq) return -1;
	for (int i = 19; i >= 0; i--) {
		int nx = fa[x][i];
		if (bit.query(dfn[nx] + sz[nx] - 1) - bit.query(dfn[nx] - 1) < qwq) x = nx;
	}
	return a[fa[x][0]];
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		edge.push_back(mp(w, mp(x, y)));
	}
	dsu.init(n);
	sort(edge.begin(), edge.end()), N = n;
	for (auto it : edge) {
		int w = it.fi, x = it.se.fi, y = it.se.se;
		x = dsu.find(x), y = dsu.find(y);
		int rt = ++N; a[rt] = w;
		G[rt].push_back(dsu.rt[x]), G[rt].push_back(dsu.rt[y]);
		dsu.fa[y] = x, dsu.rt[x] = rt;
	}
	dfs(N, N);
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= N; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	seg.Build(1, 1, n);
	while (q--) {
		int op, x, y; scanf("%d%d", &op, &x);
		if (op == 3) printf("%d\n", Query(x));
		else scanf("%d", &y), Modify(op, x, y);
	}
	return 0;
}