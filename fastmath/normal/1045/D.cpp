#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n;
int a[MAXN], d[MAXN];
vector <int> g[MAXN];
int r = 0, sum = 0;
void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double p;
        cin >> p;
        a[i] = round(100 - p * 100);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        r += a[u] * a[v];
    }
    for (int i = 0; i < n; ++i) sum += a[i];
}

int par[MAXN];
void dfs(int u, int parent) {
    par[u] = parent;
    if (u) d[parent] += a[u];
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
}

void upd(int u, int delt) {
    if (u) d[par[u]] += delt;
    r += delt * d[u];
    if (u) r += delt * a[par[u]];
    a[u] += delt;
    sum += delt;
}

void solve() {
    dfs(0, -1);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u;
        double p;
        cin >> u >> p;

        int delt = round(100 - 100 * p) - a[u];
        upd(u, delt);    

        cout << sum / 100.0 - r / 10000.0 << '\n';
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();

    return 0;
}