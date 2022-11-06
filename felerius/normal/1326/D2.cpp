// Contest: Codeforces Global Round 7 (https://codeforces.com/contest/1326)
// Problem: D1: Prefix-Suffix Palindrome (Easy version) (https://codeforces.com/contest/1326/problem/D1)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

array<vi, 2> manacher(string& s) {
    int n = sz(s);
    array<vi, 2> p = {vi(n + 1), vi(n)};
    reps(z, 0, 2) {
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            int t = r - i + !z;
            if (i < r)
                p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, --L, ++R;
            if (R > r)
                l = L, r = R;
        }
    }
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int l = 0, n = sz(s);
        while (l < n - 1 - l && s[l] == s[n - 1 - l])
            ++l;
        string s2;
        copy(begin(s) + l, end(s) - l, back_inserter(s2));
        auto [even, odd] = manacher(s2);
        pair<int, pi> mx = {0, pi(0, 0)};
        rep(i, sz(s2) + 1) {
            int le = i - even[i];
            int ri = i + even[i];
            if (le == 0 || ri == sz(s2))
                mx = max(mx, pair(ri - le, pair(le, ri)));
        }
        rep(i, sz(s2)) {
            int le = i - odd[i];
            int ri = i + odd[i] + 1;
            if (le == 0 || ri == sz(s2))
                mx = max(mx, pair(ri - le, pair(le, ri)));
        }
        auto [x, y] = mx.second;
        cout << s.substr(0, l) << s2.substr(x, y) << s.substr(n - l) << '\n';
    }

    return 0;
}