#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
vector<int> g[100000];
int par[100000][17];
int h[100000];
int tin[100000], tout[100000], timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    h[v] = (p == -1 ? 0 : h[p] + 1);
    par[v][0] = p;
    forn(i, 16) {
        if (par[v][i] == -1) {
            par[v][i + 1] = -1;
        } else {
            par[v][i + 1] = par[par[v][i]][i];
        }
    }
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
    tout[v] = timer++;
}

bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int lca(int u, int v) {
    if (isParent(u, v)) return v;
    if (isParent(v, u)) return u;
    for (int i = 16; i >= 0; --i) if (par[v][i] != -1 && !isParent(u, par[v][i])) {
        v = par[v][i];
    }
    return par[v][0];
}

int dist(int a, int b) {
    int lc = lca(a, b);
    return h[a] + h[b] - 2 * h[lc];
}

const int D = 0;
mt19937 mt(123);

int main() {
    if (D) {
        n = 100000;
        q = 100000;
    } else {
        scanf("%d%d", &n, &q);
    }
    for (int i = 1; i < n; ++i) {
        int v;
        if (D) {
            v = mt() % i;
        } else {
            scanf("%d", &v), --v;
        }
        g[i].pb(v);
        g[v].pb(i);
    }
    dfs(0, -1);
    forn(i, q) {
        int a, b, c;
        if (D) {
            a = mt() % n;
            b = mt() % n;
            c = mt() % n;
        } else {
            scanf("%d%d%d", &a, &b, &c), --a, --b, --c;
        }
        int x = lca(a, b);
        int y = lca(a, c);
        int z = lca(b, c);

        int lc;
        if (x != y && x != z) lc = x;
        else if (y != x && y != z) lc = y;
        else lc = z;

        int ans = 1 + max({dist(a, lc), dist(b, lc), dist(c, lc)});
        printf("%d\n", ans);
    }
    return 0;
}