// Contest: Codeforces Round #620 (Div. 2) (https://codeforces.com/contest/1304)
// Problem: B: Longest Palindrome (https://codeforces.com/contest/1304/problem/B)


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

    int n, m; cin >> n >> m;
    vector<string> sv(n);
    trav(si, sv) cin >> si;
    set<string> se(all(sv));

    vector<string> rev;
    string pal;
    while (sz(se)) {
        auto s = *begin(se);
        auto sr = s;
        reverse(all(sr));
        if (s == sr)
            pal = s;
        else {
            auto it = se.find(sr);
            if (it != end(se))
                rev.emplace_back(s), se.erase(it);
        }
        se.erase(s);
    }

    int l = 0;
    trav(r, rev)
        l += 2 * sz(r);
    l += sz(pal);
    cout << l << '\n';

    trav(r, rev)
        cout << r;
    if (sz(pal))
        cout << pal;
    for (int i = sz(rev) - 1; i >= 0; --i) {
        reverse(all(rev[i]));
        cout << rev[i];
    }
    cout << '\n';

    return 0;
}