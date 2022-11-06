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

// region dimvec
template <class T, class... Is> struct vec_helper;
template <class T> struct vec_helper<T> { static auto f(T val) { return val; } };
template <class T, class I, class... Is> struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is> auto vec(T val, Is... sizes) { return vec_helper<T, Is...>::f(val, sizes...); }
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k, z; cin >> n >> k >> z;
        vi a(n);
        trav(ai, a) cin >> ai;

        int mx = 0;
        rep(i, z + 1) {
            for (auto atend : {false, true}) {
                if (i + atend > z)
                    continue;
                if (1 + 2 * i + atend > k)
                    continue;
                int r = k - 2 * i - atend;
                int sum = 0;
                for (int j = 0; j <= r; ++j)
                    sum += a[j];
                int mxp = 0;
                for (int j = 1; j <= r; ++j)
                    mxp = max(mxp, a[j] + a[j-1]);
                mx = max(mx, sum + i * mxp + (atend ? a[r-1] : 0));
            }
        }
        cout << mx << '\n';
    }

    return 0;
}