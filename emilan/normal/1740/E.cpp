#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> chi(n);
    for (int u = 1; u < n; u++) {
        int p;
        cin >> p;
        p--;
        chi[p].push_back(u);
    }

    vector<int> hei(n);
    vector<int> dp(n);
    auto dfs = [&](auto &self, int u) -> void {
        for (int v : chi[u]) {
            self(self, v);
            dp[u] += dp[v];
            hei[u] = max(hei[u], hei[v] + 1);
        }
        dp[u] = max(dp[u], hei[u] + 1);
    };
    dfs(dfs, 0);

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}