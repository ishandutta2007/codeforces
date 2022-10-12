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

struct dsu {

    vector<int> p, sz;

    dsu(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    int rep(int x) {
        while (x != p[x]) x = p[x] = p[p[x]];
        return x;
    }

    // returns true if a and b are in the same set, and then unites them.
    bool unite(int a, int b) {
        a = rep(a), b = rep(b);
        if (sz[a] < sz[b]) swap(a, b);
        if (a != b) p[b] = a, sz[a] += sz[b];
        return a == b;
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

const int N = 3000;
char c[N];
vector<array<int, 2>> e;
vector<int> adj[N];
int d[N], v[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i < n-1) e.pb({i*m+j, (i+1)*m+j});
            if (j < m-1) e.pb({i*m+j, i*m+(j+1)});
        }
    for (int i = 0; i < n*m; i++)
        cin >> c[i];
    dsu u(n*m);
    for (auto& [x, y] : e)
        if (c[x] == c[y]) u.unite(x, y);
    for (auto& [x, y] : e)
        if (!u.query(x, y)) {
            x = u.rep(x), y = u.rep(y);
            debug(x, y);
            adj[x].pb(y), adj[y].pb(x);
        }
    int ans = inf;
    for (int i = 0; i < n*m; i++) {
        int x = u.rep(i);
        fill(v, v+n*m, 0);
        fill(d, d+n*m, 0);
        queue<int> q({x});
        v[x] = d[x] = 1;
        while (!q.empty()) {
            x = q.front(); q.pop();
            for (int j : adj[x])
                if (!v[j]) {
                    debug(x, j);
                    v[j] = 1, d[j] = d[x]+1;
                    q.push(j);
                }
        }
        int r = 0;
        for (int j = 0; j < n*m; j++)
            if (c[j] == 'B') cmax(r, d[j]);
        debug(vector(d, d+n*m));
        cmin(ans, r);
    }
    cout << ans << "\n";
}