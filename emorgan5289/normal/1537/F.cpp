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
vector<int> c;

bool dfs(int i) {
    for (int j : adj[i]) {
        if (c[j] == -1) {
            c[j] = c[i]^1;
            if (dfs(j)) return 1;
        }
        if (c[i] == c[j])
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        ll s = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            ll x; cin >> x; a[i] -= x;
            s += a[i];
        }
        adj.assign(n, {});
        c.assign(n, -1);
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
        }
        if (s&1) {
            cout << "NO\n"; continue;
        }
        c[0] = 0;
        if (dfs(0)) {
            cout << "YES\n"; continue;
        }
        s = 0;
        for (int i = 0; i < n; i++) {
            if (c[i]) a[i] *= -1;
            s += a[i];
        }
        debug(c);
        debug(a);
        debug(s);
        cout << (s == 0 ? "YES" : "NO") << "\n";
    }
}