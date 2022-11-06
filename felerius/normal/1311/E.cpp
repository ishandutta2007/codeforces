// Contest: Codeforces Round #624 (Div. 3) (https://codeforces.com/contest/1311)
// Problem: E: Construct the Binary Tree (https://codeforces.com/contest/1311/problem/E)


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

struct Layer {
    vi nodes;
    int open = 0;
    int deg_open = 1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, d; cin >> n >> d;
        vi p(n - 1, -1);
        vector<Layer> l(n);
        rep(i, n)
            l[i].nodes.push_back(i);
        rep(i, n - 1)
            p[i] = i;

        d -= n * (n - 1) / 2;
        for (int i = n - 1; i > 0; --i) {
            if (!d || sz(l[i].nodes) != 1)
                break;
            int par = max(0, i + d - 1);
            while (par < i - 1 && l[par].open == sz(l[par].nodes))
                ++par;
            if (par >= i - 1)
                break;
            int v = l[i].nodes[0]; l[i].nodes.pop_back();
            int pv = l[par].nodes[l[par].open];
            p[v-1] = pv;
            l[par+1].nodes.push_back(v);
            d += i - par - 1;
            if (++l[par].deg_open == 2) {
                l[par].deg_open = 0;
                ++l[par].open;
            }
        }

        if (d)
            cout << "NO\n";
        else {
            cout << "YES\n";
            trav(i, p)
                cout << (i + 1) << ' ';
            cout << '\n';
        }
    }

    return 0;
}