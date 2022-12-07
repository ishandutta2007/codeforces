#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
vector<PII> g[100000];
int par[100000], ra[100000], sz;
LL tot = 0;
int up[20][100000], mx[20][100000];
int timer = 0, tin[100000], tout[100000];

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
    sz = n;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

bool dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return false;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
    --sz;
    return true;
}

void dfs(int v, int p) {
    tin[v] = timer++;
    for (PII to : g[v]) if (to.first != p) {
        up[0][to.first] = v;
        mx[0][to.first] = to.second;
        dfs(to.first, v);
    }
    tout[v] = timer++;
}

inline bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int moveUp(int u, int &v) {
    int ret = 0;
    for (int i = 19; i >= 0; --i) if (up[i][v] != -1 && !isParent(u, up[i][v])) {
        ret = max(ret, mx[i][v]);
        v = up[i][v];
    }
    ret = max(ret, mx[0][v]);
    v = up[0][v];
    return ret;
}

int findMx(int u, int v) {
    int ret = 0;
    if (!isParent(u, v)) {
        ret = moveUp(u, v);
    }
    if (!isParent(v, u)) {
        ret = max(ret, moveUp(v, u));
    }
    return ret;
}

int from[200000], to[200000], w[200000], ord[200000];

bool cmp(const int &lhs, const int &rhs) {
    return w[lhs] < w[rhs];
}

int main() {
    scanf("%d%d", &n, &m);
    dsuInit();
    REP(i, m) scanf("%d%d%d", from + i, to + i, w + i), --from[i], --to[i];
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    REP(ii, m) {
        int i = ord[ii];
        if (dsuMerge(from[i], to[i])) {
            g[from[i]].pb(mp(to[i], w[i]));
            g[to[i]].pb(mp(from[i], w[i]));
            tot += w[i];
        }
    }
    if (sz == 1) {
        up[0][0] = -1;
        mx[0][0] = 0;
        dfs(0, -1);
        REP(i, 19) REP(j, n) if (up[i][j] == -1) {
            up[i + 1][j] = -1;
            mx[i + 1][j] = mx[i][j];
        } else {
            up[i + 1][j] = up[i][up[i][j]];
            mx[i + 1][j] = max(mx[i][j], mx[i][up[i][j]]);
        }
    }
    scanf("%d", &q);
    REP(i, q) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        if (sz == 1) {
            printf("%I64d\n", tot - findMx(u, v));
        } else if (sz == 2 && dsuParent(u) != dsuParent(v)) {
            printf("%I64d\n", tot);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}