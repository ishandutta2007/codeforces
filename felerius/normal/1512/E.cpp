// Permutation by Sum (https://codeforces.com/contest/1512/problem/E)
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
        int n, l, r, s; cin >> n >> l >> r >> s; --l;
        int m = r - l;
        int mn = m * (m + 1) / 2;
        int mx = mn + (n - m) * m;
        if (s < mn || s > mx) {
            cout << "-1\n";
            continue;
        }

        vector p(n, 0);
        rep(i, m)
            p[l + i] = i + 1;
        s -= mn;
        rep(i, m) {
            int d = min(s, n - m);
            p[r - 1 - i] += d;
            s -= d;
        }

        vector<bool> used(n);
        rep(i, l, r)
            used[p[i] - 1] = true;
        int nxt = 0;
        rep(i, n) {
            if (l <= i && i < r)
                continue;
            while (used[nxt]) ++nxt;
            p[i] = ++nxt;
        }

        trav(pi, p)
            cout << pi << ' ';
        cout << '\n';
    }

    return 0;
}