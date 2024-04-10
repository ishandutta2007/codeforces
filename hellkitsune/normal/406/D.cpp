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

int n, m;
LL x[100000], y[100000];
int r[100000];
vector<int> g[100000];
int timer = 0, tin[100000], tout[100000], par[20][100000];

inline bool ccw(LL x, LL y, LL xx, LL yy) {
    return x * yy - xx * y < 0;
}

inline bool check(int i, int j, int k) {
    return ccw(x[k] - x[i], y[k] - y[i], x[j] - x[i], y[j] - y[i]);
}

void dfs(int v, int p) {
    par[0][v] = p;
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to, v);
    }
    tout[v] = timer++;
}

inline bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int lca(int u, int v) {
    if (isParent(v, u)) return u;
    for (int i = 19; i >= 0; --i) if (par[i][u] != -1 && !isParent(v, par[i][u])) {
        u = par[i][u];
    }
    return par[0][u];
}

vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%I64d%I64d", x + i, y + i);
    }
    r[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        r[i] = i + 1;
        while (r[r[i]] != n && check(i, r[i], r[r[i]]))
            r[i] = r[r[i]];
        g[r[i]].pb(i);
    }
    dfs(n - 1, -1);
    REP(i, 19) REP(j, n) if (par[i][j] == -1) {
        par[i + 1][j] = -1;
    } else {
        par[i + 1][j] = par[i][par[i][j]];
    }
    scanf("%d", &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v), --u, --v;
        int lc = lca(u, v);
        ans.pb(lc + 1);
    }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}