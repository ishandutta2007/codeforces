//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100'005;
vector<int> g[MAXN];
int clr[MAXN];

constexpr int MOD = 1'000'000'007;
inline void add(int& x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
}
inline int mul(int x, int y) {
    return int(x * (ll)y % MOD);
}
int dp[MAXN][2];

void dfs(int v) {
    dp[v][0] = 1;
    for (int to : g[v]) {
        dfs(to);
        dp[v][0] = mul(dp[v][0], dp[to][0] + dp[to][1]);
    }
    if (clr[v]) {
        dp[v][1] = dp[v][0];
        dp[v][0] = 0;
    } else {
        int k = g[v].size();
        vector<int> prefDp(k), suffDp(k);
        for (int i = 0; i < k; ++i) prefDp[i] = suffDp[i] = (dp[g[v][i]][0] + dp[g[v][i]][1]) % MOD;
        for (int i = 1; i < k; ++i) prefDp[i] = mul(prefDp[i], prefDp[i - 1]);
        for (int i = k - 2; i >= 0; --i) suffDp[i] = mul(suffDp[i], suffDp[i + 1]);
        dp[v][1] = 0;
        for (int i = 0; i < k; ++i) {
            int tmp = (i > 0 ? prefDp[i - 1] : 1);
            tmp = mul(tmp, dp[g[v][i]][1]);
            tmp = mul(tmp, i < k - 1 ? suffDp[i + 1] : 1);
            add(dp[v][1], tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cin >> clr[i];
    }

    dfs(0);
    cout << dp[0][1] << '\n';
}