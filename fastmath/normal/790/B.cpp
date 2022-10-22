#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e5 + 7;

int n, k;
vector <int> g[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

const int MAXK = 5;

int cnt[MAXN];
int dp[MAXN][MAXK];
int dp1[MAXN];
int tmp[MAXN];
int ans = 0;

void kek(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dp1[v] += dp[v][k - 1];
        for (int i = 0; i < k; ++i) tmp[(i + 1) % k] = dp[v][i];
        for (int i = 0; i < k; ++i) dp[v][i] = tmp[i];
    }

    int add1 = 0;
    dp1[u] = 0; cnt[u] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        add1 += dp1[u] * cnt[v] + dp1[v] * cnt[u];
        dp1[u] += dp1[v];
        cnt[u] += cnt[v];
    }

    int add2 = 0;
    dp[u][0] = 1;
    for (int v : g[u]) {
        if (v == parent) continue;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < k; ++j) {
                add2 += dp[u][i] * dp[v][j] * ((i + j + k - 1) / k);
            }
        }
        for (int i = 0; i < k; ++i) dp[u][i] += dp[v][i];
    }

    ans += add1 + add2;
}

void dfs(int u, int parent) {
    for (int v : g[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
    kek(u, parent);
}
 
void solve() {
    dfs(0, 0);
}

void print() {
    cout << ans << '\n';
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