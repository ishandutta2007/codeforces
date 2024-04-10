// Domino (hard version) (https://codeforces.com/contest/1551/problem/D2)
#pragma GCC optimize("fast-math")
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        vector id(n, vector(m, -1));

        int next_id = 0;
        if (n % 2) {
            if (k < m / 2) { cout << "NO\n"; continue; }
            k -= m / 2;
            for (int i = 0; i + 1 < m; i += 2)
                id[0][i] = id[0][i + 1] = next_id++;
        }

        if (k % 2) { cout << "NO\n"; continue; }
        for (int i = n % 2; k && i + 1 < n; i += 2)
            for (int j = m % 2; k && j + 1 < m; j += 2)
                id[i][j] = id[i][j + 1] = next_id++, id[i + 1][j] = id[i + 1][j + 1] = next_id++, k -= 2;
        if (k) { cout << "NO\n"; continue; }

        if (m % 2)
            for (int i = 0; i + 1 < n; i += 2)
                id[i][0] = id[i + 1][0] = next_id++;

        vector ans(n, string(m, ' '));
        rep(i, n) rep(j, m) {
            if (ans[i][j] != ' ')
                continue;
            char c = char('a' + (i + j) % 26);
            if (i + 1 < n && id[i][j] == id[i + 1][j])
                ans[i][j] = ans[i + 1][j] = c;
            else
                ans[i][j] = ans[i][j + 1] = c;
        }

        cout << "YES\n";
        trav(row, ans)
            cout << row << '\n';
    }
}