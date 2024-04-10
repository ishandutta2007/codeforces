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

int n, k;
vector<PII> g[100000];
int up[17][100000];
bool ubad[100000], dbad[100000];
int cnt[100000] = {};
int tin[100000], tout[100000], dep[100000], timer = 0;
vector<int> mu[100000], md[100000];
int sumu[100000] = {}, sumd[100000] = {};
int z[1000005];
int remu[100005] = {}, remd[100005];
const int MOD = 1e9 + 7;

void dfs(int v, int p, bool ub, bool db) {
    if (p == -1) dep[v] = 0;
    else dep[v] = dep[p] + 1;
    ubad[v] = ub;
    dbad[v] = db;
    tin[v] = timer++;
    up[0][v] = p;
    for (PII to : g[v]) if (to.first != p) {
        dfs(to.first, v, to.second == 2, to.second == 1);
    }
    tout[v] = timer++;
}

inline bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int lcaDep(int u, int v) {
    if (isParent(v, u)) return dep[u];
    for (int i = 16; i >= 0; --i) {
        int x = up[i][u];
        if (x != -1 && !isParent(v, x)) {
            u = x;
        }
    }
    return dep[u] - 1;
}

int ans = 0;

void go(int v, int p) {
    for (int x : mu[v]) ++remu[x];
    for (int x : md[v]) ++remd[x];
    for (PII to : g[v]) if (to.first != p) {
        go(to.first, v);
        sumu[v] += sumu[to.first];
        sumd[v] += sumd[to.first];
    }
    sumu[v] -= remu[dep[v]];
    sumd[v] -= remd[dep[v]];
    remu[dep[v]] = remd[dep[v]] = 0;
    if (ubad[v]) cnt[v] = sumu[v];
    if (dbad[v]) cnt[v] = sumd[v];
    ans += z[cnt[v]];
    if (ans >= MOD) ans -= MOD;
}

int main() {
    z[0] = 0, z[1] = 1;
    for (int i = 2; i < 1000005; ++i) {
        z[i] = z[i - 1] << 1;
        if (z[i] >= MOD) z[i] -= MOD;
    }
    for (int i = 2; i < 1000005; ++i) {
        z[i] += z[i - 1];
        if (z[i] >= MOD) z[i] -= MOD;
    }
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to, x;
        scanf("%d%d%d", &from, &to, &x), --from, --to;
        g[from].pb(mp(to, 2 * x));
        g[to].pb(mp(from, x));
    }
    dfs(0, -1, false, false);
    REP(i, 16) REP(j, n) if (up[i][j] != -1) {
        up[i + 1][j] = up[i][up[i][j]];
    } else {
        up[i + 1][j] = -1;
    }
    scanf("%d", &k);
    int pre = 0;
    REP(i, k) {
        int cur;
        scanf("%d", &cur), --cur;
        int d = lcaDep(pre, cur);
        if (d < dep[pre]) mu[pre].pb(d), ++sumu[pre];
        if (d < dep[cur]) md[cur].pb(d), ++sumd[cur];
        pre = cur;
    }
    go(0, -1);
    printf("%d\n", ans);
    return 0;
}