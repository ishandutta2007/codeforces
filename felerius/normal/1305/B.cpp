// Contest: Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!) (https://codeforces.com/contest/1305)
// Problem: B: Kuroni and Simple Strings (https://codeforces.com/contest/1305/problem/B)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vvi ops;
    vector<bool> del(size(s));
    while (true) {
        vi open, close;
        int i = 0, j = size(s) - 1;
        while (i < j) {
            while (i < j && s[i] != '(')
                ++i;
            while (i < j && s[j] != ')')
                --j;
            if (i < j)
                open.push_back(i++), close.push_back(j--);
        }
        if (!sz(open))
            break;
        fill(all(del), false);
        ops.emplace_back();
        trav(i, open)
            ops.back().push_back(i), del[i] = true;
        reverse(all(close));
        trav(i, close)
            ops.back().push_back(i), del[i] = true;
        string s2;
        for (int i = 0; i < size(s); ++i)
            if (!del[i])
                s2.push_back(s[i]);
        s = s2;
    }

    cout << size(ops) << '\n';
    trav(v, ops) {
        cout << size(v) << '\n';
        trav(vi, v)
            cout << (vi + 1) << ' ';
        cout << '\n';
    }

    return 0;
}