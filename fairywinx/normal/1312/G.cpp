#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void dfs(int v, int &count_used, vector<int> &used, vector<int> &cnt, vector<vector<int>> &g) {
    cnt[v] = count_used;
    if (used[v])
        ++count_used;
    for (int i = 0; i < 26; ++i) {
        if (g[v][i] != -1) {
            dfs(g[v][i], count_used, used, cnt, g);
        }
    }
}

void calc(int v, int ans_par, int tmp_ans, vector<int> &dp, vector<int> &used, vector<vector<int>> &g, vector<int> &cnt) {
    dp[v] = ans_par;
    if (used[v]) {
        dp[v] = min(dp[v], tmp_ans + cnt[v] + 1);
    }
    for (int i = 0; i < 26; ++i) {
        if (g[v][i] != -1) {
            calc(g[v][i], dp[v] + 1, min(tmp_ans, dp[v] - cnt[v]), dp, used, g, cnt);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    g[0].resize(26, -1);
    for (int i = 1; i <= n; ++i) {
        g[i].resize(26, -1);
        int p;
        char c;
        cin >> p >> c;
        g[p][c - 'a'] = i;
    }
    int k;
    cin >> k;
    vector<int> used(n + 1);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        used[a[i]] = 1;
    }
    vector<int> dp(n + 1);
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1e9 + 228;
    }
    int tmp = 0;
    dfs(0, tmp, used, cnt, g);
    calc(0, 0, n + 228, dp, used, g, cnt);
    for (int i = 0; i < k; ++i) {
        cout << dp[a[i]] << ' ';
    }
    cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    // SOLVE;
    solve();
}