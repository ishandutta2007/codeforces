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

int n, m, q;
vector<PII> og[200000];
vector<int> g[200000];
int timer = 0, tin[200000], fup[200000], tout[200000], dep[200000];

int par[200000], ra[200000];
int up[20][200000];
int gp[200000];
int dir[200000], rev[200000];

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1;
}

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

void dfs(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (PII to : og[v]) if (to.second != p) {
        if (tin[to.first] == -1) {
            dfs(to.first, to.second);
            if (fup[to.first] <= tin[v]) {
                dsuMerge(v, to.first);
            }
            fup[v] = min(fup[v], fup[to.first]);
        } else {
            fup[v] = min(fup[v], tin[to.first]);
        }
    }
}

int curGP;

void dfs2(int v, int p) {
    tin[v] = timer++;
    up[0][v] = p;
    if (p == -1) {
        dep[v] = 0;
    } else {
        dep[v] = dep[p] + 1;
    }
    gp[v] = curGP;
    for (int to : g[v]) if (to != p) {
        dfs2(to, v);
    }
    tout[v] = timer++;
}

inline bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int lca(int u, int v) {
    if (isParent(u, v)) return v;
    if (isParent(v, u)) return u;
    for (int i = 19; i >= 0; --i) if (up[i][v] != -1 && !isParent(u, up[i][v])) {
        v = up[i][v];
    }
    return up[0][v];
}

PII dfs3(int v, int p) {
    int curDir = dir[v];
    int curRev = rev[v];
    for (int to : g[v]) if (to != p) {
        PII ret = dfs3(to, v);
        curDir = max(curDir, ret.first - 1);
        curRev = max(curRev, ret.second - 1);
    }
    if (curDir > 0 && curRev > 0) {
        printf("No\n");
        exit(0);
    }
    return mp(curDir, curRev);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        og[from].pb(mp(to, i));
        og[to].pb(mp(from, i));
    }
    dsuInit();
    REP(i, n) tin[i] = -1;
    REP(i, n) if (tin[i] == -1) {
        dfs(i, -1);
    }
    REP(i, n) {
        int ii = dsuParent(i);
        for (PII to : og[i]) {
            int jj = dsuParent(to.first);
            if (ii != jj) {
                g[ii].pb(jj);
            }
        }
    }
    REP(i, n) gp[i] = -1;
    REP(i, n) if (gp[i] == -1 && dsuParent(i) == i) {
        curGP = i;
        dfs2(i, -1);
    }
    REP(i, 19) REP(j, n) if (up[i][j] == -1) {
        up[i + 1][j] = -1;
    } else {
        up[i + 1][j] = up[i][up[i][j]];
    }

    memset(dir, 0, sizeof dir);
    memset(rev, 0, sizeof rev);
    REP(i, q) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        from = dsuParent(from);
        to = dsuParent(to);
        if (gp[from] != gp[to]) {
            printf("No\n");
            return 0;
        }
        int lc = lca(from, to);
        dir[from] = max(dir[from], dep[from] - dep[lc]);
        rev[to] = max(rev[to], dep[to] - dep[lc]);
    }
    REP(i, n) if (dsuParent(i) == i && i == gp[i]) {
        dfs3(i, -1);
    }
    printf("Yes\n");
    return 0;
}