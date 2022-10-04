#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;

ll dp[N][2];
vector <pair <int, int>> g[N];

int k;

void dfs(int u, int p) {
    vector <ll> best;
    ll sum = 0;
    for (auto [v, w] : g[u]) {
        if (v != p) {
            dfs(v, u);
            sum += dp[v][0];
            best.push_back(dp[v][1] + w - dp[v][0]);
        }
    }
    sort(best.rbegin(), best.rend());
    dp[u][0] = sum;
    dp[u][1] = sum;
    for (int i = 0; i < min(k, (int)best.size()); ++i) {
        dp[u][0] += max(0LL, best[i]);
    }
    for (int i = 0; i < min(k - 1, (int)best.size()); ++i) {
        dp[u][1] += max(0LL, best[i]);
    }
}

void solve() {
    int n;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    for (int i = 0; i + 1 < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) solve();
}