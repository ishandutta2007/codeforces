// Contest: Codeforces Round #628 (Div. 2) (https://codeforces.com/contest/1325)
// Problem: E: Ehab's REAL Number Theory Problem (https://codeforces.com/contest/1325/problem/E)


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

constexpr int MX = 1'000'000;
array<int, MX + 1> sieve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve.fill(-1);
    sieve[0] = sieve[1] = 1;
    reps(i, 2, sz(sieve)) {
        if (sieve[i] != -1)
            continue;
        for (int j = i; j < sz(sieve); j += i)
            if (sieve[j] == -1)
                sieve[j] = i;
    }

    vpi pairs;
    vi nums = {1};
    int _n; cin >> _n;
    rep(i, _n) {
        int ai; cin >> ai;
        pair<pi, pi> ps = {{-1, 0}, {-1, 0}};
        while (ai > 1) {
            int p = sieve[ai];
            ai /= p;
            if (ps.first.first == p)
                ps.first.second++;
            else if (ps.second.first == p)
                ps.second.second++;
            else
                (ps.first.first == -1 ? ps.first : ps.second) = {p, 1};
        }
        if (ps.first.second % 2 == 0) ps.first = {-1, 0};
        if (ps.second.second % 2 == 0) ps.second = {-1, 0};
        if (ps.first.first == -1 && ps.second.first == -1)
            cout << "1\n", exit(0);
        else {
            if (ps.first.first == -1) ps.first.first = 1;
            if (ps.second.first == -1) ps.second.first = 1;
            nums.push_back(ps.first.first);
            nums.push_back(ps.second.first);
            pairs.emplace_back(ps.first.first, ps.second.first);
        }
    }
    sort(all(nums));
    nums.erase(unique(all(nums)), end(nums));
    auto idx = [&](int i) { return (int)(lower_bound(all(nums), i) - begin(nums)); };

    int n = sz(nums);
    vector<vpi> adj(n);
    rep(i, _n) {
        int u = idx(pairs[i].first), v = idx(pairs[i].second);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    int mn = INF;
    for (int i = 0; i < sz(nums) && nums[i] * nums[i] <= MX; ++i) {
        vi d(n, -1), inc(n, -1);
        queue<int> q;
        q.push(i), d[i] = 0;
        while (sz(q)) {
            int v = q.front(); q.pop();
            for (auto [v2, e] : adj[v]) {
                if (e == inc[v])
                    continue;
                if (d[v2] == -1)
                    d[v2] = d[v] + 1, inc[v2] = e, q.push(v2);
                else
                    mn = min(mn, d[v] + d[v2] + 1);
            }
        }
    }

    cout << (mn == INF ? -1 : mn) << '\n';
    return 0;
}