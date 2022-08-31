#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
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
	int v, w;
	Edge* next;
};

const int N = 200010, L = 18;

int n, m;
bool vis[N];
int dep[N], f[N], ans[N], eu[N], ev[N], ew[N], id[N];
int prt[N][L], mex[N][L];
Edge* g[N];

void adde(int u, int v, int w);
bool cmp(int x, int y) { return ew[x] < ew[y]; }
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs(int u);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &eu[i], &ev[i], &ew[i]);
	iota(id + 1, id + m + 1, 1);
	iota(f + 1, f + n + 1, 1);
	sort(id + 1, id + m + 1, cmp);
	ll ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u = eu[id[i]], v = ev[id[i]], w = ew[id[i]];
		int x = find(u), y = find(v);
		if (x != y) {
			f[x] = y;
			adde(u, v, w);
			adde(v, u, w);
			ans += w;
		}
	}
	dfs(1);
	for (int i = 1; i <= m; ++i) {
		int cmex = 0, u = eu[i], v = ev[i];
		if (dep[u] > dep[v])
			swap(u, v);
		for (int k = 0; k < L; ++k)
			if (((dep[v] - dep[u]) >> k) & 1) {
				cmex = max(cmex, mex[v][k]);
				v = prt[v][k];
			}
		if (u != v) {
			for (int k = L - 1; k >= 0; --k)
				if (prt[u][k] != prt[v][k]) {
					cmex = max(cmex, max(mex[u][k], mex[v][k]));
					u = prt[u][k];
					v = prt[v][k];
				}
			cmex = max(cmex, max(mex[u][0], mex[v][0]));
		}
		printf("%lld\n", ans - cmex + ew[i]);
	}

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

void dfs(int u) {
	vis[u] = true;
	for (int k = 1; k < L; ++k) {
		prt[u][k] = prt[prt[u][k - 1]][k - 1];
		mex[u][k] = max(mex[u][k - 1], mex[prt[u][k - 1]][k - 1]);
	}
	for (Edge* p = g[u]; p; p = p->next)
		if (!vis[p->v]) {
			dep[p->v] = dep[u] + 1;
			prt[p->v][0] = u;
			mex[p->v][0] = p->w;
			dfs(p->v);
		}
}

void adde(int u, int v, int w) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}