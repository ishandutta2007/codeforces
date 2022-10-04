#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 7;

vector <int> g[N];

ll dp[N];

int a[N];

ll ans = -1e18;

void dfs(int u, int p) {
    dp[u] = a[u];
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u] += max(0ll, dp[v]);
        }
    }
    ans = max(ans, dp[u]);
}

int k = 0;

void jhfs(int u, int p) {
    dp[u] = a[u];
    for (auto v : g[u]) {
        if (v != p) {
            jhfs(v, u);
            if (dp[v] != ans) {
                dp[u] += max(0ll, dp[v]);
            }
        }
    }
    if (dp[u] == ans) ++k;
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
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    jhfs(0, -1);
    cout << ans * k << ' ' << k << '\n';
}