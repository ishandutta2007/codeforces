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

void die() {
    cout << "No";
    exit(0);
}

void solve() {
    int n, k;
    cin >> n >> k;

    if (n < 4 || k > 10) die();

    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s = 0;
    for (; sz(adj[s]) != 1; s++);

    int c = -1;
    queue<int> q;
    vt<int> d(n, -1), p(n, -1);
    q.push(s);
    d[s] = 0, p[s] = s;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (d[u] == k * 2) {
            for (int i = 0; i < k; i++, u = p[u]);
            c = u;
            break;
        }

        for (int v : adj[u]) if (!~d[v]) {
            d[v] = d[u] + 1;
            p[v] = u;
            q.push(v);
        }
    }

    if (!~c) die();

    auto dfs = [&](int u, int p, int d, auto &f) -> void {
        if ((d == k && sz(adj[u]) != 1)
                || (d > 0 && d < k && sz(adj[u]) < 4)
                || (d == 0 && sz(adj[u]) < 3)) {
            die();
        }

        for (int v : adj[u]) if (v != p) {
            f(v, u, d + 1, f);
        }
    };
    dfs(c, c, 0, dfs);

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}