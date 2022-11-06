// Contest: Educational Codeforces Round 86 (Rated for Div. 2) (https://codeforces.com/contest/1342)
// Problem: C: Yet Another Counting Problem (https://codeforces.com/contest/1342/problem/C)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        ll a, b; int q; cin >> a >> b >> q;
        ll lc = lcm(a, b);
        vi lci(lc);
        rep(i, lc)
            lci[i] += ((i % a) % b) != ((i % b) % a);
        ll lccnt = accumulate(all(lci), 0ll);
        vi lcisuff(all(lci)), lcipref(all(lci));
        reps(i, 1, lc)
            lcipref[i] += lcipref[i-1];
        for (int i = lc - 2; i >= 0; --i)
            lcisuff[i] += lcisuff[i+1];
        while (q--) {
            ll l, r; cin >> l >> r;
            ++r;
            ll r2 = r - r % lc;
            ll l2 = l + (lc - l % lc) % lc;
            if (r2 < l2) {
                l %= lc;
                r %= lc;
                ll cnt = lcipref[r - 1] - (l ? lcipref[l-1] : 0);
                cout << cnt << ' ';
                continue;
            }
            ll cnt = lccnt * ((r2 - l2) / lc);
            if (l2 > l)
                cnt += lcisuff[lc - (l2 - l)];
            if (r > r2)
                cnt += lcipref[r - r2 - 1];
            cout << cnt << ' ';
        }
        cout << '\n';
    }

    return 0;
}