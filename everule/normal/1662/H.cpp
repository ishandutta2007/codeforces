#ifndef LOCAL
    #pragma GCC optimize("O3,unroll-loops")
    #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("avx2,sse4.2,bmi,bmi2,popcnt,lzcnt")
#endif

#include "bits/stdc++.h"

#ifdef DEBUG
    #include "includes/debug/debug.hpp"
#else
    #define debug(...) 0
#endif

using ll = int64_t;
using ull = uint64_t;
using ld = long double;

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    // cout << setprecision(20) << fixed;
    int _tests = 1;
    cin >> _tests;
    for (int _test = 1; _test <= _tests; ++_test) {
        // cout << "Case #" << _test << ": ";
        int w, l;
        cin >> w >> l;
        int a[]{gcd(w, l - 2), gcd(w - 2, l), gcd(w - 1, l - 1),
                gcd(gcd(w, w - 2), l - 1), gcd(gcd(l, l - 2), w - 1)};
        set<int> s;
        for (auto x : a) {
            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    s.insert(i);
                    s.insert(x / i);
                }
            }
        }
        cout << s.size() << ' ';
        for (auto x : s) cout << x << ' ';
        cout << '\n';
    }
}