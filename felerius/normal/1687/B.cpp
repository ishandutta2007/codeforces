// Railway System (https://codeforces.com/contest/1687/problem/B)
#pragma GCC optimize("fast-math")

#include <bits/stdc++.h>
#if __has_include("dbg.h")
#  include "dbg.h"
#else
#  define dbg(...) do {} while (0)
#endif

#define cp_lib_4th(_1, _2, _3, x, ...)  x
#define cp_lib_rep(i, l, r)             for (int i = (l); (i) < (r); ++(i))
#define cp_lib_rep0(i, r)               cp_lib_rep(i, 0, r)
#define rep(...)                        cp_lib_4th(__VA_ARGS__, cp_lib_rep, cp_lib_rep0, _)(__VA_ARGS__)
#define cp_lib_repr(i, r, l, ...)       for (int i = (r); (i) >= (l); --(i))
#define repr(...)                       cp_lib_repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : (b))

using namespace std;
using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }

ll ask(string_view s) {
    cout << "? " << s << '\n' << flush;
    ll a; cin >> a;
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector l(m, 0);
    string s(m, '0');
    rep(i, m) {
        s[i] = '1';
        l[i] = int(ask(s));
        s[i] = '0';
    }

    vector idx(m, 0);
    iota(all(idx), 0);
    sort(all(idx), [&](int i, int j) {
        return l[i] > l[j];
    });

    fill(all(s), '1');
    ll expected = ask(s);
    idx.pop_back();
    trav(i, idx) {
        s[i] = '0';
        ll actual = ask(s);
        if (expected - l[i] == actual)
            s[i] = '1';
        else
            expected = actual;
    }

    cout << "! " << expected << '\n';
}