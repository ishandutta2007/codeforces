#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

vector<int> toposort(vector<vector<int>> adj) {
    vector<int> out, stk, in(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
        for (int j : adj[i]) in[j]++;
    for (int i = 0; i < adj.size(); i++)
        if (!in[i]) stk.push_back(i);
    while (!stk.empty()) {
        out.push_back(stk.back()); stk.pop_back();
        for (int j : adj[out.back()])
            if (!--in[j]) stk.push_back(j);
    }
    return out;
}

#define pc __builtin_popcountll

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<ll> dp(n), in(n);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), in[y]++;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        if (adj[i].size() == 0)
            dp[i] = 1<<(k++);
    auto o = toposort(adj);
    reverse(all(o));
    for (int i : o)
        for (int j : adj[i])
            dp[i] |= dp[j];
    vector<ll> e(k);
    bool ok = 0;
    for (int i = 0, j = 0; i < n; i++)
        if (in[i] == 0) e[j++] = dp[i];
    for (int i = 1; i < (1<<k)-1; i++) {
        ll x = 0;
        for (int j = 0; j < k; j++)
            if (i&(1<<j)) x |= e[j];
        if (pc(x) <= pc(i))
            ok = 1;
    }
    cout << (ok ? "NO" : "YES") << "\n";
}