// Restore Modulo (https://codeforces.com/contest/1484/problem/B)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector a(n, 0);
        trav(ai, a) cin >> ai;
        if (n == 1) {
            cout << "0\n";
            continue;
        }

        if (is_sorted(all(a)) || is_sorted(rbegin(a), rend(a))) {
            int d = a[1] - a[0];
            bool all = true;
            rep(i, 2, n)
                all &= (a[i] - a[i - 1] == d);
            if (all)
                cout << "0\n";
            else
                cout << "-1\n";
            continue;
        }

        int incr = 0;
        rep(i, 1, n)
            if (a[i] > a[i - 1])
                incr = a[i] - a[i - 1];

        int i = 1;
        while (a[i] > a[i - 1])
            ++i;
        // a[i - 1] + incr = a[i] mod m
        // a[i - 1] + incr = a[i] + m
        // a[i - 1] + incr = a[i] + m
        // m = a[i - 1] + incr - a[i]
        int m = a[i - 1] + incr - a[i];
        bool all = true;
        rep(j, n)
            all &= a[j] < m;
        rep(j, 1, n)
            all &= ((a[j - 1] + incr) % m == a[j]);

        if (all)
            cout << m << ' ' << incr << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}