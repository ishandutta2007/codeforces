#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    ll a_sum = accumulate(a.begin(), a.end(), 0ll);
    if (a_sum < ll(n - 1) * k) {
        cout << "NO\n";
        return 0;
    }

    vector<int> p(n, -1);
    function<int(int)> root = [&](int u) -> int {
        return p[u] < 0 ? u : p[u] = root(p[u]);
    };
    auto combine = [&](int u, int v) -> bool {
        u = root(u);
        v = root(v);
        if (u == v) return false;
        if (adj[u].size() < adj[v].size()) swap(u, v);

        a[u] += a[v] - k;
        adj[u].insert(adj[u].end(), adj[v].begin(), adj[v].end());
        p[u] = -1;
        p[v] = u;
        return true;
    };

    multiset<pli> s;
    for (int u = 0; u < n; u++) {
        s.emplace(a[u], u);
    }

    vector<int> ans;
    while (!s.empty()) {
        auto [a_u, u] = *s.rbegin();
        s.erase(s.find(pli{a_u, u}));

        while (!adj[u].empty()) {
            auto [v, i] = adj[u].back();
            adj[u].pop_back();

            v = root(v);
            ll a_v = a[v];
            bool glued = combine(u, v);
            if (glued) {
                ans.push_back(i);
                s.erase(s.find(pli{a_v, v}));
                s.emplace(a[root(u)], root(u));
                break;
            }
        }
    }

    cout << "YES\n";
    for (int i : ans) cout << i + 1 << "\n";
}