// Contest: Codeforces Round #613 (Div. 2) (https://codeforces.com/contest/1285)
// Problem: E: Delete a Segment (https://codeforces.com/contest/1285/problem/E)


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

#if __cplusplus >= 201703L
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

#if __cplusplus >= 201703L
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

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vpi seg(n);
        vector<tuple<int, bool, int>> evt;
        rep(i, n) {
            int l, r; cin >> l >> r;
            seg[i] = {l, r};
            evt.emplace_back(l, false, i);
            evt.emplace_back(r, true, i);
        }
        sort(all(evt));
        vi alone(n);
        int cnt = 0;
        set<int> active;
        vector<bool> was_connected(n);
        bool all_disconnected = true;
        for (auto [x, is_end, i] : evt) {
            if (is_end)
                active.erase(i);
            else {
                if (sz(active) == 0)
                    cnt++;
                else if (sz(active) == 1) {
                    int j = *begin(active);
                    if (was_connected[j])
                        alone[j]++;
                    else
                        was_connected[j] = true;
                }
                was_connected[i] = sz(active);
                active.emplace(i);
            }
            all_disconnected &= sz(active) < 2;
        }

        if (all_disconnected)
            cout << (cnt - 1) << '\n';
        else
            cout << (cnt + *max_element(all(alone))) << '\n';
    }

    return 0;
}