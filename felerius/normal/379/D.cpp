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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

struct Entry {
    ll s1 = 0, s2 = 0;
    ll c[2][2];
    bool lefts2 = false, rights2 = false;

    Entry() {
        c[0][0] = c[0][1] = c[1][0] = c[1][1] = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k,x,n,m; cin >> k >> x >> n >> m;

    vector<Entry> dp(k);
    dp[0].s1 = 1;
    dp[1].s2 = 1;
    dp[1].lefts2 = dp[1].rights2 = true;
    reps(i, 2, k) {
        dp[i].s1 = dp[i-1].s1 + dp[i-2].s1;
        dp[i].s2 = dp[i-1].s2 + dp[i-2].s2;
        rep(a,2) rep(b,2)
            dp[i].c[a][b] = dp[i-1].c[a][b] + dp[i-2].c[a][b];
        dp[i].c[dp[i-2].rights2][dp[i-1].lefts2]++;
        dp[i].lefts2 = dp[i-2].lefts2;
        dp[i].rights2 = dp[i-1].rights2;
    }

    auto y = dp.back();
    rep(s1, n / 2 + 1) rep(s2, m / 2 + 1) {
        rep(a1, 2) rep(c1, 2) rep(a2, 2) rep(c2, 2) {
            if (2 * s1 + a1 + c1 > n)
                continue;
            if (2 * s2 + a2 + c2 > m)
                continue;
            ll c = 0;
            c += y.s1 * s1;
            c += y.s2 * s2;
            c += y.c[0][0] * (a1 && c1);
            c += y.c[0][1] * (a1 && c2);
            c += y.c[1][1] * (a2 && c2);
            c += y.c[1][0] * (a2 && c1);
            if (c != x)
                continue;

            string str1, str2;

            if (c1)
                str1.push_back('C');
            rep(_, s1)
                str1 += "AC";
            while (sz(str1) < n - 1)
                str1.push_back('O');
            if (sz(str1) < n)
                str1.push_back(a1 ? 'A' : 'O');

            if (c2)
                str2.push_back('C');
            rep(_, s2)
                str2 += "AC";
            while (sz(str2) < m - 1)
                str2.push_back('O');
            if (sz(str2) < m)
                str2.push_back(a2 ? 'A' : 'O');

            cout << str1 << '\n' << str2 << '\n';
            return 0;
        }
    }

    cout << "Happy new year!\n";
    return 0;
}