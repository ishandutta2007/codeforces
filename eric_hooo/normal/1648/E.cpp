#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

int n, m;
vector <pip> edge;
vector <int> G[200010];

struct KKK {
	vector <int> G[400010];
	int val[400010], N;
	int fa[200010], rt[200010];
	int dfn[200010], lef[400010], rig[400010], TOT;
	int st[400010][19];
	int dep[400010], num[200010];
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void dfs(int x, int last) {
		st[x][0] = last;
		if (x <= n) lef[x] = rig[x] = dfn[x] = ++TOT, num[TOT] = x;
		else lef[x] = 0x3f3f3f3f, rig[x] = -1;
		for (auto v : G[x]) {
			dep[v] = dep[x] + 1, dfs(v, x), lef[x] = min(lef[x], lef[v]), rig[x] = max(rig[x], rig[v]);
		}
	}
	int GetLca(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		int tmp = dep[x] - dep[y], cnt = 0;
		while (tmp) {
			if (tmp & 1) x = st[x][cnt];
			tmp >>= 1, cnt++;
		}
		if (x == y) return x;
		for (int i = 18; i >= 0; i--) {
			if (st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
		}
		return st[x][0];
	}
	void Build(vector <pip> edge = :: edge) {
		// cerr << "                                          edge:"; for (auto it : edge) cerr << "  " << it.fi << " : " << it.se.fi << " " << it.se.se; cerr << endl;
		N = n, TOT = 0;
		for (int i = 1; i <= n; i++) {
			fa[i] = i, rt[i] = i, G[i].clear();
		}
		for (auto it : edge) {
			int w = it.fi, x = it.se.fi, y = it.se.se;
			x = find(x), y = find(y);
			if (x == y) continue;
			val[++N] = w, G[N].clear(), G[N].push_back(rt[x]), G[N].push_back(rt[y]);
			fa[y] = x, rt[x] = N;
		}
		dep[N] = 0, dfs(N, N);
		for (int j = 1; j < 19; j++) {
			for (int i = 1; i <= N; i++) {
				st[i][j] = st[st[i][j - 1]][j - 1];
			}
		}
	}
}K, KK;

namespace B {
	int fa[200010];
	struct Segment_tree {
		pii T[1 << 19];
		void pushup(int now) {
			T[now] = max(T[now << 1], T[now << 1 | 1]);
		}
		void Build(int now, int l, int r) {
			if (l == r) {
				T[now] = mp(1, l);
				return ;
			}
			int mid = l + r >> 1;
			Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
			pushup(now);
		}
		void Update(int now, int l, int r, int pos, int x) {
			if (l == r) {
				T[now].fi += x;
				return ;
			}
			int mid = l + r >> 1;
			if (pos <= mid) Update(now << 1, l, mid, pos, x);
			else Update(now << 1 | 1, mid + 1, r, pos, x);
			pushup(now);
		}
		int FindSuc(int now, int l, int r, int L, int R) {
			if (T[now].fi < 1) return 0;
			if (l == r) return l;
			int mid = l + r >> 1;
			if (R <= mid) return FindSuc(now << 1, l, mid, L, R);
			if (L > mid) return FindSuc(now << 1 | 1, mid + 1, r, L, R);
			int tmp = FindSuc(now << 1 | 1, mid + 1, r, mid + 1, R);
			return tmp ? tmp : FindSuc(now << 1, l, mid, L, mid);
		}
		int FindPre(int now, int l, int r, int L, int R) {
			if (T[now].fi < 1) return 0;
			if (l == r) return l;
			int mid = l + r >> 1;
			if (R <= mid) return FindPre(now << 1, l, mid, L, R);
			if (L > mid) return FindPre(now << 1 | 1, mid + 1, r, L, R);
			int tmp = FindPre(now << 1, l, mid, L, mid);
			return tmp ? tmp : FindPre(now << 1 | 1, mid + 1, r, mid + 1, R);
		}
	}seg;
	vector <int> node[200010];
	vector <pip> edge;
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	int ban[200010];
	pip Calc(vector <int> node) {
		// cerr << " node:"; for (auto it : node) cerr << " " << it; cerr << endl;
		for (auto x : node) {
			if (!ban[K.dfn[x]]) seg.Update(1, 1, n, K.dfn[x], -1);
			ban[K.dfn[x]]++;
			// cerr << "          G:" << :: G[x].size() << endl;
		}
		pip edge = mp(0x3f3f3f3f, mp(-1, -1));
		for (auto x : node) {
			for (auto v : :: G[x]) {
				// cerr << "                                     v:" << v << endl;
				if (!ban[K.dfn[v]])	seg.Update(1, 1, n, K.dfn[v], -1);
				ban[K.dfn[v]]++;
			}
			int pre = seg.FindSuc(1, 1, n, 1, K.dfn[x]), suc = seg.FindPre(1, 1, n, K.dfn[x], n);
			pre = K.num[pre], suc = K.num[suc];
			// cerr << "         pre:" << x << " : " << pre << " " << suc << endl;
			if (pre) edge = min(edge, mp(K.val[K.GetLca(pre, x)], mp(pre, x)));
			if (suc) edge = min(edge, mp(K.val[K.GetLca(x, suc)], mp(x, suc)));
			for (auto v : :: G[x]) {
				ban[K.dfn[v]]--;
				if (!ban[K.dfn[v]]) seg.Update(1, 1, n, K.dfn[v], 1);
			}
		}
		for (auto x : node) {
			ban[K.dfn[x]]--;
			if (!ban[K.dfn[x]]) seg.Update(1, 1, n, K.dfn[x], 1);
		}
		return edge;
	}
	vector <pip> my;
	void Solve() {
		int tot = n;
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
		seg.Build(1, 1, n);
		my.clear();
		while (tot > 1) {
			for (int i = 1; i <= n; i++) {
				node[i].clear();
			}
			for (int i = 1; i <= n; i++) {
				node[find(i)].push_back(i);
			}
			edge.clear();
			for (int i = 1; i <= n; i++) {
				if (!node[i].size()) continue;
				edge.push_back(Calc(node[i]));
			}
			for (auto it : edge) {
				int w = it.fi, x = it.se.fi, y = it.se.se;
				if (find(x) == find(y)) continue;
				tot--;
				fa[find(x)] = find(y);
				my.push_back(mp(w, mp(x, y)));
			}
		}
		sort(my.begin(), my.end());
		KK.Build(my);
	}
}

int X[200010], Y[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		edge.clear();
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y, w; scanf("%d%d%d", &x, &y, &w);
			X[i] = x, Y[i] = y;
			G[x].push_back(y);
			G[y].push_back(x);
			edge.push_back(mp(w, mp(x, y)));
		}
		sort(edge.begin(), edge.end());
		K.Build();
		// cerr << "         POS" << endl;
		B :: Solve();
		for (int i = 0; i < m; i++) {
			printf("%d ", KK.val[KK.GetLca(X[i], Y[i])]);
		}
		printf("\n");
	}
	return 0;
}