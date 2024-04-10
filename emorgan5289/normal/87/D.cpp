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

struct unionfind {

    vector<int> p, sz;

    unionfind(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x])
            x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return;
        p[b] = a;
        sz[a] += sz[b];
    }

    // returns true if a and b are in the same set.
    bool query(int a, int b) {
        return rep(a) == rep(b);
    }

    // returns the size of the set containing x
    int size(int x) {
        return sz[rep(x)];
    }
};

const int N = 1e5+5;
map<int, vector<array<int, 3>>> m;
vector<pair<int, int>> adj[N];
set<int> s;
vector<pair<int, int>> c;
ll r[N], sz[N];
bool vis[N];
unionfind uf(N);

void dfs(int u, int p) {
    sz[u] = uf.size(u);
    c.pb({u, p});
    for (auto& [i, v] : adj[u])
        if (i != p)
            dfs(v, i), sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v, w; cin >> u >> v >> w;
        m[w].pb({i, u-1, v-1});
    }
    debug(m);
    for (auto& [_, x] : m) {
        for (auto& [i, u, v] : x) {
            u = uf.rep(u), v = uf.rep(v);
            adj[u].pb({i, v}), adj[v].pb({i, u});
            s.insert(u), s.insert(v);
        }
        debug(s, vector(adj, adj+n));
        for (auto& u : s)
            if (!vis[u]) {
                dfs(u, -1);
                debug(c);
                for (auto& [i, j] : c) {
                    vis[i] = 1;
                    if (j != -1)
                        r[j] = 2*sz[i]*(sz[u]-sz[i]);
                }
                c.clear();
            }
        for (auto& u : s)
            adj[u].clear(), vis[u] = 0;
        s.clear();
        for (auto& [i, u, v] : x)
            uf.unite(u, v);
    }
    ll rm = *max_element(r, r+n);
    vector<int> rr;
    for (int i = 0; i < n; i++)
        if (r[i] == rm) rr.pb(i);
    cout << rm << " " << rr.size() << "\n";
    for (auto& i : rr) cout << i+1 << " ";
    cout << "\n";
}