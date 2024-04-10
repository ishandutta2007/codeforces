#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

int n, m;
vector <int> g[MAXN];
char a[MAXN];

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
    }   
}

bool used[MAXN];
int pos[MAXN];
vector <int> v;

void dfs1(int u) {
    used[u] = 1;
    for (int v : g[u]) {
        if (!used[v]) dfs1(v);
    }
    v.push_back(u);
}

void check() {
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i) if (!used[i]) dfs1(i);
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; ++i) pos[v[i]] = i;
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (pos[v] <= pos[u]) {
                cout << "-1\n";
                exit(0);
            }
        }
    }
}

int dp[MAXN];
void dfs2(int u, char c) {
    used[u] = 1;
    dp[u] = (a[u] == c);
    for (int v : g[u]) {
        if (!used[v]) dfs2(v, c);
        dp[u] = max(dp[u], (a[u] == c) + dp[v]);
    }
}

int get(char c) {
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; ++i) if (!used[i]) dfs2(i, c);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    return ans;
}

int ans = 0;
void solve() {
    for (char c = 'a'; c <= 'z'; ++c) ans = max(ans, get(c));    
}

void print() {
    cout << ans << '\n';
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    check();
    solve();
    print();

    return 0;
}