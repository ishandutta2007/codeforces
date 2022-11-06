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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    vi p, a;
    rep(i, n) {
        if (s[i] == 'P')
            p.push_back(i);
        else if (s[i] == '*')
            a.push_back(i);
    }

    int l = 0, r = 3 * n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        int le = 0, prev = -INF / 2;
        auto it = begin(a);
        bool pos = true;
        for (auto pi : p) {
            auto itr = it;
            while (itr != end(a) && *itr <= pi)
                ++itr;
            if (it == itr) {
                prev = pi;
                le = 0;
                continue;
            }
            int nle = pi - *it;
            for (auto it2 = it; it2 != itr; ++it2) {
                int lri = (*it2 - prev) + le + min(*it2 - prev, le);
                int ri = next(it2) == itr ? 0 : pi - *next(it2);
                if (lri <= m)
                    nle = ri;
            }

            if (nle > m) {
                pos = false;
                break;
            }
            le = nle;
            it = itr;
            prev = pi;
        }
        if (pos && it != end(a)) {
            pos = le + (a.back() - p.back()) + min(le, a.back() - p.back()) <= m;
        }
        (pos ? r : l) = m;
    }

    cout << r << '\n';
    return 0;
}