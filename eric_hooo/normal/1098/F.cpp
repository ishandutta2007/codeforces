#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

char s[200010];
int L[200010], R[200010];
int n, q;
vector <int> from[400010];
int pos[200010];
int fa[400010], len[400010];
int dep[400010], son[400010], id[400010], sz[400010], TOT, tp[400010], seq[400010];
long long ans[200010];
vector <pii> qry[400010], mdy[400010];

struct SAM {
	int son[400010][26], TOT, lst;
	void clear() {memset(son, 0, sizeof(son)), len[1] = 0, fa[1] = 0, TOT = lst = 1;} 
	int append(int x) {
		int p = lst, np = ++TOT; len[np] = len[p] + 1;
		while (p && !son[p][x]) son[p][x] = np, p = fa[p];
		if (p) {
			int q = son[p][x];
			if (len[q] == len[p] + 1) fa[np] = q;
			else {
				int nq = ++TOT; memcpy(son[nq], son[q], sizeof(son[q])), len[nq] = len[p] + 1;
				fa[nq] = fa[q], fa[q] = fa[np] = nq;
				while (p && son[p][x] == q) son[p][x] = nq, p = fa[p];
			}
		} else fa[np] = 1;
		return lst = np;
	}
	void BuildT() {for (int i = 2; i <= TOT; i++) from[fa[i]].push_back(i);}
}sam;

void dfs1(int x, int last) {
	sz[x] = 1, son[x] = -1;
	for (auto v : from[x]) if (v != last) {
		dep[v] = dep[x] + 1, dfs1(v, x), sz[x] += sz[v];
		if (son[x] == -1 || sz[v] > sz[son[x]]) son[x] = v;
	}
}

void dfs2(int x, int t) {
	id[x] = ++TOT, seq[TOT] = x, tp[x] = t;
	if (son[x] == -1) return ;
	dfs2(son[x], t);
	for (auto v : from[x]) if (v != fa[x] && v != son[x]) dfs2(v, v);
}

void AddQry(int id) {
	int x = pos[L[id]], l = R[id] - L[id] + 1;
	while (tp[x] != 1) {
		if (len[fa[tp[x]]] < l) qry[tp[x]].push_back(mp(min(l, len[x]) - len[fa[tp[x]]], id));
		x = fa[tp[x]];
	}
	qry[tp[x]].push_back(mp(min(l, len[x]), id));
}

void AddMdy(int id) {
	int x = pos[id];
	while (tp[x] != 1) mdy[tp[x]].push_back(mp(len[x] - len[fa[tp[x]]], id)), x = fa[tp[x]];
	mdy[tp[x]].push_back(mp(len[x] - len[fa[tp[x]]], id));
}

bool cmpm(pii x, pii y) {return x.fi + x.se < y.fi + y.se;}

bool cmpq1(pii x, pii y) {return R[x.se] < R[y.se];}

bool cmpq2(pii x, pii y) {return R[x.se] - x.fi < R[y.se] - y.fi;}

struct BIT {
	long long T[200010][2];
	int vis[200010], VIS;
	BIT() {memset(vis, 0, sizeof(vis)), VIS = 2333;}
	void clear() {VIS++;}
	void Flush(int x) {if (vis[x] != VIS) vis[x] = VIS, T[x][0] = T[x][1] = 0;}
	void insert(int x, int v) {while (x <= 200005) Flush(x), T[x][0]++, T[x][1] += v, x += x & -x;}
	void erase(int x, int v) {while (x <= 200005) Flush(x), T[x][0]--, T[x][1] -= v, x += x & -x;}
	long long query0(int x) {long long res = 0; while (x) Flush(x), res += T[x][0], x -= x & -x;return res;}
	long long query1(int x) {long long res = 0; while (x) Flush(x), res += T[x][1], x -= x & -x;return res;}
}up, dw;

void Solve(int x) {
	sort(mdy[x].rbegin(), mdy[x].rend()), sort(qry[x].rbegin(), qry[x].rend());
	int pos = 0;
	up.clear(), dw.clear();
	for (auto it : mdy[x]) up.insert(it.se, it.fi);
	for (auto it : qry[x]) {
		int lim = R[it.se] + 1 - len[fa[x]];
		while (pos < mdy[x].size() && mdy[x][pos].fi >= it.fi) {
			up.erase(mdy[x][pos].se, mdy[x][pos].fi);
			dw.insert(mdy[x][pos].se, mdy[x][pos].fi);
			pos++;
		}
		int tmp = lim - it.fi;
		ans[it.se] -= up.query1(L[it.se] - 1);
		ans[it.se] -= dw.query0(L[it.se] - 1) * it.fi;
		int old = ans[it.se];
		ans[it.se] -= it.fi * up.query0(tmp) - up.query1(tmp);
	}
	sort(mdy[x].begin(), mdy[x].end(), cmpm);
	sort(qry[x].begin(), qry[x].end(), cmpq1);
	up.clear(), dw.clear(), pos = 0;
	for (auto it : mdy[x]) up.insert(it.se, it.se);
	for (auto it : qry[x]) {
		int lim = R[it.se] + 1 - len[fa[x]];
		while (pos < mdy[x].size() && mdy[x][pos].fi + mdy[x][pos].se <= lim) {
			up.erase(mdy[x][pos].se, mdy[x][pos].se);
			dw.insert(mdy[x][pos].se, mdy[x][pos].fi);
			pos++;
		}
		ans[it.se] += lim * up.query0(lim) - up.query1(lim);
		ans[it.se] += dw.query1(lim);
		int tmp = lim - it.fi;
		ans[it.se] -= tmp * up.query0(tmp) - up.query1(tmp);
		ans[it.se] -= dw.query1(tmp) - dw.query0(tmp) * it.fi;
	}
}

int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	sam.clear();
	for (int i = n; i >= 1; i--) pos[i] = sam.append(s[i] - 'a');
	sam.BuildT(), dfs1(1, 1), dfs2(1, 1);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) scanf("%d%d", &L[i], &R[i]), AddQry(i);
	for (int i = 1; i <= n; i++) AddMdy(i);
	for (int i = 1; i <= TOT; i++) if (tp[i] == i) Solve(i);
	for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
	return 0;
}