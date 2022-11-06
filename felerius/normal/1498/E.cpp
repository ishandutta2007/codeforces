// Two Houses (https://codeforces.com/contest/1498/problem/E)
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
    vector k(n, 0);
    trav(ki, k) cin >> ki;

    vector<pair<int, int>> pairs;
    rep(i, n) rep(j, i + 1, n)
        pairs.emplace_back(i, j);
    sort(all(pairs), [&](auto& p1, auto& p2) {
        return abs(k[p1.first] - k[p1.second]) > abs(k[p2.first] - k[p2.second]);
    });

    for (auto [i, j] : pairs) {
        if (k[i] < k[j]) swap(i, j);
        cout << "? " << (i + 1) << ' ' << (j + 1) << '\n' << flush;
        string s; cin >> s;
        if (s[0] == 'Y')
            cout << "! " << (i + 1) << ' ' << (j + 1) << '\n', exit(0);
    }

    cout << "! 0 0\n";
    return 0;
}