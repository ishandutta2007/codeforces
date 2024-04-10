#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int LG = 20;

int n, l, s;
int a[MAXN];
vector <int> g[MAXN];
void read() {
    cin >> n >> l >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p; 
        --p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
}

int go[MAXN][LG];
int sum[MAXN], h[MAXN];

int get(int u) {
    int ost = min(l - 1, h[u]);
    int ostsum = s - a[u];
    for (int i = LG - 1; i >= 0; --i) {
        int v = go[u][i];
        int r = sum[u] - sum[v];
        if (ost >= (1 << i) && ostsum >= r) {
            ost -= (1 << i);
            ostsum -= r;
            u = v;
        }
    }
    return u;
}

void dfs(int u, int parent, int d) {
    h[u] = d;

    if (u) sum[u] = sum[parent] + a[parent];
    else sum[u] = 0;

    go[u][0] = parent;
    for (int i = 1; i < LG; ++i) {
        go[u][i] = go[go[u][i - 1]][i - 1];
    }

    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u, d + 1);
    }
}

int getbest(int u, int v) {
    if (u == -1) return v;
    if (v == -1) return u;
    if (h[u] < h[v]) return u;
    else return v;
}

int dp[MAXN], best[MAXN];
void dfs1(int u, int parent) {
    best[u] = -1;
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        dp[u] += dp[v];
        best[u] = getbest(best[u], best[v]);
    }
    if (best[u] == -1) {
        ++dp[u];
        if (get(u) == u) best[u] = -1;
        else best[u] = get(u);
    }
    else if (best[u] == u) {
        best[u] = -1;
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (a[i] > s) {
            cout << "-1\n";
            exit(0);
        }   
    }

    dfs(0, 0, 0);
    dfs1(0, 0);
}

void print() {
    cout << dp[0] << '\n';
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