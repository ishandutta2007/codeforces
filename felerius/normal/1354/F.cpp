// Contest: Educational Codeforces Round 87 (Rated for Div. 2) (https://codeforces.com/contest/1354)
// Problem: F: Summoning Minions (https://codeforces.com/contest/1354/problem/F)


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

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi a(n), b(n);
        rep(i, n)
            cin >> a[i] >> b[i];
        vi idx(n);
        iota(all(idx), 0);
        sort(all(idx), [&](int i, int j) { return b[i] < b[j]; });
        ll mx = 0;
        vi seq;
        rep(i, n) {
            auto dp = vec(-INFL, n, k);
            dp[0][0] = (k - 1) * b[idx[i]] + a[idx[i]];
            rep(j, n) {
                if (i == j)
                    continue;
                int ji = j + (j < i);
                dp[ji][0] = dp[ji-1][0] + (k - 1) * b[idx[j]];
                reps(x, 1, k)
                    dp[ji][x] = max(
                        dp[ji-1][x] + (k - 1) * b[idx[j]],
                        dp[ji-1][x-1] + (x - 1) * b[idx[j]] + a[idx[j]]
                    );
            }
            if (dp[n - 1][k - 1] > mx) {
                mx = dp[n - 1][k - 1];
                seq.clear();
                int x = k - 1;
                for (int j = n - 1; j >= 0; --j) {
                    if (j == i)
                        continue;
                    int ji = j + (j < i);
                    if (x && dp[ji][x] == dp[ji-1][x-1] + (x - 1) * b[idx[j]] + a[idx[j]])
                        --x, seq.insert(begin(seq), idx[j] + 1);
                    else
                        seq.push_back(idx[j] + 1), seq.push_back(-idx[j] - 1);
                }
                seq.push_back(idx[i] + 1);
            }
        }

        cout << sz(seq) << '\n';
        trav(i, seq)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}