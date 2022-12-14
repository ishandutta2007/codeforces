#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

// range-update
struct Bit {
    int n;
    vector<int> a;

    Bit(int n_) : n(n_), a(n + 1) {}

    Bit(const vector<int> &a_) : n(SZ(a_)), a(n + 1) {
        for (int i = 1; i <= n; i++) {
            a[i] += a_[i - 1];
            if (int j = i + (i & -i); j <= n) {
                a[i] -= a_[j - 1];
            }
        }
    }

    int query(int i) {
        int ans = 0;
        for (i++; i <= n; i += i & -i) {
            ans += a[i];
        }
        return ans;
    }

    void update(int l, int r, int x) {
        update0_(l - 1, -x);
        update0_(r - 1, x);
    }

    void update0_(int i, int x) {
        for (i++; i > 0; i -= i & -i) {
            a[i] += x;
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ord = 0;
    vector<int> tin(n, -1), tout(n, -1);
    vector<int> depth(n);
    auto dfs = [&](auto &self, int u) -> void {
        tin[u] = ord++;
        for (int v : adj[u]) if (tin[v] == -1) {
            depth[v] = depth[u] + 1;
            self(self, v);
        }
        tout[u] = ord;
    };
    dfs(dfs, 0);

    vector<int> b(n);
    for (int u = 0; u < n; u++) {
        b[tin[u]] = depth[u] & 1 ? -a[u] : a[u];
    }
    Bit bit(b);

    // Bit bit(n);
    // for (int u = 0; u < n; u++) {
    //     bit.update(tin[u], tin[u] + 1, depth[u] & 1 ? -a[u] : a[u]);
    // }

    while (q--) {
        int t, u;
        cin >> t >> u;
        u--;
        if (t == 1) {
            int x;
            cin >> x;
            bit.update(tin[u], tout[u], depth[u] & 1 ? -x : x);
        } else {
            int x = bit.query(tin[u]);
            cout << (depth[u] & 1 ? -x : x) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}