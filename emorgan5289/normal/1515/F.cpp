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

const ll N = 3e5+5;
ll a[N];
set<ll> adj[N];
array<ll, 2> e[N];
vector<int> ans;
multiset<array<ll, 2>, greater<>> s;
dsu u(N);

void merge(int e_id) {
    cout << e_id+1 << "\n";
    auto [x, y] = e[e_id];
    if (u.query(x, y)) {
        debug("bad");
        debug(x, y, e_id, adj[x], adj[y]);
        adj[x].erase(adj[x].find(e_id));
        adj[y].erase(adj[y].find(e_id));
        debug("fixed");
        return;
    }
    x = u.rep(x), y = u.rep(y);
    debug(x, y);
    s.erase(s.find({a[x], x}));
    s.erase(s.find({a[y], y}));
    debug("ok");
    u.unite(x, y);
    ll z = u.rep(x);
    debug(z);
    x = x^y^z;
    if (adj[z].size() < adj[x].size())
        swap(adj[x], adj[z]);
    adj[z].erase(adj[z].find(e_id));
    for (auto& q : adj[x])
        if (q != e_id)
            adj[z].insert(q);
    a[z] += a[x];
    s.insert({a[z], z});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, x; cin >> n >> m >> x;
    ll a_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i] -= x;
        s.insert({a[i], i});
        a_sum += a[i];
    }
    if (a_sum < -x) {
        cout << "NO\n";
        exit(0);
    }
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        int p, q; cin >> p >> q; p--, q--;
        adj[p].insert(i), adj[q].insert(i);
        e[i] = {p, q};
    }
    for (int i = 0; i < n-1; i++) {
        auto [_, j] = *s.begin();
        debug(s, j);
        ll edge = *adj[j].begin();
        while (u.query(e[edge][0], e[edge][1])) {
            adj[j].erase(adj[j].begin());
            edge = *adj[j].begin();
        }
        merge(*adj[j].begin());
    }
}