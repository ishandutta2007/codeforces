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

    int n, m; cin >> n >> m;
    vector<array<bool, 2>> into(n, {false, false});
    vector<vpi> inc(n);
    vi d(n, INF);

    rep(_, m) {
        int u, v, t; cin >> u >> v >> t; --u, --v;
        if (u == v || u == n - 1)
            continue;
        inc[v].emplace_back(u, t);
    }

    d[n-1] = 0;
    queue<int> q;
    q.push(n-1);
    into[n-1] = {true, true};
    string res(n, '0');

    while (sz(q)) {
        int v = q.front(); q.pop();
        for (auto [u, t] : inc[v]) {
            if (into[u][t])
                continue;
            into[u][t] = true;
            if (into[u][1-t])
                d[u] = d[v] + 1, q.push(u), res[u] = (char)('0' + t);
        }
    }

    rep(i, n)
        if (d[i] == INF)
            res[i] = into[i][0] ? '1' : '0';
    if (d[0] == INF)
        cout << "-1\n" << res << '\n';
    else
        cout << d[0] << '\n' << res << '\n';

    return 0;
}