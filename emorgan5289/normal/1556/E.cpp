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

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename iterator_traits<it>::value_type;
    vector<vector<T>> t; bin_op f;

    sparse_table(it first, it last, bin_op op) : f(op) {
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    vector<ll> a(n), b(n), p(n+1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] -= b[i];
        p[i+1] = p[i]+a[i];
    }
    debug(a);
    debug(p);
    sparse_table tmin(all(p), [](ll x, ll y){ return min(x, y); });
    sparse_table tmax(all(p), [](ll x, ll y){ return max(x, y); });
    while (q--) {
        ll l, r; cin >> l >> r; l--, r--;
        if (p[l] != p[r+1] || tmax.query(l, r+1) > p[l])
            cout << "-1\n";
        else {
            cout << p[l]-tmin.query(l, r+1) << "\n";
        }
        debug(l, r);
    }
}