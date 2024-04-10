// Contest: Codeforces Round #617 (Div. 3) (https://codeforces.com/contest/1296)
// Problem: C: Yet Another Walking Robot (https://codeforces.com/contest/1296/problem/C)


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

    auto off = [](char c) -> pi {
        switch (c) {
            case 'L': return {-1, 0};
            case 'R': return {1, 0};
            case 'U': return {0, 1};
            case 'D': return {0, -1};
        }
    };

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        map<pi, int> seen;
        int mn = INF, l = 0, r = 0;
        pi pos = {0, 0};
        trav(c, s) {
            auto [dx, dy] = off(c);
            pos.first += dx, pos.second += dy;
        }
        for (int i = n - 1; i >= 0; --i) {
            seen[pos] = i;
            auto [dx, dy] = off(s[i]);
            pos.first -= dx, pos.second -= dy;
            auto it = seen.find(pos);
            if (it != end(seen) && it->second - i < mn)
                l = i, r = it->second, mn = r - l;
        }

        if (mn == INF)
            cout << "-1\n";
        else
            cout << (l+1) << ' ' << (r+1) << '\n';
    }

    return 0;
}