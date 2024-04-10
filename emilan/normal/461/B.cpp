#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int N = 1e5;
const ll mod = 1e9 + 7;
ll dp[N][2];

ll inv(ll a, ll b = mod) {
    return a > 1 ? b - inv(b % a, a) * b / a : 1;
}

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> adj(n);
    for (int u = 1; u < n; u++) {
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vt<int> color(n);
    for (int &x : color) cin >> x;

    ll ans = 1;
    auto dfs = [&](int u, int p, auto &f) -> void {
        if (color[u]) {
            dp[u][0] = dp[u][1] = 1;

            for (int v : adj[u]) if (v != p) {
                f(v, u, f);
                ans = ans * dp[v][1] % mod;
            }

            return;
        }

        ll pi1 = 1;
        for (int v : adj[u]) if (v != p) {
            f(v, u, f);
            pi1 = pi1 * dp[v][1] % mod;
        }

        for (int v : adj[u]) if (v != p) {
            dp[u][0] += pi1 * dp[v][0] % mod * inv(dp[v][1]) % mod;
        }

        dp[u][0] %= mod;
        dp[u][1] = (pi1 + dp[u][0]) % mod;
    };

    for (int i = 0; i < n; i++) {
        if (color[i]) {
            dfs(i, i, dfs);
            break;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}