#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

template<typename T>
vector<T> dijkstra(vector<vector<pair<T, int>>> adj, int s) {

    const static T inf_T = numeric_limits<T>::max();
    int n = adj.size();
    vector<bool> vis(n, 0);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> heap;
    heap.push({0, s});
    vector<T> out(n, inf_T);

    while (!heap.empty()) {
        auto [c, i] = heap.top(); heap.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        out[i] = c;
        for (auto& [w, j] : adj[i])
            if (!vis[j])
                heap.push({c+w, j});
    }
    return out;
}

const int maxn = 300005;
int s[maxn]; ll y[maxn], d[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<ll, int>>> adj(2*n);
    for (int i = 0; i < m; i++) {
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        adj[u].pb({w, v}); adj[v].pb({w, u});
        adj[u+n].pb({w, v}); adj[v+n].pb({w, u});
    }
    adj[n].pb({0, 0});
    fill(d, d+maxn, inf_ll);
    int out = 0;
    for (int i = 0; i < k; i++) {
        cin >> s[i] >> y[i]; s[i]--;
        if (d[s[i]] != inf_ll) out++;
        d[s[i]] = min(d[s[i]], y[i]);
    }
    for (int i = 0; i < n; i++)
        if (d[i] != inf_ll)
            adj[n].pb({d[i], i+n});
    auto c = dijkstra(adj, n);
    for (int i = 0; i < n; i++)
        if (d[i] != inf_ll && c[i] <= d[i])
            out++;
    cout << out << "\n";
}