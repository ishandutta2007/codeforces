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

// vector<ll> p = {1, 2, 8, 9, 7, 0, 3, 6, 5, 4};
// 3 2 4 7 8 9 6 1 0 5

bool qry(ll x, ll y) {
    cout << "1 " << x << " " << y << endl;
    ll r; cin >> r;
    return r;
}

bool qry(ll x, vector<ll> y) {
    cout << "2 " << x << " " << y.size();
    for (ll z : y) cout << " " << z;
    cout << endl;
    ll r; cin >> r;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a = {0};
        for (int i = 1; i < n; i++) {
            if (qry(a.back(), i))
                a.pb(i);
            else if (qry(i, a[0]))
                a.insert(a.begin(), i);
            else {
                int l = 0, r = a.size()-1;
                while (l+1 < r) {
                    int m = (l+r)/2;
                    if (qry(a[m], i)) l = m;
                    else r = m;
                }
                a.insert(a.begin()+r, i);
            }
            debug(a);
        }
        // so far, 7n q1, 0 q2
        debug(a);
        dsu u(n);
        for (int i = 1; i < n; i++) {
            int j = i-1;
            while (1) {
                vector<ll> v;
                for (int k = 0; k <= j; k++)
                    v.pb(a[k]);
                if (!qry(a[i], v)) break;
                u.unite(a[i], a[j]);
                while (j >= 0 && u.query(a[i], a[j])) j--;
                if (j < 0) break;
            }
        }
        cout << "3\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (u.query(i, j) || find(all(a), i) < find(all(a), j))
                    cout << "1";
                else
                    cout << "0";
            }
            cout << endl;
        }
        ll r; cin >> r;
    }
}