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

int n, m;
vector<int> g[999], ng[999];
int par[999], ra[999];
int timer = 0, tin[999], fup[999];

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
    for (int to : g[v]) if (to != p) {
        if (tin[to] == -1) {
            dfs(to, v);
            if (fup[to] <= tin[v]) {
                dsuMerge(v, to);
            }
            fup[v] = min(fup[v], fup[to]);
        } else {
            fup[v] = min(fup[v], tin[to]);
        }
    }
}

set<PII> se;
vector<int> c[999];
vector<int> le;

void dfs2(int v, int p) {
    if ((int)ng[v].size() < 2) {
        le.pb(v);
        return;
    }
    for (int to : ng[v]) if (to != p) {
        dfs2(to, v);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        se.insert(mp(min(from, to), max(from, to)));
        g[from].pb(to);
        g[to].pb(from);
    }
    if (n == 2) {
        printf("-1\n");
        return 0;
    }
    dsuInit();
    REP(i, n) tin[i] = -1;
    dfs(0, -1);
    REP(i, n) c[dsuParent(i)].pb(i);
    int cnt = 0;
    REP(i, n) {
        int ii = dsuParent(i);
        if (ii == i) ++cnt;
        for (int to : g[i]) {
            int jj = dsuParent(to);
            if (jj != ii) {
                ng[ii].pb(jj);
            }
        }
    }
    if (cnt == 1) {
        printf("0\n");
        return 0;
    }
    if (cnt == 2) {
        int a = -1, b = -1;
        REP(i, n) if (dsuParent(i) == i) {
            a = b;
            b = i;
        }
        assert(a != -1 && b != -1);
        for (int u : c[a]) for (int v : c[b]) if (!se.count(mp(min(u, v), max(u, v)))) {
            printf("1\n%d %d\n", u + 1, v + 1);
            return 0;
        }
        assert(false);
    }
    int st = -1;
    REP(i, n) if (dsuParent(i) == i && (int)ng[i].size() > 1) {
        st = i;
        break;
    }
    assert(st != -1);
    dfs2(st, -1);
    int sz = (int)le.size();
    printf("%d\n", (sz + 1) / 2);
    int sk = (sz + 1) / 2;
    if (sz % 2 == 1) {
        le.pb(st);
        ++sz;
    }
    REP(i, sz / 2) {
        int u = le[i];
        int v = le[i + sk];
        bool done = false;
        for (int uu : c[u]) {
            if (done) break;
            for (int vv : c[v]) if (!se.count(mp(min(uu, vv), max(uu, vv)))) {
                printf("%d %d\n", uu + 1, vv + 1);
                done = true;
                break;
            }
        }
        if (!done) {
            REP(i, n) if (i != u && !se.count(mp(min(u, i), max(u, i)))) {
                printf("%d %d\n", u + 1, i + 1);
                return 0;
            }
        }
    }
    return 0;
}