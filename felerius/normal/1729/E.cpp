// Guess the Cycle Size (https://codeforces.com/contest/1729/problem/E)
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

int main() {
    rep(i, 2, 52) {
        ll d1, d2;
        cout << "? 1 " << i << '\n' << flush;
        cin >> d1;
        cout << "? " << i << " 1\n" << flush;
        cin >> d2;

        if (d1 == -1)
            cout << "! " << i - 1 << '\n', exit(0);
        else if (d1 != d2)
            cout << "! " << d1 + d2 << '\n', exit(0);
    }
}