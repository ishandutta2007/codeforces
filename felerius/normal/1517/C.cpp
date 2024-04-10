// Fillomino 2 (https://codeforces.com/contest/1517/problem/C)
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

    int n; cin >> n;
    vector p(n, 0);
    trav(pi, p) cin >> pi, --pi;

    vector open(n, set<pair<int, int>>());
    vector g(n, vector(n, -1));
    rep(i, n) {
        g[i][i] = p[i];
        if (i)
            open[p[i]].emplace(i, i - 1);
        if (i + 1 < n)
            open[p[i]].emplace(i + 1, i);
    }

    int rem = (n * n - n) / 2;
    vector remper(n, 0);
    rep(i, n)
        remper[i] = i;

    rep(_, rem) {
        int j = 0;
        while (j < n && (remper[j] == 0 || sz(open[j]) != 1))
            ++j;
        if (j == n)
            cout << "-1\n", exit(0);

        auto [a, b] = *begin(open[j]);
        g[a][b] = j;
        remper[j]--;

        rep(i, n)
            open[i].erase(pair(a, b));

        for (auto [da, db] : {pair(-1,0), {1,0}, {0,-1}, {0,1}})
            if (0 <= a + da && a + da < n && 0 <= b + db && b + db < n && g[a+da][b+db] == -1)
                open[j].emplace(a + da, b + db);
    }

    rep(i, n) rep(j, i + 1)
        cout << (g[i][j] + 1) << " \n"[j == i];

    return 0;
}