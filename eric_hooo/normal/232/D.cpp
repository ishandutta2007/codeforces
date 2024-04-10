#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

namespace BIT {
	int T[100010];
	void Modify(int x, int v) {
		while (x <= 100005) T[x] += v, x += x & -x;
	}
	int Query(int x) {
		int res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}
	int Query(int l, int r) {
		if (l > r) return 0;
		return Query(r) - Query(l - 1);
	}
}

int n, q;
int a[100010];
int L[100010], R[100010], ans[100010], X[100010];
vector <pii> mdy;
vector <pii> qry;

namespace SAM {
	map <int, int> son[400010];
	int fa[400010], len[400010], TOT, lst;
	void Init() {TOT = 0, lst = ++TOT;}
	int Append(int x) {
		int p = lst, np = ++TOT; lst = np, len[np] = len[p] + 1;
		while (p && !son[p].count(x)) son[p][x] = np, p = fa[p];
		if (p) {
			int q = son[p][x];
			if (len[q] == len[p] + 1) fa[np] = q;
			else {
				int nq = ++TOT; son[nq] = son[q], len[nq] = len[p] + 1;
				fa[nq] = fa[q], fa[q] = fa[np] = nq;
				while (p && son[p][x] == q) son[p][x] = nq, p = fa[p];
			}
		} else fa[np] = 1;
		return lst;
	}
	int f[400010][18];
	vector <int> G[400010];
	int dfn[400010], DFN, sz[400010];
	void dfs(int x) {
		// cerr << "  x:" << x << endl;
		dfn[x] = ++DFN, sz[x] = 1;
		for (auto v : G[x]) {
			dfs(v), sz[x] += sz[v];
		}
	}
	void PreCalc() {
		for (int i = 2; i <= TOT; i++) {
			// cerr << "    fa:" << fa[i] << " " << i << endl;
			G[fa[i]].push_back(i);
		}
		dfs(1);
		for (int i = 1; i <= TOT; i++) {
			f[i][0] = i == 1 ? 1 : fa[i];
		}
		for (int j = 1; j < 18; j++) for (int i = 1; i <= TOT; i++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	int GetNode(int x, int l) {
		for (int i = 17; i >= 0; i--) {
			if (len[f[x][i]] >= l) x = f[x][i];
		}
		return x;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	static int pos[100010], sop[100010];
	SAM :: Init();
	for (int i = 1; i < n; i++) {
		pos[i] = SAM :: Append(a[i + 1] - a[i]);
	}
	for (int i = 1; i < n; i++) {
		sop[i] = SAM :: Append(a[i] - a[i + 1]);
	}
	SAM :: PreCalc();
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &L[i], &R[i]);
		if (L[i] == R[i]) ans[i] = n - 1, X[i] = -1;
		else ans[i] = 0, X[i] = SAM :: GetNode(sop[R[i] - 1], R[i] - L[i]);
	}
	for (int i = 1; i < n; i++) {
		mdy.push_back(mp(SAM :: dfn[pos[i]], i));
	}
	// return 0;
	for (int i = 0; i < q; i++) {
		if (X[i] != -1) {
			qry.push_back(mp(SAM :: dfn[X[i]] - 1, i << 1 | 0));
			qry.push_back(mp(SAM :: dfn[X[i]] + SAM :: sz[X[i]] - 1, i << 1 | 1));
		}
	}
	sort(mdy.begin(), mdy.end()), sort(qry.begin(), qry.end());
	auto it = mdy.begin(); auto jt = qry.begin();
	while (jt != qry.end()) {
		while (it != mdy.end() && it->fi <= jt->fi) BIT :: Modify(it->se, 1), it++;
		int id = jt->se >> 1, L = :: L[id], R = :: R[id], &ans = :: ans[id], coef = jt->se & 1 ? 1 : -1;
		int delta = R - 1 - L;
		ans += (BIT :: Query(1, L - 2) + BIT :: Query(R + 1 + delta, n - 1)) * coef;
		jt++;
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}