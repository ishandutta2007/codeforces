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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    void unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (a != b) p[b] = a, sz[a] += sz[b];
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

const int N = 5e5+5;
int c[N], v[N], r[N], bad[N];
vector<int> adj[N];
vector<array<int, 2>> adj2[N];
map<array<int, 2>, vector<array<int, 3>>> edges;

void dfs(int i) {
    v[i] = 1;
    for (auto& j : adj[i])
        if (c[i] == c[j] && !v[j]) r[j] = r[i]^1, dfs(j);
}

void dfs2(int i) {
    v[i] = 1;
    for (auto& [w, j] : adj2[i])
        if (!v[j]) r[j] = r[i]^w, dfs2(j);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    dsu uf(n);
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
        if (c[x] == c[y]) uf.unite(x, y);
    }
    ll good = k;
    for (int i = 0; i < n; i++)
        if (!v[i]) dfs(i);
    for (int i = 0; i < n; i++)
        for (auto& j : adj[i])
            if (c[i] == c[j] && !bad[c[i]] && r[i] == r[j])
                bad[c[i]] = 1, good--;
    ll ans = good*(good-1)/2;
    for (int i = 0; i < n; i++)
        for (auto& j : adj[i])
            if (i < j && c[i] != c[j] && !bad[c[i]] && !bad[c[j]]) {
                int x = uf.rep(i), y = uf.rep(j);
                if (x > y) swap(x, y);
                edges[{min(c[i], c[j]), max(c[i], c[j])}].pb({uf.rep(i), uf.rep(j), r[i]^r[j]^1});
            }
    for (auto& [_, sub] : edges) {
        for (auto& [x, y, w] : sub) {
            r[x] = r[y] = v[x] = v[y] = 0;
            adj2[x].clear(), adj2[y].clear();
        }
        for (auto& [x, y, w] : sub)
            adj2[x].pb({w, y}), adj2[y].pb({w, x});
        for (auto& [x, y, w] : sub)
            if (!v[x]) dfs2(x);
        bool ok = 1;
        for (auto& [x, y, w] : sub)
            ok = ok && (1^r[x]^r[y]^w);
        if (!ok) ans--;
    }
    cout << ans << "\n";
}