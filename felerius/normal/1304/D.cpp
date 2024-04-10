// Contest: Codeforces Round #620 (Div. 2) (https://codeforces.com/contest/1304)
// Problem: D: Shortest and Longest LIS (https://codeforces.com/contest/1304/problem/D)


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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        vi a = {0}, b = {0};
        int i = 0, amn = 0;

        while (i < sz(s) && s[i] == '<')
            a.push_back(a.back() + 1), ++i;
        while (i < sz(s)) {
            int inc = 0, dec = 0;
            while (i < sz(s) && s[i] == '>')
                ++dec, ++i;
            while (i < sz(s) && s[i] == '<')
                ++inc, ++i;
            int st = amn - 1 - inc;
            rep(j, dec)
                a.push_back(st - j);
            rep(j, inc)
                a.push_back(st + j + 1);
            amn = st - dec + 1;
        }

        i = 0;
        int bmx = 0;
        while (i < sz(s) && s[i] == '>')
            b.push_back(b.back() - 1), ++i;
        while (i < sz(s)) {
            int inc = 0, dec = 0;
            while (i < sz(s) && s[i] == '<')
                ++inc, ++i;
            while (i < sz(s) && s[i] == '>')
                ++dec, ++i;
            int st = bmx + 1 + dec;
            rep(j, inc)
                b.push_back(st + j);
            rep(j, dec)
                b.push_back(st - j - 1);
            bmx = st + inc - 1;
        }

        for (auto& v : {a, b}) {
            auto cop = v;
            sort(all(cop));
            trav(vi, v)
                cout << (lower_bound(all(cop), vi) - begin(cop) + 1) << ' ';
            cout << '\n';
        }
    }

    return 0;
}