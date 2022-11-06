// Card Deck (https://codeforces.com/contest/1492/problem/B)
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
        vector p(n, 0);
        trav(pi, p) cin >> pi;
        set<int> rem(all(p));
        vector<int> ans;

        while (sz(p)) {
            auto mx = *rbegin(rem);
            int c = 0;
            while (p[sz(p) - 1 - c] != mx)
                ++c;
            rep(i, sz(p) - 1 - c, sz(p))
                ans.push_back(p[i]), rem.erase(p[i]);
            p.erase(end(p) - 1 - c, end(p));
        }

        trav(ai, ans)
            cout << ai << ' ';
        cout << '\n';
    }

    return 0;
}