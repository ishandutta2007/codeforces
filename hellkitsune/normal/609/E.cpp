#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<PII> g[200000];
bool taken[200000] = {};
int s[200000], t[200000], w[200000], ord[200000];

inline bool cmp(const int &lhs, const int &rhs) {
    return w[lhs] < w[rhs];
}

int dpar[200000], ra[200000];
void dsuInit() {
    REP(i, n) dpar[i] = i, ra[i] = 1;
}

int dsuParent(int v) {
    if (v == dpar[v]) return v;
    return dpar[v] = dsuParent(dpar[v]);
}

void dsuMerge(int u, int v) {
    u = dsuParent(u);
    v = dsuParent(v);
    if (u == v) return;
    if (ra[u] < ra[v]) swap(u, v);
    dpar[v] = u;
    ra[u] += ra[v];
}

const int INF = 1e9 + 111;
int tin[200000], tout[200000], timer = 0;
int par[18][200000], mx[18][200000];

void dfs(int v, int p, int cost) {
    par[0][v] = p;
    mx[0][v] = cost;
    REP(i, 17) {
        if (par[i][v] == -1) break;
        par[i + 1][v] = par[i][par[i][v]];
        mx[i + 1][v] = max(mx[i][v], mx[i][par[i][v]]);
    }
    tin[v] = timer++;
    for (PII to : g[v]) if (to.first != p) {
        dfs(to.first, v, to.second);
    }
    tout[v] = timer++;
}

bool isParent(int v, int p) {
    return tin[p] <= tin[v] && tout[p] >= tout[v];
}

int findMax(int u, int v) {
    int res = 0;
    REP(times, 2) {
        for (int i = 17; i >= 0; --i) if (par[i][u] != -1 && !isParent(v, par[i][u])) {
            res = max(res, mx[i][u]);
            u = par[i][u];
        }
        if (!isParent(v, u)) {
            res = max(res, mx[0][u]);
            u = par[0][u];
        }
        swap(u, v);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to, ww;
        scanf("%d%d%d", &from, &to, &ww), --from, --to;
        g[from].pb(mp(to, ww));
        g[to].pb(mp(from, ww));
        s[i] = from;
        t[i] = to;
        w[i] = ww;
    }
    dsuInit();
    REP(i, m) ord[i] = i;
    sort(ord, ord + m, cmp);
    LL ans = 0;
    REP(ii, m) {
        int i = ord[ii];
        if (dsuParent(s[i]) != dsuParent(t[i])) {
            dsuMerge(s[i], t[i]);
            taken[i] = true;
            ans += w[i];
        }
    }
    REP(i, n) g[i].clear();
    REP(x, m) if (taken[x]) {
        g[s[x]].pb(mp(t[x], w[x]));
        g[t[x]].pb(mp(s[x], w[x]));
    }
    dfs(0, -1, 0);
    REP(x, m) if (taken[x]) {
        printf("%I64d\n", ans);
    } else {
        LL cur = ans - findMax(s[x], t[x]) + w[x];
        printf("%I64d\n", cur);
    }
    return 0;
}