// Contest: Educational Codeforces Round 87 (Rated for Div. 2) (https://codeforces.com/contest/1354)
// Problem: G: Find a Gift (https://codeforces.com/contest/1354/problem/G)


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

int ask(int l1, int r1, int l2, int r2) {
    cout << "? " << (r1 - l1) << ' ' << (r2 - l2) << '\n';
    reps(i, l1, r1)
        cout << (i + 1) << ' ';
    cout << '\n';
    reps(i, l2, r2)
        cout << (i + 1) << ' ';
    cout << '\n';
    string ans; cin >> ans;
    if (ans[0] == 'W')
        exit(0);
    switch (ans[0]) {
        case 'F': return -1;
        case 'E': return 0;
        default: return 1;
    }
}

int askSingle(int i, int j) {
    return ask(i, i + 1, j, j + 1);
}

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        uniform_int_distribution<int> dist(1, n - 1);
        bool stone = true;
        rep(i, 30)
            stone &= askSingle(0, dist(rng)) < 1;
        if (!stone) {
            cout << "! 1\n";
            continue;
        }
        int e = 0;
        while (ask(0, 1 << e, 1 << e, min(n, 2 << e)) == 0)
            ++e;
        int l = 1 << e, r = min(n, 2 << e);
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ask(0, m - l, l, m) == 0)
                l = m;
            else
                r = m;
        }
        cout << "! " << r << '\n';
    }

    return 0;
}