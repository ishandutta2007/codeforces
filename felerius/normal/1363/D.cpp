// Contest: Codeforces Round #646 (Div. 2) (https://codeforces.com/contest/1363)
// Problem: D: Guess The Maximums (https://codeforces.com/contest/1363/problem/D)


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

int main() {
    ios::sync_with_stdio(false);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vvi sets(k);
        trav(s, sets) {
            int c; cin >> c;
            s.resize(c);
            trav(si, s) cin >> si, --si;
        }

        cout << "? " << n;
        rep(i, n) cout << ' ' << (i + 1);
        cout << '\n';
        int mx; cin >> mx;

        int l = 0, r = n;
        while (r - l > 1) {
            int m = (r + l) / 2;
            cout << "? " << (m - l);
            reps(i, l, m) cout << ' ' << (i + 1);
            cout << '\n';
            int rngmx; cin >> rngmx;
            (rngmx == mx ? r : l) = m;
        }

        int si = -1;
        rep(i, k)
            if (find(all(sets[i]), l) != end(sets[i]))
                si = i;
        vi ans(k, mx);
        if (si != -1) {
            vi ask;
            rep(i, n)
                if (find(all(sets[si]), i) == end(sets[si]))
                    ask.push_back(i);
            cout << "? " << sz(ask);
            trav(i, ask)
                cout << ' ' << (i + 1);
            cout << '\n';
            cin >> ans[si];
        }
        cout << "!";
        trav(i, ans) cout << ' ' << i;
        cout << '\n';

        string s; cin >> s;
    }

    return 0;
}