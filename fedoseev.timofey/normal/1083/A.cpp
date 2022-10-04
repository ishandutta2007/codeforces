#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

int a[N];
ll dp[N];

vector <pair <int, int>> g[N];

ll ans = 0;

void dfs(int u, int p) {
    dp[u] = a[u];
    vector <pair <int, int>> id;
    for (auto &[v, w] : g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] = max(dp[u], a[u] - w + dp[v]);
            id.push_back({v, w});
        }
    }
    sort(id.begin(), id.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        return dp[a.first] - a.second > dp[b.first] - b.second;
    });
    ans = max(ans, dp[u]);
    if (id.size() >= 2) {
        ans = max(ans, a[u] + dp[id[0].first] + dp[id[1].first] - id[0].second - id[1].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i + 1 < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dfs(0, -1);
    cout << ans << '\n';
}