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

multiset<ll> large, small;
ll large_sum;

void inc() {
    auto it = --small.end();
    large_sum += *it;
    debug("inc", *it);
    large.insert(*it);
    small.erase(it);
}

void ins(ll x) {
    debug("ins", x);
    large.insert(x);
    large_sum += x;
    auto it = large.begin();
    small.insert(*it);
    large_sum -= *it;
    large.erase(it);
}

void rem(ll x) {
    debug("rem", x);
    debug(small, large);
    if (large.find(x) != large.end()) {
        auto it = large.find(x);
        large_sum -= *it;
        large.erase(it);
        inc();
    } else {
        auto it = small.find(x);
        small.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, d; cin >> n >> d;
    dsu u(n);
    set<array<ll, 2>> s;
    for (int i = 0; i < n; i++)
        s.insert({-1, i}), small.insert(1);
    for (int i = 0; i < 100; i++)
        small.insert(0);
    inc();
    while (d--) {
        ll x, y; cin >> x >> y; x--, y--;
        if (!u.query(x, y)) {
            debug(x, y);
            x = u.rep(x), y = u.rep(y);
            s.erase(s.find({-u.size(x), x}));
            s.erase(s.find({-u.size(y), y}));
            rem(u.size(x));
            rem(u.size(y));
            u.unite(x, y);
            x = u.rep(x);
            s.insert({-u.size(x), x});
            ins(u.size(x));
        } else {
            inc();
        }
        cout << large_sum-1 << "\n";
    }
}