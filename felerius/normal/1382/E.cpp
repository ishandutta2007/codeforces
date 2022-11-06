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

vi solve() {
    int n, x, y; cin >> n >> x >> y;
    vvi idx(n + 1);
    vi b(n);
    rep(i, n)
        cin >> b[i], --b[i], idx[b[i]].push_back(i);
    int z = y - x;

    int c0 = 0;
    while (sz(idx[c0])) ++c0;
    vi a(n, c0);

    set<pi> col;
    auto take_col = [&]() {
        auto c = prev(end(col))->second;
        col.erase(prev(end(col)));
        int i = idx[c].back();
        idx[c].pop_back();
        return pi(i, c);
    };
    auto push_col = [&](int i) {
        if (sz(idx[i]))
            col.emplace(sz(idx[i]), i);
    };

    rep(i, n + 1)
        push_col(i);

    if (sz(col) >= 3 && z >= 3 && z % 2) {
        auto [i1, c1] = take_col();
        auto [i2, c2] = take_col();
        auto [i3, c3] = take_col();
        push_col(c1), push_col(c2), push_col(c3);
        a[i1] = c3;
        a[i2] = c1;
        a[i3] = c2;
        z -= 3;
    }

    int last_z_idx = -1;
    while (z > 0) {
        if (sz(col) < 2)
            return {};
        auto [i1, c1] = take_col();
        auto [i2, c2] = take_col();
        push_col(c1), push_col(c2);
        a[i1] = c2;
        a[i2] = c1;
        last_z_idx = i2;
        z -= 2;
    }

    rep(i, n) {
        if (x == 0)
            break;
        if (a[i] == c0)
            a[i] = b[i], --x;
    }

    if (x)
        return {};

    if (z == -1)
        a[last_z_idx] = c0;

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        auto a = solve();
        if (sz(a)) {
            cout << "YES\n";
            trav(ai, a)
                cout << (ai + 1) << ' ';
            cout << '\n';
        } else
            cout << "NO\n";
    }

    return 0;
}