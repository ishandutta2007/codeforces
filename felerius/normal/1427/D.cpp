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

vi perform(vi& c, vi& d) {
    vi res(sz(c));
    int i = 0;
    trav(di, d) {
        copy(begin(c) + i, begin(c) + i + di, end(res) - i - di);
        i += di;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi c(n);
    trav(ci, c) cin >> ci;
    bool flipped = n % 2;

    vvi ops;
    rep(i, n) {
        int j = (int)(find(all(c), i + 1) - begin(c));
        vi d;
        if (flipped) {
            if (j)
                d.push_back(j);
            d.push_back(n - i - j);
            rep(_, i)
                d.push_back(1);
        } else {
            rep(_, i)
                d.push_back(1);
            d.push_back(j + 1 - i);
            if (n - j - 1)
                d.push_back(n - j - 1);
        }

        c = perform(c, d);
        flipped = !flipped;

        if (sz(d) > 1)
            ops.push_back(d);
    }

    assert(is_sorted(all(c)));

    cout << sz(ops) << '\n';
    trav(d, ops) {
        cout << sz(d);
        trav(di, d) cout << ' ' << di;
        cout << '\n';
    }

    return 0;
}