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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

namespace snippets_dsu {
    struct DSU {
        vi p;
        explicit DSU(int n) : p(n, -1) {}

        int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
        bool same(int i, int j) { return find(i) == find(j); }
        int size(int i) { return -p[find(i)]; }
        bool join(int i, int j) {
            i = find(i), j = find(j);
            if (i == j) return false;
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            return true;
        }
    };
} using namespace snippets_dsu;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    map<string, int> ma;
    string s, s2;
    rep(i, n) {
        cin >> s;
        ma[s] = sz(ma);
    }

    DSU dsu(2 * n);
    rep(i, m) {
        int t; cin >> t >> s >> s2;
        int u = ma[s], v = ma[s2];
        if (t == 1) {
            if (dsu.same(u, v + n))
                cout << "NO\n";
            else
                cout << "YES\n", dsu.join(u, v), dsu.join(u + n, v + n);
        } else {
            if (dsu.same(u, v))
                cout << "NO\n";
            else
                cout << "YES\n", dsu.join(u, v + n), dsu.join(u + n, v);
        }
    }

    while (q--) {
        cin >> s >> s2;
        int u = ma[s], v = ma[s2];
        int ans = 3;
        if (dsu.same(u, v))
            ans = 1;
        else if (dsu.same(u, v + n))
            ans = 2;
        cout << ans << '\n';
    }

    return 0;
}