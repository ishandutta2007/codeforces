#include <stack>
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;
const int LIM = 500005;
bool chk[LIM + 1];
int cnt, u[LIM], v[LIM], w[LIM], prv[LIM], rnk[LIM];
pii e[LIM << 1];

inline bool comp_e(const pii &e1, const pii &e2) { 
	return w[e1.ff] < w[e2.ff] || w[e1.ff] == w[e2.ff] && e1.ss < e2.ss;
}

int dsu(int u, int v, int q) {
	while (prv[u]) u = prv[u];
	while (prv[v]) v = prv[v];
	if (u == v) return chk[q] = false;
	if (rnk[u] > rnk[v]) swap(u, v);
	rnk[prv[u] = v] += rnk[v] == rnk[u];
	return u;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		e[cnt++] = make_pair(i, LIM);
	}
	int q; scanf("%d", &q);
	fill(chk, chk + q, true);
	for (int i = 0; i < q; ++i) {
		int k; scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int x; scanf("%d", &x);
			e[cnt++] = make_pair(--x, i);
		}
	}
	sort(e, e + cnt, comp_e);
	stack<int> s;
	for (int i = 0; i < cnt; ++i) {
		for (pii tmp = e[i]; !comp_e(tmp, e[i]) && !comp_e(e[i], tmp); ++i)
			s.push(dsu(u[e[i].ff], v[e[i].ff], e[i].ss));
		for (--i; !s.empty(); s.pop())
			if (e[i].ss != LIM)
				prv[s.top()] = 0;
	}
	for (int i = 0; i < q; ++i)
		printf("%s\n", chk[i] ? "YES" : "NO");
}