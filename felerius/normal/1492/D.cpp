// Genius's Gambit (https://codeforces.com/contest/1492/problem/D)
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

    //   110001000 (n zeroes)
    // - 100001001
    //   --------
    //   001111111 (n ones)

    // 11000000
    // 00000011
    // --------
    // 10111101

    // 1 00011 1 000111 0
    // 1 00011 0 000111 1
    // 0 00000 0 111111 1

    int a, b, k; cin >> a >> b >> k;
    if (b == 1) {
        if (k != 0)
            cout << "No\n", exit(0);
        string s(a + b, '0');
        s[0] = '1';
        cout << "Yes\n" << s << '\n' << s << '\n';
        return 0;
    }

    if (a == 0) {
        if (k != 0)
            cout << "No\n", exit(0);
        string s(a + b, '1');
        cout << "Yes\n" << s << '\n' << s << '\n';
        return 0;
    }

    if (k >= a + b - 1)
        cout << "No\n", exit(0);

    if (k == 0) {
        string s(a + b, '0');
        rep(i, b)
            s[i] = '1';
        cout << "Yes\n" << s << '\n' << s << '\n';
        return 0;
    }

    int n = a + b;
    string x(a + b, '0'), y = x;
    x[0] = y[0] = '1';
    x[n - k - 1] = '1';
    y.back() = '1';
    b -= 2;

    rep(i, n) {
        if (b == 0)
            break;
        if (i == 0 || i == n - k - 1 || i == n - 1)
            continue;
        x[i] = y[i] = '1';
        b--;
    }

    cout << "Yes\n" << x << '\n' << y << '\n';
    return 0;
}