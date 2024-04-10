#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

vector <int> g[N];

int ans = 0;
int dp[N];

void dfs(int u, int p) {
    dp[u] = g[u].size();
    vector <int> id;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] = max(dp[u], dp[v] + (int)g[u].size() - 1);
            id.push_back(v);
        }
    }
    ans = max(ans, dp[u]);
    nth_element(id.begin(), id.begin() + 2, id.end(), [&] (int a, int b) {
        return dp[a] > dp[b];
    });
    if (id.size() > 1) ans = max(ans, dp[id[0]] + dp[id[1]] + (int)g[u].size() - 2);
}

void solve() {
    int n;
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) dp[i] = 0;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}