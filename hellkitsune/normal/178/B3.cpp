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
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
vector<int> g[100000], ng[100000];
int par[100000], ra[100000];
int curT = 0, tin[100000], fup[100000];
int dep[100000], root;
int tout[100000];
int tpar[20][100000];
bool used[100000];

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
}

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
}

void dfs(int v, int p) {
    fup[v] = tin[v] = curT++;
    for (int to : g[v]) if (to != p) {
        if (tin[to] != -1) {
            fup[v] = min(fup[v], tin[to]);
            dsuMerge(v, to);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] <= tin[v]) {
                dsuMerge(v, to);
            }
        }
    }
}

void dfs2(int v, int p) {
    tpar[0][v] = p;
    if (p == -1) dep[v] = 0;
    else dep[v] = dep[p] + 1;
    tin[v] = curT++;
    for (int to : ng[v]) if (to != p) {
        dfs2(to, v);
    }
    tout[v] = curT++;
}

bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int lca(int u, int v) {
    if (isParent(v, u)) return u;
    for (int i = 19; i >= 0; --i) {
        if (tpar[i][u] != -1 && !isParent(v, tpar[i][u])) {
            u = tpar[i][u];
        }
    }
    return tpar[0][u];
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dsuInit();
    REP(i, n) tin[i] = -1;
    dfs(0, -1);
    REP(i, n) {
        int v = dsuParent(i);
        for (int to : g[i]) {
            int u = dsuParent(to);
            if (u != v) {
                ng[v].pb(u);
            }
        }
    }
    root = dsuParent(0);
    curT = 0;
    dfs2(root, -1);
    REP(i, n) if (dsuParent(i) == i) used[i] = true;
    for (int i = 0; i < 19; ++i) REP(j, n) if (used[j]) {
        if (tpar[i][j] == -1) {
            tpar[i + 1][j] = -1;
        } else {
            tpar[i + 1][j] = tpar[i][tpar[i][j]];
        }
    }
    scanf("%d", &k);
    REP(i, k) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        from = dsuParent(from);
        to = dsuParent(to);
        int lc = lca(from, to);
        printf("%d\n", dep[from] + dep[to] - 2 * dep[lc]);
    }
    return 0;
}