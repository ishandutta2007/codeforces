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

// call randint() for a random integer
mt19937 randint(chrono::steady_clock::now().time_since_epoch().count());

// returns a random integer over [a, b] inclusive
inline int uniform_randint(const int a, const int b) {
    return uniform_int_distribution<int>(a, b)(randint);
}

// returns a random double from 0 to 1
inline double rand01() {
    return uniform_randint(0, INT_MAX)/double(INT_MAX);
}

// randomly and uniformly select k distinct integers in the range [0..n-1]
// runs in O(klog(n/k))
vector<int> random_sample(int k, int n) {
    vector<int> r(k);
    std::iota(r.begin(), r.end(), 0);
    double w = exp(log(rand01())/k);
    int i = k-1;
    while (i < n) {
        i += 1+floor(log(rand01())/log(1-w));
        if (i < n) {
            r[uniform_randint(0, k-1)] = i;
            w *= exp(log(rand01())/k);
        }
    }
    return r;
}

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
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i]--;
        debug(a);
        set<ll> s;
        for (int tt = 0; tt < 60; tt++) {
            ll x = uniform_randint(0, n-1);
            vector<ll> p(n);
            for (int i = 0; i < n; i++)
                p[i] = (a[x]+(i-x)+n)%n;
            dsu u(n);
            for (int i = 0; i < n; i++)
                u.unite((a[x]+(i-x)+n)%n, a[i]);
            ll c = n;
            for (int i = 0; i < n; i++)
                if (i == u.rep(i)) c--;
            if (c <= m) {
                s.insert((n-(a[x]-x+n)%n+n)%n);
            }
        }
        cout << s.size();
        for (int x : s) {
            cout << " " << (x);
        }
        cout << "\n";
    }
}