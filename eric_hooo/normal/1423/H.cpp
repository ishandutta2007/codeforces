#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define KK(x) (ch[fa[x]][0] == x ? 0 : 1)
#define isroot(x) (!fa[x] || ch[fa[x]][0] != x && ch[fa[x]][1] != x)
#define REV(x) rev[x] ^= 1, swap(ch[x][0], ch[x][1])
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;

struct LCT {
	int fa[600010], ch[600010][2], st[600010], tp, rev[600010], sz[600010], ss[600010];
	int T[600010], a[600010];
	void init() {
		memset(fa, 0, sizeof(fa)), memset(ch, 0, sizeof(ch)), memset(rev, 0, sizeof(rev));
		memset(a, 0x3f, sizeof(a)), memset(T, 0x3f, sizeof(T)), memset(ss, 0, sizeof(ss));
		for (int i = 1; i <= 600000; i++) {
			sz[i] = 1;
		}
	}
	void pushup(int x) {
		T[x] = a[x], sz[x] = ss[x] + 1;
		if (ch[x][0]) T[x] = min(T[x], T[ch[x][0]]), sz[x] += sz[ch[x][0]];
		if (ch[x][1]) T[x] = min(T[x], T[ch[x][1]]), sz[x] += sz[ch[x][1]];
	}
	void pushdown(int x) {
		if (!rev[x]) return ;
		if (ch[x][0]) REV(ch[x][0]);
		if (ch[x][1]) REV(ch[x][1]);
		rev[x] = 0;
	}
	void rotate(int x) {
		int p = fa[x], k = KK(x);
		if (!isroot(p)) ch[fa[p]][KK(p)] = x; fa[x] = fa[p], fa[p] = x;
		if (ch[x][k ^ 1]) fa[ch[x][k ^ 1]] = p; ch[p][k] = ch[x][k ^ 1];
		ch[x][k ^ 1] = p;
		pushup(p), pushup(x);
	}
	void splay(int x) {
		tp = 0, st[tp++] = x;
		int cur = x;
		while (!isroot(cur)) cur = fa[cur], st[tp++] = cur;
		while (tp--) pushdown(st[tp]);
		while (!isroot(x)) {
			int p = fa[x];
			if (!isroot(p)) rotate(KK(x) == KK(p) ? p : x);
			rotate(x);
		}
	}
	void access(int x) {
		int lst = 0;
		while (x) {
			splay(x);
			if (ch[x][1]) ss[x] += sz[ch[x][1]];
			if (lst) ss[x] -= sz[lst];
			ch[x][1] = lst, pushup(x), lst = x, x = fa[x];
		}
	}
	int findroot(int x) {
		access(x), splay(x);
		while (ch[x][0]) pushdown(x), x = ch[x][0];
		splay(x);
		return x;
	}
	void makeroot(int x) {
		access(x), splay(x), REV(x);
	}
	void link(int x, int y) {
		makeroot(x), access(y), splay(y);
		ch[y][1] = x, fa[x] = y, pushup(y);
	}
	void cut(int x, int y) {
		makeroot(x), access(y), splay(y), splay(x);
		ch[x][1] = fa[y] = 0, pushup(x);
	}
	int query(int x, int y) {
		makeroot(x), access(y), splay(y);
		return T[y];
	}
}lct;

vector <int> all[500010];
int X[500010], Y[500010], vis[500010];

int main () {
	int n, q, k; scanf("%d%d%d", &n, &q, &k);
	int T = 0; lct.init();
	for (int i = 1; i <= q; i++) {
		int op; scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d", &X[i], &Y[i]);
			if (lct.findroot(X[i]) == lct.findroot(Y[i])) {
				int id = lct.query(X[i], Y[i]);
				lct.cut(n + id, X[id]), lct.cut(n + id, Y[id]), vis[id] = 0;
			}
			lct.a[n + i] = lct.T[n + i] = i;
			lct.link(n + i, X[i]), lct.link(n + i, Y[i]), vis[i] = 1;
			all[T].push_back(i);
		} else if (op == 2) scanf("%d", &X[i]), printf("%d\n", lct.sz[lct.findroot(X[i])] / 2 + 1);
		else if (op == 3) {
			T++;
			if (T < k) continue;
			for (int i = 0; i < all[T - k].size(); i++) {
				int id = all[T - k][i];
				if (vis[id]) lct.cut(n + id, X[id]), lct.cut(n + id, Y[id]), vis[id] = 0;
			}
		}
	}
	return 0;
}