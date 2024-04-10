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

    int n; cin >> n;
    string s, t; cin >> s >> t;

    if (count(all(s), '1') != count(all(t), '1'))
        cout << "-1\n", exit(0);

    array<set<int>, 2> idx;
    rep(i, n) {
        if (s[i] == t[i])
            continue;
        idx[s[i] - '0'].insert(i);
    }

    int c = 0;
    while (sz(idx[0])) {
        ++c;
        if (*begin(idx[0]) < *begin(idx[1])) {
            int i = *begin(idx[0]) - 1;
            while (1) {
                auto it1 = idx[0].upper_bound(i);
                if (it1 == end(idx[0])) break;
                auto it2 = idx[1].upper_bound(*it1);
                if (it2 == end(idx[1])) break;
                i = *it2;
                idx[0].erase(it1);
                idx[1].erase(it2);
            }
        } else {
            int i = *begin(idx[1]) - 1;
            while (1) {
                auto it1 = idx[1].upper_bound(i);
                if (it1 == end(idx[1])) break;
                auto it2 = idx[0].upper_bound(*it1);
                if (it2 == end(idx[0])) break;
                i = *it2;
                idx[1].erase(it1);
                idx[0].erase(it2);
            }
        }
    }

    cout << c << '\n';

    return 0;
}