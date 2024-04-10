#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

struct Node {
    int cost, b, c;
};

void solve(int tc) {
    int n;
    cin >> n;
    vt<Node> node(n);
    for (Node &i : node) {
        cin >> i.cost >> i.b >> i.c;
    }
    vt<vt<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    ll ans = 0;
    function<int(int, int)> dfs = [&](int x, int p) {
        int pos = 0, neg = 0;
        if (!node[x].b && node[x].c) neg++;
        else if (node[x].b && !node[x].c) pos++;

        for (int i : adj[x]) {
            if (i == p) continue;
            node[i].cost = min(node[i].cost, node[x].cost);
            int ret = dfs(i, x);
            if (ret > 0) pos += ret;
            else neg -= ret;
        }

        int mn = min(pos, neg);
        pos -= mn, neg -= mn, ans += 2ll * mn * node[x].cost;
        if (pos) return pos;
        else return -neg;
    };
    if (dfs(0, -1)) return cout << -1, void();
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}