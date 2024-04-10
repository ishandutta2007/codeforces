// Contest: Hello 2020 (https://codeforces.com/contest/1284)
// Problem: D: New Year and Conference (https://codeforces.com/contest/1284/problem/D)


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
//endregion }}}

void check(vpi& a, vpi& b) {
    auto n = sz(a);
    vector<tuple<int, bool, int>> evt;
    rep(i, n)
        evt.emplace_back(a[i].first, false, i), evt.emplace_back(a[i].second, true, i);
    sort(all(evt));

    multiset<int> act_starts, act_ends;
    for (auto [_, isend, i] : evt) {
        if (isend) {
            act_starts.erase(act_starts.find(b[i].first));
            act_ends.erase(act_ends.find(b[i].second));
        } else {
            if (sz(act_starts)) {
                int l = *rbegin(act_starts);
                int r = *begin(act_ends);
                if (b[i].second < l || r < b[i].first)
                    cout << "NO\n", exit(0);
            }
            act_starts.emplace(b[i].first);
            act_ends.emplace(b[i].second);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vpi a(n), b(n);
    rep(i, n)
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;

    check(a, b);
    check(b, a);
    cout << "YES\n";

    return 0;
}