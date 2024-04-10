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

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename remove_reference<decltype(*declval<it>())>::type;
    vector<vector<T>> t; bin_op f;

    sparse_table(it first, it last, bin_op op) : t(1), f(op) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    // returns f(a[l..r]) in O(1) time
    T query(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, p; cin >> n >> p;
        ll ans = 0;
        vector<ll> a(n), o(n);
        iota(all(o), 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(all(o), [&](int i, int j){ return a[i] < a[j]; });
        sparse_table gcd_t(all(a), [&](ll i, ll j){ return __gcd(i, j); });
        sparse_table min_t(all(a), [&](ll i, ll j){ return min(i, j); });
        set<int> s;
        for (int i = 0; i < n-1; i++)
            s.insert(i);
        for (int i : o) {
            if (a[i] >= p) break;
            int l = i, r = i;
            for (int j = 1<<20; j > 0; j >>= 1) {
                if (r+j < n && min_t.query(i, r+j) == a[i] && gcd_t.query(i, r+j) == a[i])
                    r += j;
                if (l-j >= 0 && min_t.query(l-j, i) == a[i] && gcd_t.query(l-j, i) == a[i])
                    l -= j;
            }
            while (s.lower_bound(l) != s.end() && *s.lower_bound(l) < r) {
                s.erase(s.lower_bound(l));
                ans += a[i];
            }
        }
        cout << ans+p*s.size() << "\n";
    }
}