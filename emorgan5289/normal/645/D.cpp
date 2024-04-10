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
    ll n, m; cin >> n >> m;
    vector<array<int, 2>> e;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        e.pb({x-1, y-1});
    }
    int k = m;
    for (int i = 1<<20; i > 0; i /= 2) {
        vector<vector<int>> adj(n);
        for (int j = 0; j <= k-i; j++)
            adj[e[j][0]].pb(e[j][1]);
        auto o = toposort(adj);
        bool ok = 1;
        for (int j = 0; j < n-1; j++)
            if (find(all(adj[o[j]]), o[j+1]) == adj[o[j]].end())
                ok = 0;
        if (ok) k -= i;
    }
    cout << (k == m ? -1 : k+1) << "\n";
}