// region boilerplate
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
//endregion

ll f(ll a) {
    ll b = 2 * a;
    ll c = a ^ b;
    return (a + c) ^ (a + b);
}

int find(ll a) {
    rep(i, 100) {
        if ((f(a) ^ a) == 2)
            return i;
        if (a >= (ll)1e18)
            break;
        a = f(a);
    }
    return -1;
}

pi findfind(ll a) {
    for (int i = 1; i < 300; i += 2) {
        int x = find(i * a);
        if (x != -1)
            return {i, x};
    }
    assert(false);
}

vector<tuple<ll, char, ll>> ops;

void plus_(ll a, ll b) {
    ops.emplace_back(a, '+', b);
}

void xor_(ll a, ll b) {
    ops.emplace_back(a, '^', b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* for (int i = 1; i < 1'000'000; i += 2) { */
    /*     auto [a, b] = findfind(i); */
    /*     ll x = a * (ll)i; */
    /*     rep(_, b) */
    /*         x = f(x); */
    /*     assert((f(x) ^ x) == 2); */
    /* } */

    ll x; cin >> x;
    ll xrem = x;
    auto [a, b] = findfind(x);
    rep(i, a-1)
        plus_(x, (i + 1) * x);
    x *= a;
    ll xprev = x;
    rep(_, b + 1) {
        ll c = x ^ (2 * x);
        plus_(x, x);
        xor_(x, 2 * x);
        plus_(x, c);
        plus_(x, 2 * x);
        xor_(x + c, 3 * x);
        xprev = x;
        x = f(x);
    }

    xor_(xprev, x);
    reps(i, 1, 25) {
        if ((xrem >> i) & 1) {
            xor_(xrem, 1 << i);
            xrem ^= 1 << i;
        }
        plus_(1 << i,  1 << i);
    }

    cout << sz(ops) << '\n';
    for (auto [a, o, b] : ops)
        cout << a << ' ' << o << ' ' << b << '\n';

    return 0;
}