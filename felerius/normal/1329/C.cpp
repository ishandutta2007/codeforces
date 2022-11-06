// Contest: Codeforces Round #631 (Div. 1) - Thanks, Denis aramis Shitov! (https://codeforces.com/contest/1329)
// Problem: C: Drazil Likes Heap (https://codeforces.com/contest/1329/problem/C)


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
        int h, g; cin >> h >> g;
        vi a(1 << (h + 1));
        reps(i, 1, sz(a) / 2) cin >> a[i];
        vi op;
        ll sum = 0;
        reps(i, 1, 1 << g) {
            while (1) {
                int j = i;
                while (a[j] != 0)
                    j = a[2*j] > a[2*j+1] ? 2*j : 2*j+1;
                int d = sizeof(int) * 8 - 1 - __builtin_clz(j);
                if (d <= g)
                    break;
                op.push_back(i);
                j = i;
                while (a[j] != 0)
                    a[j] = max(a[2*j], a[2*j+1]), j = a[2*j] > a[2*j+1] ? 2*j : 2*j+1;
            }
            sum += a[i];
        }
        cout << sum << '\n';
        trav(opi, op)
            cout << opi << ' ';
        cout << '\n';
    }

    return 0;
}