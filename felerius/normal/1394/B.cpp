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

using Set = bitset<45>;
int idx[10][10];

int solve(Set cur, int i, int k, array<Set, 45>& exclude) {
    if (i == k + 1)
        return 1;

    int sum = 0;
    rep(j, i)
        if (cur[idx[i][j]])
            sum += solve(cur & ~exclude[idx[i][j]], i + 1, k, exclude);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int counter = 0;
    reps(i, 1, 10) rep(j, i)
        idx[i][j] = counter++;

    int n, m, k; cin >> n >> m >> k;
    vector<vpi> adj(n);
    rep(_, m) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        adj[u].emplace_back(w, v);
    }

    vector<array<int, 45>> in(n);
    rep(i, n) {
        sort(all(adj[i]));
        rep(j, sz(adj[i]))
            in[adj[i][j].second][idx[sz(adj[i])][j]]++;
    }

    Set forbidden;
    array<Set, 45> exclude{};
    vi in45;
    rep(i, n) {
        in45.clear();
        rep(j, 45) {
            if (in[i][j] > 1)
                forbidden[j] = true;
            else if (in[i][j] == 1)
                in45.push_back(j);
        }
        rep(j, sz(in45))
            reps(x, j + 1, sz(in45))
                exclude[in45[j]][in45[x]] = true;
    }

    cout << solve(~forbidden, 1, k, exclude) << '\n';
    return 0;
}