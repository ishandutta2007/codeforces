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
vector<int> g[300000];
int par[300000], ra[300000], len[300000];

void dsuInit() {
    REP(i, n) par[i] = i, ra[i] = 1, len[i] = 0;
}

int dsuParent(int v) {
    if (v == par[v]) return v;
    return par[v] = dsuParent(par[v]);
}

void dsuMerge(int u, int v, bool calcLen) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    par[v] = u;
    ra[u] += ra[v];
    if (calcLen) {
        len[u] = max((len[u] + 1) / 2 + (len[v] + 1) / 2 + 1, max(len[u], len[v]));
    }
}

int best;
int dist[300000];

void dfs(int v, int p) {
    if (p == -1) {
        dist[v] = 0;
    } else {
        dist[v] = dist[p] + 1;
    }
    if (dist[v] > dist[best]) {
        best = v;
    }
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    dsuInit();
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        dsuMerge(from, to, false);
        g[from].pb(to);
        g[to].pb(from);
    }
    REP(i, n) if (dsuParent(i) == i) {
        best = i;
        dfs(i, -1);
        dfs(best, -1);
        len[i] = dist[best];
    }
    REP(i, q) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int v;
            scanf("%d", &v), --v;
            printf("%d\n", len[dsuParent(v)]);
        } else {
            int from, to;
            scanf("%d%d", &from, &to), --from, --to;
            dsuMerge(from, to, true);
        }
    }
    return 0;
}