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

struct tour {

    vector<vector<pair<int, int>>> adj;
    vector<int> bad, circ;
    vector<bool> vis;
    int t = 0;

    // n vertices
    tour(int n) : adj(n) {}

    // tour(vector<vector<int>> _adj) : tour(_adj.size()) {
    //     for (int i = 0; i < _adj.size(); i++)
    //         for (int j : adj[i]) if (i < j) edge(i, j);
    // }

    void clear(int n) {
        adj.assign(n, {});
        bad.clear(); circ.clear(); vis.clear();
    }

    // undirected edge between i and j
    void edge(int i, int j) {
        adj[j].push_back({i, t});
        adj[i].push_back({j, t++});
        vis.push_back(0);
    }

    void dfs(int i) {
        // Hierholzers algorithm
        while (!adj[i].empty()) {
            auto [j, e] = adj[i].back();
            adj[i].pop_back();
            if (!vis[e]) {
                vis[e] = 1;
                dfs(j);
            }
        }
        circ.push_back(i);
    }

    // runs in O(E). one time use. assumes graph is connected.
    vector<int> solve() {
        for (int i = 0; i < adj.size(); i++)
            if (adj[i].size()%2 != 0)
                bad.push_back(i);
        if (bad.size() == 0) { // found a circuit
            for (int i = 0; i < adj.size(); i++)
                if (!adj[i].empty()) {
                    dfs(i); return circ;
                }
        } else if (bad.size() == 2) { // found a path
            for (int i : bad) {
                dfs(i); return circ;
            }
        }
        return {};
    }
};

bool query(ll x) {
    cout << "? " << x+1 << endl;
    char r; cin >> r;
    if (r == 'E') exit(0);
    return r == 'Y';
}

const int N = 1024;
int u[N];

auto load_chunk_fwd(int k, int x, bool upd) {
    debug(k, x, upd, "fwd");
    int b = -1;
    for (int i = x; i < x+k; i++)
        if (u[i]) {
             b = i; break;
         }
    if (b == -1) {
        cout << "R" << endl;
        return;
    }
    if (upd) u[b] = u[b] && !query(b);
    else query(b);
    for (int i = x; i < x+k; i++) {
        if (i == b) continue;
        if (!u[i]) query(b);
        else if (upd) u[i] = u[i] && !query(i);
        else query(i);
    }
}

auto load_chunk_rev(int k, int x, bool upd) {
    debug(k, x, upd, "rev");
    int b = -1;
    for (int i = x; i < x+k; i++) {
        if (u[i]) b = i;
    }
    if (b == -1) {
        cout << "R" << endl;
        return;
    }
    debug(u[x], u[x+1], b);
    if (upd) u[b] = u[b] && !query(b);
    else query(b);
    for (int i = x+k-1; i >= x; i--) {
        if (i == b) continue;
        if (!u[i]) query(b);
        else if (upd) u[i] = u[i] && !query(i);
        else query(i);
    }
}

// remove elements of u[y..y+k-1] which occur in u[x..x+k-1], or later in the x block
auto compare_chunks(int k, int x, int y) {
    debug(k, x, y);
    // assuming x is already loaded fwd, with nothing spilled
    load_chunk_rev(k, y, 1);
    cout << "R" << endl;
    load_chunk_rev(k, x, 0);
    load_chunk_fwd(k, y, 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    fill(u, u+n, 1);
    if (k != n)
        for (int i = 0; i < n; i += 2*k) {
            load_chunk_fwd(k, i, 1);
            compare_chunks(k, i, i+k);
        }
    tour t(n/k);
    for (int i = 0; i < n/k; i++)
        for (int j = i+(i%2 ? 1 : 2); j < n/k; j++)
            t.edge(i, j);
    auto v = t.solve();
    cout << "R" << endl;
    debug(v);
    load_chunk_fwd(k, 0, 1);
    for (int i = 0; i+1 < v.size(); i++)
        compare_chunks(k, k*v[i], k*v[i+1]);
    cout << "! " << accumulate(u, u+n, 0) << endl;
}