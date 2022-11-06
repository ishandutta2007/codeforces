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

    string s_; cin >> s_;
    vector<pair<char, int>> s;
    int n = sz(s_);
    rep(i, n)
        s.emplace_back(s_[i], i);
    int mn = INF;
    rep(i, n+1) rep(j, n) rep(k, n) {
        if (i == j || j == k || i == k)
            continue;

        vector<pair<int, int>> ops;
        vector<int> order;
        if (i == n) {
            ops = {pair(j, n-1), pair(k, n-2)};
            order = {0, 1};
        } else {
            ops = {pair(i, 0), pair(j, n-1), pair(k, n-2)};
            order = {0, 1, 2};
        }

        do {
            auto s2 = s;
            int cost = 0;
            trav(x, order) {
                auto [from, to] = ops[x];
                int from2 = (int)(find_if(all(s2), [from=from](auto& p) { return p.second == from; }) - begin(s2));
                cost += abs(from2 - to);
                auto val = s2[from2];
                s2.erase(begin(s2) + from2);
                s2.insert(begin(s2) + to, val);
            }

            ll val = 0;
            for (auto [c, _] : s2)
                val = val * 10 + (c - '0');
            if (s2[0].first != '0' && val % 25 == 0)
                mn = min(mn, cost);
        } while (next_permutation(all(order)));
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}