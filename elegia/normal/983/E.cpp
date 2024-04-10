#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <random>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Edge {
	int v;
	 Edge* next;
};

const int N = 200010, LGN = 19;

int n, m, q;
int dep[N], su[N], sv[N], sl[N], qu[N], qv[N], ql[N], ans[N], fw[N], dl[N], dr[N], tmp[N];
vector<int> subway[N];
vector<pair<int, int> > qry[N];
int prt[N][LGN], dp[N][LGN];
Edge* g[N];

int lowBit(int k) { return k & -k; }

void adde(int u, int v);
int lca(int u, int v);
void dfn(int u);
void dfs(int u);
void ch(int k, int x);
int qr(int k);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &prt[i][0]);
		adde(prt[i][0], i);
		dep[i] = dep[prt[i][0]] + 1;
		for (int j = 1; j < LGN; ++j)
			prt[i][j] = prt[prt[i][j - 1]][j - 1];
	}
	scanf("%d", &m);
	for (int i = 1; i <= n; ++i)
		dp[i][0] = i;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &su[i], &sv[i]);
		sl[i] = lca(su[i], sv[i]);
		if (su[i] > sv[i])
			swap(su[i], sv[i]);
		subway[su[i]].push_back(sv[i]);
		subway[sv[i]].push_back(su[i]);
		dp[su[i]][0] = min(dp[su[i]][0], sl[i]);
		dp[sv[i]][0] = min(dp[sv[i]][0], sl[i]);
	}
	for (int u = n; u; --u)
		for (Edge* p = g[u]; p; p = p->next)
			dp[u][0] = min(dp[u][0], dp[p->v][0]);
	for (int u = 1; u <= n; ++u)
		for (int i = 1; i < LGN; ++i)
			dp[u][i] = dp[dp[u][i - 1]][i - 1];
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &qu[i], &qv[i]);
		if (qu[i] > qv[i])
			swap(qu[i], qv[i]);
		ql[i] = lca(qu[i], qv[i]);
		for (int k = LGN - 1; k >= 0; --k)
			if (dp[qv[i]][k] > ql[i]) {
				qv[i] = dp[qv[i]][k];
				ans[i] += 1 << k;
			}
		if (ql[i] == qu[i]) {
			if (dp[qv[i]][0] > ql[i])
				ans[i] = -1;
			else if (qv[i] > ql[i])
				++ans[i];
		} else {
			for (int k = LGN - 1; k >= 0; --k)
				if (dp[qu[i]][k] > ql[i]) {
					qu[i] = dp[qu[i]][k];
					ans[i] += 1 << k;
				}
			if (dp[qv[i]][0] > ql[i] || dp[qu[i]][0] > ql[i]) {
				ans[i] = -1;
			} else {
				if (qu[i] > qv[i])
					swap(qu[i], qv[i]);
				qry[qu[i]].emplace_back(qv[i], i);
			}
		}
	}
	dfn(1);
	dfs(1);
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void dfn(int u) {
	static int t = 0;
	dl[u] = ++t;
	for (Edge* p = g[u]; p; p = p->next)
		dfn(p->v);
	dr[u] = t;
}

void dfs(int u) {
	for (pair<int, int> qq : qry[u])
		tmp[qq.second] = qr(dl[qq.first] - 1) - qr(dr[qq.first]);
	for (int dest : subway[u]) {
		ch(dl[dest], 1);
	}
	for (Edge* p = g[u]; p; p = p->next)
		dfs(p->v);
	for (pair<int, int> qq : qry[u])
		ans[qq.second] += 1 + (tmp[qq.second] == qr(dl[qq.first] - 1) - qr(dr[qq.first]));
}

void ch(int k, int x) {
	for (; k <= n; k += lowBit(k))
		fw[k] += x;
}

int qr(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret += fw[k];
	return ret;
}

void adde(int u, int v) {
	static Edge pool[N];
	static Edge* p = pool;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	++p;
}

int lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	for (int k = 0; k < LGN; ++k)
		if (((dep[u] - dep[v]) >> k) & 1)
			u = prt[u][k];
	if (u == v)
		return u;
	for (int k = LGN - 1; k >= 0; --k)
		if (prt[u][k] != prt[v][k]) {
			u = prt[u][k];
			v = prt[v][k];
		}
	return prt[u][0];
}