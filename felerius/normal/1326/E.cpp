// Contest: Codeforces Global Round 7 (https://codeforces.com/contest/1326)
// Problem: E: Bombs (https://codeforces.com/contest/1326/problem/E)


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

struct SegTree {
    struct T {
        int mx, sum;
    };
    static constexpr T UNIT = {0, 0};
    static T combine(T& a, T& b) {
        return {max(a.mx + b.sum, b.mx), a.sum + b.sum};
    }

    int k = 1;
    vector<T> d;

    explicit SegTree(int n) {
        while (k < n) k *= 2;
        d = vector(2 * k, UNIT);
    }

    T& root() { return d[1]; }
    T& leaf(int i) { return d[k + i]; }

    void update(int i, int val) {
        d[i + k] = {val, val};
        for (int j = i + k; j /= 2;)
            d[j] = combine(d[2*j], d[2*j+1]);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi p(n), q(n), pos(n);
    rep(i, n) cin >> p[i], pos[--p[i]] = i;
    trav(qi, q) cin >> qi, --qi;

    SegTree s(2 * n);
    cout << n << ' ';
    int mx = n;
    rep(i, n - 1) {
        s.update(2 * q[i] + 1, -1);
        while (s.root().mx <= 0)
            s.update(2 * pos[--mx], 1);
        cout << (mx + 1) << ' ';
    }
    cout << '\n';

    return 0;
}