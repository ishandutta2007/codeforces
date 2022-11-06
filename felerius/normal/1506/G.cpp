// Maximize the Remaining String (https://codeforces.com/contest/1506/problem/G)
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
        string s; cin >> s;
        string res;
        array<vector<int>, 26> idx{};
        rep(i, sz(s))
            idx[s[i] - 'a'].push_back(i);
        rep(i, 26)
            reverse(all(idx[i]));

        map<int, vector<int>> m;
        rep(i, 26)
            if (sz(idx[i]))
                m[i] = move(idx[i]);

        while (sz(m)) {
            int c = -1;
            for (auto it = rbegin(m); it != rend(m); ++it) {
                int first = it->second.back();
                bool pos = true;
                for (auto& [c2, id] : m)
                    if (c2 != it->first && id[0] < first)
                        pos = false;
                if (pos) {
                    c = it->first;
                    break;
                }
            }

            res.push_back(char('a' + c));
            int pos = m[c].back();
            m.erase(c);

            for (auto& [c2, id] : m)
                while (id.back() < pos)
                    id.pop_back();
        }

        cout << res << '\n';
    }

    return 0;
}