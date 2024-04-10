#include <bits/stdc++.h>
using namespace std;

#define DD(x) (ch[fa[(x)]][1] == (x))

int n, m;
int fa[200010], ch[200010][2];
int dep[200010], tag[200010], maxj[200010], minj[200010];

void init(int x, int d) {
	fa[x] = ch[x][0] = ch[x][1] = tag[x] = 0, dep[x] = maxj[x] = minj[x] = d;
}

void pushup(int x) {
	maxj[x] = minj[x] = dep[x];
	if (ch[x][0]) maxj[x] = max(maxj[x], maxj[ch[x][0]]), minj[x] = min(minj[x], minj[ch[x][0]]);
	if (ch[x][1]) maxj[x] = max(maxj[x], maxj[ch[x][1]]), minj[x] = min(minj[x], minj[ch[x][1]]);
}

void addtag(int x, int t) {
	dep[x] += t, tag[x] += t, minj[x] += t, maxj[x] += t;
}

void pushdown(int x) {
	if (!tag[x]) return ;
	if (ch[x][0]) addtag(ch[x][0], tag[x]);
	if (ch[x][1]) addtag(ch[x][1], tag[x]);
	tag[x] = 0;
}

void rotate(int x) {
	int p = fa[x], d = DD(x), t = ch[x][d ^ 1];
	ch[p][d] = t, ch[x][d ^ 1] = p;
	if (fa[p]) ch[fa[p]][DD(p)] = x;
	fa[x] = fa[p], fa[p] = x;
	if (t) fa[t] = p;
	pushup(p);
}

int st[200010];

void splay(int x) {
	int tp = 0, cur = x;
	while (cur) st[tp++] = cur, cur = fa[cur];
	while (tp--) pushdown(st[tp]);
	while (fa[x]) {
		int p = fa[x];
		if (fa[p]) rotate(DD(p) == DD(x) ? p : x);
		rotate(x);
	}
	pushup(x);
}

int Merge(int x, int y) {
	if (!x || !y) return x | y;
	splay(x), splay(y);
	while (ch[x][1]) x = ch[x][1];
	splay(x), ch[x][1] = y, fa[y] = x, pushup(x);
	return x;
}

int GetLst(int x, int d) {
	pushdown(x);
	if (ch[x][1] && minj[ch[x][1]] <= d && d <= maxj[ch[x][1]]) return GetLst(ch[x][1], d);
	if (dep[x] == d) return x;
	return GetLst(ch[x][0], d);
}

bool cmp(int x, int y) {
	if (x == y) return 0;
	splay(x);
	int cur = y;
	while (fa[cur] != x) cur = fa[cur];
	int ans = DD(cur);
	splay(y);
	return ans;
}

int Dep(int x) {splay(x); return dep[x];}

int Minj(int l, int r) {
	splay(l);
	int ans = dep[l];
	fa[ch[l][1]] = 0, ch[l][1] = 0, pushup(l);
	splay(r);
	ans = min(ans, dep[r]);
	if (ch[r][0]) ans = min(ans, minj[ch[r][0]]);
	ch[l][1] = r, fa[r] = l, pushup(l);
	return ans;
}

vector <int> G[100010];
vector <int> seq;

void GetSeq(int x, int d) {
	seq.push_back(x << 1), init(x << 1, d);
	for (auto v : G[x]) {
		GetSeq(v, d + 1);
	}
	seq.push_back(x << 1 | 1), init(x << 1 | 1, d);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		while (k--) {
			int x; scanf("%d", &x);
			G[i].push_back(x);
		}
	}
	GetSeq(1, 0);
	for (int i = 1; i < seq.size(); i++) {
		ch[seq[i - 1]][1] = seq[i], fa[seq[i]] = seq[i - 1];
	}
	splay(seq.back());
	for (int turn = 0; turn < m; turn++) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int x, y; scanf("%d%d", &x, &y);
			if (cmp(y << 1, x << 1)) swap(x, y);
			if (cmp(y << 1, x << 1 | 1)) printf("%d\n", Dep(y << 1) - Dep(x << 1));
			else printf("%d\n", Dep(x << 1) + Dep(y << 1) - 2 * (Minj(x << 1, y << 1) - 1));
		} else if (op == 2) {
			int x, h; scanf("%d%d", &x, &h);
			int xl = x << 1, xr = x << 1 | 1;
			splay(xl);
			int lef = ch[xl][0]; fa[lef] = ch[xl][0] = 0, pushup(xl);
			splay(xr);
			int rig = ch[xr][1]; fa[rig] = ch[xr][1] = 0, pushup(xr);
			addtag(xr, -h + 1);
			int par = GetLst(lef, Dep(xr) - 1); splay(par), lef = par, par ^= 1;
			splay(par), rig = ch[par][0], fa[rig] = ch[par][0] = 0, pushup(par);
			lef = Merge(lef, rig);
			lef = Merge(lef, xr);
			lef = Merge(lef, par);
		} else {
			int k; scanf("%d", &k);
			splay(2);
			int x = GetLst(2, k);
			splay(x);
			printf("%d\n", x >> 1);
		}
	}
	return 0;
}