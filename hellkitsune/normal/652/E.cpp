#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<PII> g[300000];
int from[300001], to[300001], z[300001];
int a, b;

int par[300000], ra[300000];
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

int tin[300000], fup[300000], timer = 0;

void dfs(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (PII to : g[v]) if (to.second != p) {
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

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d%d", from + i, to + i, z + i), --from[i], --to[i];
        g[from[i]].pb(mp(to[i], i));
        g[to[i]].pb(mp(from[i], i));
    }
    scanf("%d%d", &a, &b), --a, --b;
    if (a != b) {
        from[m] = a;
        to[m] = b;
        z[m] = 0;
        g[from[m]].pb(mp(to[m], m));
        g[to[m]].pb(mp(from[m], m));
        ++m;
    }
    dsuInit();
    memset(tin, -1, sizeof tin);
    dfs(a, -1);
    if (dsuParent(a) != dsuParent(b)) {
        printf("NO\n");
        return 0;
    }
    REP(i, m) if (z[i] == 1 && dsuParent(from[i]) == dsuParent(a) && dsuParent(to[i]) == dsuParent(a)) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}