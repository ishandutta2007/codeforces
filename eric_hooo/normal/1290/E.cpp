#include <bits/stdc++.h>
#define DD(x) ((x) == ch[fa[x]][1])
#define isroot(x) (ch[fa[x]][0] != (x) && ch[fa[x]][1] != (x))
using namespace std;

int a[200010], p[200010];
long long ans[200010];
set <int> S;

struct LCT {
	int ch[200010][2], fa[200010];
	int val[200010], sz[200010], ss[200010], sss[200010];
	long long sum[200010], ssum[200010];
	LCT() {
		memset(ch, 0, sizeof(ch)), memset(fa, 0, sizeof(fa)), memset(sz, 0, sizeof(sz));
		memset(sss, 0, sizeof(sss)), memset(ss, 0, sizeof(ss)), memset(sum, 0, sizeof(sum));
		memset(ssum, 0, sizeof(ssum));
	}
	void pushup(int x) {
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
		ss[x] = ss[ch[x][0]] + ss[ch[x][1]] + sss[x] + 1;
		sum[x] = ssum[x] + sum[ch[x][0]] + sum[ch[x][1]];
		sum[x] += 1ll * (sz[ch[x][0]] + 1) * (ss[ch[x][1]] + sss[x] + 1);
	}
	void rotate(int x) {
		int p = fa[x], d = DD(x);
		ch[p][d] = ch[x][d ^ 1], fa[ch[x][d ^ 1]] = p;
		if (!isroot(p)) ch[fa[p]][DD(p)] = x; fa[x] = fa[p];
		ch[x][d ^ 1] = p, fa[p] = x;
		pushup(p), pushup(x);
	}
	void splay(int x) {
		while (!isroot(x)) {
			int p = fa[x];
			if (!isroot(p)) rotate(DD(x) == DD(p) ? p : x);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x) {
		int lst = 0;
		while (x) {
			splay(x);
			sss[x] += ss[ch[x][1]] - ss[lst], ssum[x] += sum[ch[x][1]] - sum[lst];
			ch[x][1] = lst, pushup(x);
			lst = x, x = fa[x];
		}
	}
	int Insert(int x, int y) {
		while (1) {
			int to = y > x ? 0 : 1;
			if (!ch[x][to]) {
				ch[x][to] = y, fa[y] = x, pushup(x);
				while (!isroot(x)) x = fa[x], pushup(x);
				break;
			}
			x = ch[x][to];
		}
		splay(y);
		return y;
	}
	int Merge(int x, int y) {
		if (!y) return x;
		int ls = ch[y][0], rs = ch[y][1];
		fa[ls] = fa[rs] = 0, ch[y][0] = ch[y][1] = 0, pushup(y);
		x = Insert(x, y), x = Merge(x, ls), x = Merge(x, rs);
		return x;
	}
}lct;

struct RMQ {
	int a[200010], f[200010][18], lg[200010];
	int MAX(int x, int y) {return a[x] < a[y] ? y : x;}
	void init(int *A, int n) {
		lg[0] = -1;
		for (int i = 1; i <= n; i++) {
			f[i][0] = i, a[i] = A[i], lg[i] = lg[i >> 1] + 1;
		}
		for (int j = 1; j < 18; j++) {
			for (int i = 1; i <= n; i++) {
				if (i + (1 << j) - 1 > n) break;
				f[i][j] = MAX(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	int get_max(int l, int r) {
		int k = lg[r - l + 1];
		return MAX(f[l][k], f[r - (1 << k) + 1][k]);
	}
}rmq;

int Build(int l, int r) {
	if (l > r) return 0;
	int mid = rmq.get_max(l, r), x = a[mid];
	int ls = Build(l, mid - 1), rs = Build(mid + 1, r);
	lct.fa[ls] = x, lct.fa[rs] = x;
	lct.sss[x] = r - l, lct.ssum[x] = lct.sum[ls] + lct.sum[rs];
	lct.pushup(x);
	return x;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
		S.insert(i);
	}
	rmq.init(a, n);
	Build(1, n);
	ans[n] = lct.sum[n];
	for (int i = n; i >= 2; i--) {
		S.erase(p[i]);
		set <int> :: iterator it = S.lower_bound(p[i]);
		int suc = it == S.end() ? 0 : a[*it], pre = it == S.begin() ? 0 : a[*(--it)];
		if (pre) lct.access(pre), lct.splay(pre), lct.splay(i), lct.fa[lct.ch[i][1]] = 0, lct.splay(pre);
		if (suc) lct.access(suc), lct.splay(suc), lct.splay(i), lct.fa[lct.ch[i][1]] = 0, lct.splay(suc);
		if (lct.sz[pre] < lct.sz[suc]) swap(pre, suc);
		lct.Merge(pre, suc);
		lct.splay(i - 1), ans[i - 1] = lct.sum[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}