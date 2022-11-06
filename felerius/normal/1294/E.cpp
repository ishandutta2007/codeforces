// Contest: Codeforces Round #615 (Div. 3) (https://codeforces.com/contest/1294)
// Problem: E: Obtain a Permutation (https://codeforces.com/contest/1294/problem/E)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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

#if __cpp_lib_nonmember_container_access >= 201411
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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

#if __has_cpp_attribute(maybe_unused) >= 201603
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

template <class T, class... Is> struct vec_helper;
template <class T>
struct vec_helper<T> {
    static auto f(T val) { return val; }
};
template <class T, class I, class... Is>
struct vec_helper<T, I, Is...> {
    static auto f(T val, I size, Is... sizes) {
        return vector(size, vec_helper<T, Is...>::f(val, sizes...));
    }
};
template <class T, class... Is>
auto vec(T val, Is... sizes) {
    return vec_helper<T, Is...>::f(val, sizes...);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    auto mat = vec(0, n, m);
    rep(i, n) rep(j, m) cin >> mat[i][j], mat[i][j]--;

    int r = 0;
    rep(i, m) {
        vi s(n);
        rep(j, n) {
            if (mat[j][i] % m == i && mat[j][i] < n * m) {
                int tar = mat[j][i] / m;
                s[(j - tar + n) % n]++;
            }
        }
        int mn = INF;
        rep(j, n)
            mn = min(mn, j + (n - s[j]));
        r += mn;
    }

    cout << r << '\n';
    return 0;
}