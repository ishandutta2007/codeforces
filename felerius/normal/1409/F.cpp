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

const int N = 205;

int dp[N][N][N];

void mx(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; string s, t; cin >> n >> k >> s >> t;
    if (t[0] == t[1]) {
        int c = (int)count(all(s), t[0]);
        c = min(n, c + k);
        cout << (c * (c - 1) / 2) << '\n';
        return 0;
    }

    vi a(n);
    rep(i, n)
        a[i] = (s[i] == t[0] ? 0 : (s[i] == t[1] ? 1 : 2));

    rep(i, N) rep(j, N) rep(k, N) dp[i][j][k] = -INF;

    dp[0][0][0] = 0;
    rep(i, n) rep(r, k + 1) rep(f, i + 2) {
        int& dpi = dp[i+1][r][f];
        rep(c, 3) {
            int nr = r - (c != a[i]);
            int nf = f - (c == 0);
            if (nr >= 0 && nf >= 0)
                mx(dpi, dp[i][nr][nf] + (c == 1 ? nf : 0));
        }
    }

    int res = 0;
    rep(r, k + 1) rep(f, n + 1)
        res = max(res, dp[n][r][f]);
    cout << res << '\n';

    return 0;
}