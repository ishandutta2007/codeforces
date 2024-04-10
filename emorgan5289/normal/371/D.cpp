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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n+1), b(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = inf_ll;
    ll m; cin >> m;

    vector<int> r(n+1);
    iota(all(r), 0);
    dsu u(n+1);

    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            ll p, x; cin >> p >> x; p--;
            while (x > 0) {
                p = r[u.rep(p)];
                if (x >= a[p]-b[p]) {
                    x -= a[p]-b[p];
                    b[p] = a[p];
                    ll q = r[u.rep(p+1)];
                    u.unite(p, p+1);
                    r[u.rep(p)] = q;
                } else {
                    b[p] += x;
                    x = 0;
                }
            }
        } else {
            ll k; cin >> k; k--;
            cout << b[k] << "\n";
        }
    }
}