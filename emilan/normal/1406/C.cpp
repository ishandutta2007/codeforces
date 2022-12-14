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

void solve() {
    int n;
    cin >> n;
    vt<vt<int>> adj(n);
    int bruh1, bruh2;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        bruh1 = u--, bruh2 = v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bruh = [&]() {
        cout << bruh1 << ' ' << bruh2 << '\n';
        cout << bruh1 << ' ' << bruh2 << '\n';
    };
    if (n & 1) return bruh();

    vt<int> subtree_size(n, 1), par(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        par[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;

            dfs(v, u);
            subtree_size[u] += subtree_size[v];
        }
    };
    dfs(0, 0);

    int s = -1;
    for (int i = 0; i < n; i++) {
        if (subtree_size[i] == n / 2) s = i;
    }

    if (!~s) return bruh();

    int t = adj[s][0];
    if (t == par[s]) t = adj[s][1];

    cout << s + 1 << ' ' << t + 1 << '\n';
    cout << par[s] + 1 << ' ' << t + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}