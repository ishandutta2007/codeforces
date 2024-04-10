// K-beautiful Strings (https://codeforces.com/contest/1493/problem/C)
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

string solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    if (n % k)
        return "-1";

    array<int, 26> cnt{};
    trav(c, s)
        cnt[c - 'a']++;
    if (all_of(all(cnt), [&](int i) { return i % k == 0; }))
        return s;

    repr(i, n - 1) {
        int co = s[i] - 'a';
        cnt[co]--;
        int rem = n - i - 1;
        rep(j, co + 1, 26) {
            cnt[j]++;
            int req = 0;
            rep(x, 26)
                if (cnt[x] % k)
                    req += k - cnt[x] % k;
            if (req > rem) {
                cnt[j]--;
                continue;
            }

            s[i] = char('a' + j);
            int y = i + 1;
            rep(_, rem - req)
                s[y++] = 'a';
            rep(x, 26)
                if (cnt[x] % k)
                    rep(_, k - cnt[x] % k)
                        s[y++] = char('a' + x);
            return s;
        }
    }

    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        cout << solve() << '\n';

    return 0;
}