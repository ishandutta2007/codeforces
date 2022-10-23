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

vector<vector<int>> adj;
vector<ll> s;

array<ll, 2> dfs(int i, ll x) {
    vector<array<ll, 2>> c;

    if (adj[i].size() == 0)
        return {s[i]*x, s[i]*(x+1)};

    ll y = x/adj[i].size();
    for (int j : adj[i]) {
        s[j] += s[i];
        c.pb(dfs(j, y));
    }
    sort(all(c), [](auto a, auto b){
        return a[1]-a[0] > b[1]-b[0];
    });
    ll k1 = 0, k2 = 0;

    for (int j = 0; j < adj[i].size(); j++) {
        if (j < x%adj[i].size())
            k1 += c[j][1];
        else
            k1 += c[j][0];
        if (j < (x+1)%adj[i].size() || (x+1)%adj[i].size() == 0)
            k2 += c[j][1];
        else
            k2 += c[j][0];
    }

    debug(i, x, k1, k2);

    return {k1, k2};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        adj.assign(n, {});
        s.assign(n, 0);
        for (int i = 1; i < n; i++) {
            int x; cin >> x; x--;
            adj[x].pb(i);
        }
        for (int i = 0; i < n; i++)
            cin >> s[i];
        debug(adj);
        debug(s);
        auto [x, y] = dfs(0, k);
        cout << x << "\n";
    }
}