// Contest: Codeforces Round #620 (Div. 2) (https://codeforces.com/contest/1304)
// Problem: F1: Animal Observation (easy version) (https://codeforces.com/contest/1304/problem/F1)


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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vl> d(n, vl(m));
    trav(row, d) trav(v, row) cin >> v;
    trav(row, d)
        reps(i, 1, m)
            row[i] += row[i-1];
    d.emplace_back(vl(m));

    int w = m - k + 1;
    if (n == 1) {
        ll mx = 0;
        rep(i, w)
            mx = max(mx, d[0][i+k-1] - (i ? d[0][i-1] : 0));
        cout << mx << '\n';
        return 0;
    }

    vl dp(w), dpp(w);
    rep(i, w)
        dpp[i] = d[0][i + k - 1] + d[1][i + k - 1] - (i ? d[0][i-1] + d[1][i-1] : 0);

    reps(i, 1, n) {
        set<pair<ll, int>> maxes;
        rep(j, w) {
            pair<ll, int> p = {dpp[j], j};
            if (sz(maxes) < 2 * k)
                maxes.emplace(p);
            else {
                if (p > *begin(maxes))
                    maxes.erase(begin(maxes)), maxes.emplace(p);
            }
        }
        vector<pair<ll, int>> maxesv(all(maxes));
        reverse(all(maxesv));

        rep(j, w) {
            ll onlast = d[i][j+k-1] - (j ? d[i][j-1] : 0);
            int x = 0; ll mx = -INFL;
            while (x < sz(maxesv) && mx == -INFL) {
                if (abs(maxesv[x].second - j) >= k)
                    mx = maxesv[x].first;
                ++x;
            }

            for (int y = max(0, j - k + 1); y < min(w, j + k); ++y) {
                int r = min(j + k - 1, y + k - 1);
                int l = max(j - 1, y - 1);
                ll over = d[i][r] - (l >= 0 ? d[i][l] : 0);
                mx = max(mx, dpp[y] - over);
            }

            dp[j] = d[i+1][j + k - 1] - (j ? d[i+1][j - 1] : 0) + mx + onlast;
        }

        swap(dp, dpp);
    }

    cout << *max_element(all(dpp)) << '\n';
    return 0;
}