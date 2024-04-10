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

vector<int> toposort(vector<vector<int>> adj) {
    vector<int> out, stk, in(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
        for (int j : adj[i]) in[j]++;
    for (int i = 0; i < adj.size(); i++)
        if (!in[i]) stk.push_back(i);
    while (!stk.empty()) {
        out.pb(stk.back()); stk.pop_back();
        for (int j : adj[out.back()])
            if (!--in[j]) stk.push_back(j);
    }
    return out;
}

const int N = 3e5+5;
int p[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> adj(n), adj2(n);
    dsu u(n);
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), u.unite(x, y);
    }
    auto t = toposort(adj);
    if (t.size() != n) cout << "0\n", exit(0);
    vector<int> r(n);
    for (int i = 0; i < n; i++)
        r[t[i]] = i;
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) continue;
        if (u.query(p[i], i)) {
            if (r[p[i]] > r[i]) cout << "0\n", exit(0);
        } else
            adj2[u.rep(p[i])].pb(u.rep(i));
    }
    vector<vector<int>> g(n);
    for (auto& x : t)
        g[u.rep(x)].pb(x);
    auto t2 = toposort(adj2);
    vector<int> out;
    for (auto& x : t2)
        for (auto& i : g[x])
            out.pb(i);
    if (out.size() != n) cout << "0\n", exit(0);
    for (int i = 0; i < n; i++)
        cout << out[i]+1 << " \n"[i == n-1];
}