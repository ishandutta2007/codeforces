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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> a(n), f(N), m(N);
    dsu u1(2*N);
    for (int i = 0; i < n; i++)
        cin >> a[i], f[a[i]] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 1; i*j < N; j++) {
            if (f[i*j]) u1.unite(N+i*j, i);
            if (f[i*j-1]) m[i] = 1;
        }
    map<ll, set<ll>> s;
    for (ll i = 2; i < N; i++)
        for (ll j = 2; i*j < N; j++)
            if (gcd(i, j) == 1 && m[i*j]) {
                debug(i, j);
                s[u1.rep(i)].insert(u1.rep(j));
            }
    for (int i = 2; i < N; i++) {
        // debug(i);
        for (int j = 1; i*j < N; j++) {
            if (f[i*j-1])
                s[u1.rep(N+i*j-1)].insert(u1.rep(i));
        }
    }
    while (q--) {
        ll x, y; cin >> x >> y; x--, y--;
        debug(a[x], a[y]);
        debug(u1.rep(N+a[x]), u1.rep(N+a[y]));
        debug(s[u1.rep(a[x])]);
        debug(s[u1.rep(a[y])]);
        if (u1.query(N+a[x], N+a[y])) {
            cout << "0\n";
        }
        else if (s[u1.rep(N+a[x])].count(u1.rep(N+a[y]))) {
            debug(a[x], a[y]);
            cout << "1\n";
        }
        else if (s[u1.rep(N+a[y])].count(u1.rep(N+a[x]))) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }
}