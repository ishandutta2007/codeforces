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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i]--;
        for (int i = 0; i < n; i++)
            cin >> b[i], b[i]--;
        map<ll, ll> f;
        for (int i = 0; i < n; i++)
            f[a[i]]++;
        ll mf = 0, r = 0;
        for (auto& [x, y] : f) cmax(mf, y);
        for (int i = 0; i < n; i++)
            if (f[i] == mf) r = i;

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            if (a[i] != r && b[i] != r)
                adj[a[i]].pb(b[i]);

        debug(adj);

        cout << (toposort(adj).size() != n ? "WA" : "AC") << "\n";
    }
}