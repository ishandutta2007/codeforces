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
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; string s; cin >> n >> k >> s;
        int zeros = (int)count(all(s), 'L');
        k = min(k, zeros);
        if (zeros == n) {
            cout << (k ? 1 + 2*(k-1) : 0) << '\n';
            continue;
        }


        int bef = 0, aft = 0;
        while (s[bef] == 'L') ++bef;
        while (s[n-1-aft] == 'L') ++aft;

        multiset<int> between;
        int pts = (s[0] == 'W');
        reps(i, 1, n) {
            pts += s[i] == 'L' ? 0 : (s[i-1] == 'W' ? 2 : 1);
            if (s[i] != 'L' || s[i-1] != 'W') continue;
            int j = i;
            while (j < n && s[j] == 'L') ++j;
            if (j < n)
                between.emplace(j - i);
        }

        while (size(between) && *begin(between) <= k) {
            int w = *begin(between);
            between.erase(begin(between));
            k -= w;
            pts += 2 * w + 1;
        }

        pts += 2 * k;
        cout << pts << '\n';
    }

    return 0;
}