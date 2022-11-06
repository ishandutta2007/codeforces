// Planet Lapituletti (https://codeforces.com/contest/1493/problem/B)
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

    vector<int> mirror = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
    int t; cin >> t;
    while (t--) {
        int H, M; cin >> H >> M;
        string s; cin >> s;
        int h = (s[0] - '0') * 10 + (s[1] - '0'), m = (s[3] - '0') * 10 + (s[4] - '0');
        while (1) {
            bool valid = mirror[h/10] != -1 && mirror[h%10] != -1 && mirror[m/10] != -1 && mirror[m%10] != -1;
            if (valid) {
                int h2 = mirror[m%10] * 10 + mirror[m/10], m2 = mirror[h%10] * 10 + mirror[h/10];
                valid = h2 < H && m2 < M;
            }
            if (valid)
                break;
            ++m;
            if (m == M)
                ++h, m = 0;
            if (h == H)
                h = 0;
        }

        cout << (h / 10) << (h % 10) << ':' << (m / 10) << (m % 10) << '\n';
    }

    return 0;
}