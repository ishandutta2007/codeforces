#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 3e5 + 7;

vector <int> g[MAXN];
int par[MAXN];
int h[MAXN];
int cnt[MAXN];

void jfs(int u, int parent, int d) {
    par[u] = parent;
    h[u] = d;
    cnt[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        jfs(v, u, d + 1);
        cnt[u] += cnt[v];
    }
}

int lca(int u, int v) {
    while (h[u] < h[v]) v = par[v];
    while (h[v] < h[u]) u = par[u];
    while (u != v) {
        u = par[u];
        v = par[v];
    }
    return u;
}
 
bool chx[MAXN], chy[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    --x;
    --y;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    jfs(0, 0, 0);
    
    int u = x;
    while (true) {
        chx[u] = true;
        if (u == 0) break;
        u = par[u];
    }

    u = y;
    while (true) {
        chy[u] = true;
        if (u == 0) break;
        u = par[u];
    }

    int l = lca(x, y);
    
    int bad = 0;
    if (l == x) {
        int k = -1;
        for (int v : g[x]) {
            if (v == par[x]) continue;
            if (chy[v]) k = v;
        }

        bad = (n - cnt[k]) * cnt[y];
    }
    else if (l == y) {
        int k = -1;
        for (int v : g[y]) {
            if (v == par[y]) continue;
            if (chx[v]) k = v;
        }

        bad = (n - cnt[k]) * cnt[x];
    }
    else {
        bad = cnt[x] * cnt[y];
    }

    cout << n * (n - 1) - bad << '\n';
     
    return 0;
}