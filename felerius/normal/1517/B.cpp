// Morning Jogging (https://codeforces.com/contest/1517/problem/B)
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
        int n, m; cin >> n >> m;
        vector b(n, vector<int>(m));
        vector<array<int, 3>> bs;
        rep(i, n) rep(j, m)
            cin >> b[i][j], bs.push_back({b[i][j], i, j});

        sort(all(bs));
        set<pair<int, int>> special;
        rep(x, m) {
            auto [_, i, j] = bs[x];
            special.emplace(i, j);
        }

        vector nxt(n, 0);
        auto it = begin(special);
        vector ans(m, vector<int>(n));

        rep(x, m) {
            auto [si, sj] = *it++;
            rep(i, n) {
                if (i == si) {
                    ans[x][i] = b[si][sj];
                    continue;
                }
                while (special.find(pair(i, nxt[i])) != end(special))
                    ++nxt[i];
                ans[x][i] = b[i][nxt[i]++];
            }
        }

        rep(i, n) rep(j, m)
            cout << ans[j][i] << " \n"[j + 1 == m];
    }

    return 0;
}