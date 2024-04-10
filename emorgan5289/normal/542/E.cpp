#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

pair<int, vector<int>> components(vector<vector<int>>& adj) {
    int size = adj.size();
    vector<bool> vis(size, 0), r(size);
    vector<int> c(size), s;
    int t = -1;
    for (int i = 0; i < size; i++)
        if (!vis[i]) {
            s.push_back(i); c[i] = ++t; vis[i] = 1; r[i] = 0;
            while (!s.empty()) {
                int j = s.back(); s.pop_back();
                for (auto k : adj[j])
                    if (!vis[k]) {
                        vis[k] = 1;
                        r[k] = !r[j];
                        c[k] = t;
                        s.push_back(k);
                    } else {
                        if (r[j] == r[k]) {
                            cout << "-1\n"; exit(0);
                        }
                    }
            }
        }
    return make_pair(t+1, c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v); adj[v].pb(u);
    }
    auto [t, c] = components(adj);
    vector<int> r(t, 0), d;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        d.assign(n, -1);
        d[i] = 0; q.push(i);
        while (!q.empty()) {
            int j = q.front(); q.pop();
            r[c[i]] = max(r[c[i]], d[j]);
            for (auto& k : adj[j])
                if (d[k] == -1) {
                    d[k] = d[j]+1; q.push(k);
                }
        }
    }
    int out = 0;
    for (int i = 0; i < t; i++)
        out += r[i];
    cout << out << "\n";
}