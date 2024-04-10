#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;
const int INF = 1e9 + 7;

int n, k;
vector <int> g[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
}

int h[MAXN];
void dfs1(int u, int parent, int d) {
    h[u] = d;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs1(v, u, d + 1);
    }
}

int dp1[MAXN], besth[MAXN];
int dp2[MAXN];

void calc(int u, int parent) {
    bool lief = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        lief = 0;
    }   
    
    if (lief) {
        besth[u] = h[u] - k;
        dp1[u] = dp2[u] = 1;
        return;
    }

    besth[u] = INF;
    for (int v : g[u]) {
        if (v == parent) continue;
        besth[u] = min(besth[u], besth[v]);
    }

    for (int v : g[u]) {
        if (v == parent) continue;
        if (besth[v] <= h[u]) dp1[u] += dp1[v];
    }
    
    for (int v : g[u]) {
        if (v == parent) continue;
        int t = 0;
        if (besth[v] <= h[u]) t = dp1[v];
        dp2[u] = max(dp2[u], dp1[u] - t + dp2[v]);
    }

    //cout << u + 1 << " : " << dp1[u] << ' ' << besth[u] << ' ' << dp2[u] << '\n';
}

void dfs2(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs2(v, u);
    }
    calc(u, parent);
}

void solve() {
    dfs1(0, 0, 0);
    dfs2(0, 0);
}

void print() {
    cout << dp2[0] << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}