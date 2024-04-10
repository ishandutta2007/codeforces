#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, q, x, y, z;
ll dp[300105];
set<pair<int, ll>> g[300105];

inline void add_edge(int x, int y, ll z) {
    g[x].insert({y, z});
    g[y].insert({x, z});
}

inline void remove_edge(int x, int y) {
    g[x].erase(g[x].lower_bound({y, LLONG_MIN}));
    g[y].erase(g[y].lower_bound({x, LLONG_MIN}));
}

inline ll get_cost(int x, int y) {
    return g[x].lower_bound({y, LLONG_MIN})->second;
}

int pr[300105], inroute[300105];
void dfs(int v, int p = -1) {
    if (pr[v]) return;
    pr[v] = p;
    for (auto& x : g[v])
        dfs(x.first, v);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    queue<int> qu;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> z;
        add_edge(x, y, z);
    }

    dfs(1);
    vector<int> route;
    ll routecost = 0;
    int curv = n;
    while (curv != -1) {
        route.push_back(curv);
        inroute[curv] = 1;
        if (pr[curv] != -1)
            routecost += get_cost(curv, pr[curv]);
        curv = pr[curv];
    }

    int can_cheat = 0;
    for (int i = 0; i < route.size(); ++i) {
        int shrt = 0, lng = 0;
        int v = route[i];
        for (auto& x : g[v]) {
            int to = x.first;
            if (inroute[to]) continue;
            if (g[to].size() == 1) ++shrt;
            else ++lng;
        }
        if (lng > 0 || shrt > 1)
            can_cheat = 1;
    }

    for (int i = 1; i <= n; ++i)
        qu.push(i);
    while (qu.size()) {
        int v = qu.front();
        qu.pop();
        if (v <= 1 || v >= n || g[v].size() != 1) continue;
        int u = g[v].begin()->first;
        int cost = g[v].begin()->second;
        dp[u] = max(dp[u], dp[v] + cost);
        remove_edge(u, v);
        qu.push(u);
    }

    vector<vector<ll>> dp1(2, vector<ll>(route.size())), dp2 = dp1; /// 0 - go to "tails", 1 - strictly on chain
    ll cur = 0;
    for (int i = 0; i < route.size(); ++i) {
        /// Ugly hack here. If edge weights could be = 0, then we would have checked "tails" somehow else.
        dp1[0][i] = max(i ? dp1[0][i - 1] : (ll)-1e18, dp[route[i]] ? cur + dp[route[i]] : (ll)-1e18);
        dp1[1][i] = cur;
        if (i + 1 != route.size())
            cur += get_cost(route[i], route[i + 1]);
    }
    cur = 0;
    for (int i = (int)route.size() - 1; i >= 0; --i) {
        dp2[0][i] = max(i + 1 < (int)route.size() ? dp2[0][i + 1] : (ll)-1e18, dp[route[i]] ? cur + dp[route[i]] : (ll)-1e18);
        dp2[1][i] = cur;
        if (i)
            cur += get_cost(route[i], route[i - 1]);
    }
    ll extra = 0;
    for (int i = 0; i + 1 < route.size(); ++i) {
        extra = max(extra, dp1[0][i] + dp2[1][i + 1]);
        extra = max(extra, dp1[1][i] + dp2[0][i + 1]);
        extra = max(extra, dp1[0][i] + dp2[0][i + 1]);
        if (i + 2 < route.size())
            extra = max(extra, dp1[1][i] + dp2[1][i + 2]);
    }

    while (q--) {
        int x;
        cin >> x;
        if (can_cheat) cout << routecost << "\n";
        else cout << min(extra + x, routecost) << "\n";
    }
}