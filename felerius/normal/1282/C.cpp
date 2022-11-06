// Contest: Codeforces Round #610 (Div. 2) (https://codeforces.com/contest/1282)
// Problem: C: Petya and Exam (https://codeforces.com/contest/1282/problem/C)


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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    while (m--) {
        int n, t, a, b; cin >> n >> t >> a >> b;
        vector<int> hard(n);
        trav(hi, hard) cin >> hi;
        vi et(n);
        trav(ti, et) cin >> ti;
        int num_hard = accumulate(all(hard), 0), num_easy = n - num_hard;
        if ((ll)b * num_hard + (ll)a * num_easy <= t) {
            cout << n << '\n';
            continue;
        }

        vector<pi> evt;
        rep(i, n)
            evt.emplace_back(et[i], hard[i]);
        sort(all(evt));

        ll mx = 0;
        if (evt.front().first > 0) {
            int ti = evt.front().first - 1;
            int easy = min(ti / a, num_easy);
            int hard = min((ti - easy * a) / b, num_hard);
            mx = easy + hard;
        }
        ll ce = 0, ch = 0;
        rep(i, n) {
            auto [ti, h] = evt[i];
            (h ? ch : ce)++;
            ll next_time = i + 1 == n ? t : evt[i+1].first;
            if (ti < next_time) {
                ll time = next_time - 1;
                ll mint = ce * a + ch * b;
                if (mint <= time) {
                    time -= mint;
                    ll extra_easy = min((ll)time / a, num_easy - ce);
                    time -= extra_easy * a;
                    ll extra_hard = min((ll)time / b, num_hard - ch);
                    mx = max(mx, ce + ch + extra_easy + extra_hard);
                }
            }
        }
        cout << mx << '\n';
    }

    return 0;
}