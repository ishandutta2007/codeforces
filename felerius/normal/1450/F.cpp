// The Struggling Contestant (https://codeforces.com/contest/1450/problem/F)

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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        trav(ai, a) cin >> ai;

        map<int, int> cnt_;
        int mx = 0;
        trav(ai, a) mx = max(mx, ++cnt_[ai]);
        if (mx > (n + 1) / 2) {
            cout << "-1\n";
            continue;
        }

        map<int, multiset<int>> adj;
        int l = 0, r;
        while (l < n) {
            r = l + 1;
            while (r < n && a[r] != a[r-1]) ++r;
            adj[a[l]].emplace(a[r-1]);
            adj[a[r-1]].emplace(a[l]);
            l = r;
        }

        int rem = 0;
        set<pair<int, int>> cnt;
        for (auto& [ai, v] : adj)
            cnt.emplace(sz(v), ai), rem += sz(v);

        rem /= 2;
        int res = 0, cur = -1;
        while (rem) {
            int start;
            if (cur == rbegin(cnt)->second) {
                if (sz(cnt) == 1)
                    break;
                start = ::next(rbegin(cnt))->second;
            } else
                start = rbegin(cnt)->second;

            int end = *begin(adj[start]);

            for (auto [u, v] : {pair(start, end), pair(end, start)}) {
                cnt.erase(pair(sz(adj[u]), u));
                adj[u].erase(adj[u].find(v));
                if (sz(adj[u]))
                    cnt.emplace(sz(adj[u]), u);
            }

            --rem;
            ++res;
            cur = end;
        }

        cout << (res - 1 + 2 * rem) << '\n';
    }

    return 0;
}