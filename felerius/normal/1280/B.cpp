// Contest: Codeforces Round #607 (Div. 1) (https://codeforces.com/contest/1280)
// Problem: B: Beingawesomeism (https://codeforces.com/contest/1280/problem/B)


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

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

arr<bool, 60, 60> g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int r, c; cin >> r >> c;
        char _c;
        rep(i, r) rep(j, c) cin >> _c, g[i][j] = _c == 'A';

        bool all = true;
        rep(i, r) rep(j, c) all &= g[i][j];
        if (all) { cout << "0\n"; continue; }

        arr<bool, 60> ro, co;
        ro.fill(true), co.fill(true);
        rep(i, r) rep(j, c) ro[i] &= g[i][j], co[j] &= g[i][j];

        if (ro[0] || ro[r-1] || co[0] || co[c-1]) { cout << "1\n"; continue; }
        bool rowcol = false;
        rep(i, r) rowcol |= ro[i];
        rep(i, c) rowcol |= co[i];
        if (rowcol) { cout << "2\n"; continue; }

        if (g[0][0] || g[0][c-1] || g[r-1][0] || g[r-1][c-1]) { cout << "2\n"; continue; }
        bool side = false;
        rep(i, r) side |= g[i][0] || g[i][c-1];
        rep(i, c) side |= g[0][i] || g[r-1][i];
        if (side) { cout << "3\n"; continue; }

        bool any = false;
        rep(i, r) rep(j, c) any |= g[i][j];

        cout << (any ? "4\n" : "MORTAL\n");
    }

    return 0;
}