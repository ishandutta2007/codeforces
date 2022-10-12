#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

vector<int> topologicalsort(vector<vector<int>>& adj) {

    int n = adj.size();
    vector<int> out, stk, in(n, 0);
    vector<bool> visited(n, 0);

    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            in[j]++;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
            stk.push_back(i);

    while (!stk.empty()) {
        int i = stk.back();
        stk.pop_back();
        out.push_back(i);
        for (int j : adj[i])
            if (--in[j] == 0)
                stk.push_back(j);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<pair<int, int>> e(m);
        for (auto& [u, v] : e) {
            int b; cin >> b;
            cin >> u >> v; u--, v--;
            if (b) adj[u].pb(v);
        }
        auto o = topologicalsort(adj);
        if (o.size() < n) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            vector<int> p(n);
            for (int i = 0; i < n; i++)
                p[o[i]] = i;
            for (auto& [u, v] : e) {
                if (p[u] > p[v]) swap(u, v);
                cout << u+1 << " " << v+1 << "\n";
            }
        }
    }
}