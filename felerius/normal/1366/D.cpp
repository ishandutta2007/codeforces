// Contest: Educational Codeforces Round 89 (Rated for Div. 2) (https://codeforces.com/contest/1366)
// Problem: D: Two Divisors (https://codeforces.com/contest/1366/problem/D)


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

array<int, 10'000'001> sieve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    reps(i, 2, sz(sieve)) {
        if (sieve[i])
            continue;
        sieve[i] = i;
        for (ll j = (ll)i * i; j < sz(sieve); j += i)
            sieve[j] = i;
    }

    int n; cin >> n;
    vi x(n, -1), y(n, -1);
    rep(c, n) {
        int a; cin >> a;
        int b = a;
        while (b % sieve[a] == 0)
            b /= sieve[a];
        if (b > 1)
            x[c] = b, y[c] = sieve[a];
    }

    trav(xi, x) cout << xi << ' ';
    cout << '\n';
    trav(yi, y) cout << yi << ' ';
    cout << '\n';

    return 0;
}