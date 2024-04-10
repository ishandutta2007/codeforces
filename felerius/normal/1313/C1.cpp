// Contest: Codeforces Round #622 (Div. 2) (https://codeforces.com/contest/1313)
// Problem: C1: Skyscrapers (easy version) (https://codeforces.com/contest/1313/problem/C1)


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

    int n; cin >> n;
    vi m(n);
    trav(mi, m) cin >> mi;

    pair<ll, int> omx = {0, -1};
    rep(i, n) {
        ll s = m[i];
        int mx = m[i];
        for (int j = i - 1; j >= 0; --j)
            s += min(mx, m[j]), mx = min(mx, m[j]);
        mx = m[i];
        for (int j = i + 1; j < n; ++j)
            s += min(mx, m[j]), mx = min(mx, m[j]);
        omx = max(omx, pair(s, i));
    }

    vi res;
    int mx = m[omx.second];
    for (int i = omx.second; i >= 0; --i)
        res.push_back(min(mx, m[i])), mx = min(mx, m[i]);
    reverse(all(res));
    mx = m[omx.second];
    for (int i = omx.second + 1; i < n; ++i)
        res.push_back(min(mx, m[i])), mx = min(mx, m[i]);
    trav(h, res)
        cout << h << ' ';
    cout << '\n';

    return 0;
}