// Contest: Codeforces Round #622 (Div. 2) (https://codeforces.com/contest/1313)
// Problem: C2: Skyscrapers (hard version) (https://codeforces.com/contest/1313/problem/C2)


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

struct Entry {
    int h, l, w;
    ll sum() const {
        return (ll)h * w;
    }
};

template <class It>
vl scan(It it, It it_end) {
    int i = 0;
    vl res;
    ll sum = 0;
    vector<Entry> s;
    while (it != it_end) {
        int h = *it++;
        while (sz(s) && s.back().h > h)
            sum -= s.back().sum(), s.pop_back();
        int l = sz(s) ? s.back().l + s.back().w : 0;
        s.emplace_back(Entry {h, l, i - l + 1});
        sum += s.back().sum();
        res.push_back(sum);
        ++i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vi m(n);
    trav(mi, m) cin >> mi;

    vl l = scan(all(m));
    vl r = scan(rbegin(m), rend(m));
    reverse(all(r));
    pair<ll, int> mx = {0, -1};
    rep(i, n)
        mx = max(mx, pair(l[i] + r[i] - m[i], i));

    vi res;
    int mxh = m[mx.second];
    for (int i = mx.second; i >= 0; --i)
        res.push_back(min(mxh, m[i])), mxh = min(mxh, m[i]);
    reverse(all(res));
    mxh = m[mx.second];
    for (int i = mx.second + 1; i < n; ++i)
        res.push_back(min(mxh, m[i])), mxh = min(mxh, m[i]);
    trav(h, res)
        cout << h << ' ';
    cout << '\n';

    return 0;
}