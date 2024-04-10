// Guessing the Greatest (easy version) (https://codeforces.com/contest/1486/problem/C1)
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

int ask(int l, int r) {
    if (l + 1 == r) return r;
    cout << "? " << (l + 1) << ' ' << r << '\n' << flush;
    int i; cin >> i;
    return i - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int x = ask(0, n);
    if (x < n - 1 && ask(x, n) == x) {
        int l = x, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (ask(x, m) == x ? r : l) = m;
        }
        cout << "! " << r << '\n';
    } else {
        int l = 0, r = x;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (ask(m, x + 1) == x ? l : r) = m;
        }
        cout << "! " << (l + 1) << '\n';
    }

    return 0;
}