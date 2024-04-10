// 1D Sokoban (https://codeforces.com/contest/1494/problem/C)
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

int solve(vector<int>& a, vector<int>& b) {
    if (!sz(b)) return 0;
    sort(all(a));
    sort(all(b));

    auto it = begin(a);
    int cnt = 0;
    vector<int> last(sz(b));
    vector<bool> box_on(sz(b));
    rep(i, sz(b)) {
        while (it != end(a) && *it < b[i])
            ++cnt, ++it;
        if (it != end(a) && *it == b[i]) {
            ++cnt;
            box_on[i] = true;
            ++it;
        }
        last[i] = b[i] - cnt;
    }

    vector<int> boxes_after(sz(b) + 1);
    repr(i, sz(b) - 1)
        boxes_after[i] = boxes_after[i + 1] + box_on[i];

    int mx = 0;
    rep(i, sz(b)) {
        auto itb = upper_bound(all(b), last[i]);
        mx = max(mx, i + 1 - int(itb - begin(b)) + boxes_after[i + 1]);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a1, a2, b1, b2;
        rep(_, n) {
            int ai; cin >> ai;
            (ai < 0 ? a1 : a2).push_back(abs(ai));
        }
        rep(_, m) {
            int bi; cin >> bi;
            (bi < 0 ? b1 : b2).push_back(abs(bi));
        }

        cout << (solve(a1, b1) + solve(a2, b2)) << '\n';
    }

    return 0;
}