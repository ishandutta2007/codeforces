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

const int N = 1e6+5;
int a[N], v[N], ans[N];
map<ll, int> m;
multiset<array<ll, 3>> s, t;
ll n, q, d;

template<typename T>
auto inc(T it) { return ++it; }
template<typename T>
auto dec(T it) { return --it; }

template<typename T>
void check(T l, T r) {
    if ((*l)[2] != (*r)[2])
        t.insert({(*r)[0]-(*l)[0], (*l)[1], (*r)[1]});
}

void upd(int i) {
    v[i] = 1;
    auto it = s.find({a[i], i, 0});
    if (it != s.begin() && it != --s.end())
        check(dec(it), inc(it));
    s.erase(it);
    for (ll x : {a[i]-d, a[i]+d}) {
        it = s.insert({x, i, 1});
        if (it != s.begin()) check(dec(it), it);
        if (it != --s.end()) check(it, inc(it));
    }
}

multiset<array<ll, 4>> qry;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll r; cin >> n >> q >> r >> d; r--;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        s.insert({a[i], i, 0});
    upd(0);
    while (!t.empty()) {
        auto [x, i, j] = *t.begin();
        t.erase(t.begin());
        if (v[i] && v[j]) continue;
        qry.insert({x, 0, i, j});
        debug(x, i, j);
        if (v[i]) upd(j);
        else upd(i);
    }
    for (int i = 0; i < q; i++) {
        ll j, k; cin >> j >> k; j--;
        qry.insert({k, 1, i, j});
    }
    dsu u(n);
    for (auto& [x, b, i, j] : qry) {
        if (b)
            ans[i] = u.query(r, j);
        else
            u.unite(i, j);
    }
    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "YES" : "NO") << "\n";
}