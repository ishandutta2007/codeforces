// Binary Literature (https://codeforces.com/contest/1508/problem/A)
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

int subseq(string_view a, string_view b) {
    int i = 0, j = 0;
    while (i < sz(a)) {
        if (a[i] == b[j])
            ++i, ++j;
        else
            ++i;
    }

    return j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        array<string, 3> s{};
        array<int, 3> idx{};
        trav(si, s) cin >> si;

        string r;
        while (*max_element(all(idx)) < 2 * n) {
            int c1 = (s[0][idx[0]] == '1') + (s[1][idx[1]] == '1') + (s[2][idx[2]] == '1');
            bool one = (c1 > 1);
            r.push_back(char('0' + one));
            rep(i, 3)
                if (s[i][idx[i]] == r.back())
                    ++idx[i];
        }

        auto [mn_it, mx_it] = minmax_element(all(idx));
        if (*mn_it < 2 * n) {
            auto it0 = begin(idx), it1 = it0 + 1;
            int append = -1;
            if (it0 != mn_it && it0 != mx_it)
                append = 0;
            else if (it1 != mn_it && it1 != mx_it)
                append = 1;
            else
                append = 2;

            rep(i, idx[append], 2 * n)
                r.push_back(s[append][i]);
        }

        cout << r << '\n';
    }

    return 0;
}