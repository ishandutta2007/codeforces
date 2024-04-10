// Contest: Educational Codeforces Round 83 (Rated for Div. 2) (https://codeforces.com/contest/1312)
// Problem: G: Autocompletion (https://codeforces.com/contest/1312/problem/G)


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

constexpr int N = 1'000'005;
char c[N];
int nxt[N][26];
int str[N];
vi res;

int dfs(int v, int mn_char, int mn_jump) {
    int cost = min(mn_char, str[v] == -1 ? INF : mn_jump);
    if (str[v] != -1)
        res[str[v]] = cost;
    int strs = (int)(str[v] != -1);
    rep(i, 26)
        if (nxt[v][i])
            strs += dfs(nxt[v][i], cost + 1, min(cost + strs + 1, mn_jump + strs));
    return strs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fill(all(str), -1);
    int n, p; cin >> n;
    reps(i, 1, n + 1)
        cin >> p >> c[i], nxt[p][c[i] - 'a'] = i;
    int k, ai; cin >> k;
    rep(i, k)
        cin >> ai, str[ai] = i;
    res.resize(k);
    dfs(0, 0, INF);
    trav(ri, res)
        cout << ri << ' ';
    cout << '\n';

    return 0;
}