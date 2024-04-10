#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

struct UF {
	int fa[100010], dep[100010], sz[100010];
	int tot;
	vector <int> op;
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i, dep[i] = 0, sz[i] = 1;
		}
		tot = n;
		op.clear();
	}
	int find(int x) {return fa[x] == x ? x : find(fa[x]);}
	int merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return 0;
		if (dep[x] > dep[y]) swap(x, y);
		op.push_back(x << 1 | (dep[x] == dep[y]));
		if (sz[x] & 1) tot--;
		if (sz[y] & 1) tot--;
		fa[x] = y, dep[y] += dep[x] == dep[y], sz[y] += sz[x];
		if (sz[y] & 1) tot++;
		return 1;
	}
	void cancel() {
		int x = op.back() >> 1, d = op.back() & 1; op.pop_back();
		int y = fa[x];
		if (sz[y] & 1) tot--;
		dep[y] -= d, sz[y] -= sz[x];
		if (sz[y] & 1) tot++;
		if (sz[x] & 1) tot++;
		fa[x] = x;
	}
}uf;

pii a[300010], b[300010];
int p[300010], q[300010], W[300010];
int ans[300010]; 

void solve(int l, int r, int L, int R) {
	if (l > r) return ;
	int mid = l + r >> 1;
	int T = 0;
	for (int i = l; i <= mid; i++) {
		if (p[i] < L) T += uf.merge(a[i].fi, a[i].se);
	}
	int pos = -1;
	for (int i = L; i <= R; i++) {
		if (q[i] <= mid) T += uf.merge(b[i].fi, b[i].se);
		if (!uf.tot) {
			pos = i;
			goto END;
		}
	}
	END:;
	if (pos == -1) {
		for (int i = l; i <= mid; i++) {
			ans[i] = -1;
		}
		while (T) uf.cancel(), T--;
		for (int i = l; i <= mid; i++) {
			if (p[i] < L) T += uf.merge(a[i].fi, a[i].se);
		}
		solve(mid + 1, r, L, R);
		while (T) uf.cancel(), T--;
		return ;
	}
	ans[mid] = pos;
	while (T) uf.cancel(), T--;
	for (int i = L; i < pos; i++) {
		if (q[i] < l) T += uf.merge(b[i].fi, b[i].se);
	}
	solve(l, mid - 1, pos, R);
	while (T) uf.cancel(), T--;
	for (int i = l; i <= mid; i++) {
		if (p[i] < L) T += uf.merge(a[i].fi, a[i].se);
	}
	solve(mid + 1, r, L, pos);
	while (T) uf.cancel(), T--;
}

bool cmp(int x, int y) {
	return W[x] < W[y];
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].fi, &a[i].se, &W[i]);
		q[i] = i;
	}
	sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		b[i] = a[q[i]];
		p[q[i]] = i; 
	}
	uf.init(n);
	solve(1, m, 1, m);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i] == -1 ? -1 : W[q[ans[i]]]);
	}
	return 0;
}