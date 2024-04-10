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
vector<int> c, p;
vector<array<int, 2>> ans;

void dfs(int i, int k) {
    vector<int> a[2];
    for (int j : adj[i])
        if (j != k) {
            dfs(j, i);
            a[c[j]].pb(j);
        }
    while (!a[c[i]].empty()) {
        int x = i, y = a[c[i]].back();
        a[c[i]].pop_back();
        while (y != -1) {
            ans.pb({x, y});
            c[x] ^= 1, c[y] ^= 1;
            x = y, y = p[y];
        }
    }
    if (!a[c[i]^1].empty())
        p[i] = a[c[i]^1][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        adj.assign(n, {});
        c.assign(n, 0);
        for (int i = 0; i < n-1; i++) {
            int x, y; cin >> x >> y; x--, y--;
            adj[x].pb(y), adj[y].pb(x);
            c[x] ^= 1, c[y] ^= 1;
        }
        ans.clear();
        p.assign(n, -1);
        dfs(0, 0);
        if (ans.size() == n-1) {
            cout << "YES\n";
            for (auto& [x, y] : ans)
                cout << x+1 << " " << y+1 << "\n";
        } else {
            cout << "NO\n";
        }
    }
}