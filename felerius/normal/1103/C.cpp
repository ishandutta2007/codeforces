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

const int N = 250'005;

vi adj[N];
int parent[N], depth[N];
vi leaves;

void dfs(int v) {
    bool leaf = true;
    trav(v2, adj[v])
        if (parent[v2] == -1)
            parent[v2] = v, depth[v2] = depth[v] + 1, dfs(v2), leaf = false;
    if (leaf)
        leaves.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    rep(_, m) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fill(begin(parent), begin(parent) + n, -1);
    parent[0] = -2;
    dfs(0);

    int len = (n + k - 1) / k;
    if (*max_element(begin(depth), begin(depth) + n) >= len - 1) {
        int v = 0;
        while (depth[v] != len - 1)
            ++v;
        cout << "PATH\n" << len << '\n' << (v + 1);
        while (parent[v] != -2)
            v = parent[v], cout << ' ' << (v + 1);
        cout << '\n';
        return 0;
    }

    cout << "CYCLES\n";
    leaves.resize(k);
    trav(vl, leaves) {
        int vp = parent[vl];
        int v0 = adj[vl][adj[vl][0] == vp];
        int v1 = adj[vl][adj[vl][2] == vp ? 1 : 2];
        if (depth[v0] > depth[v1])
            swap(v0, v1);

        int vbot, vtop;
        if ((depth[vl] - depth[v0] + 1) % 3)
            vbot = vp, vtop = v0;
        else if ((depth[vl] - depth[v1] + 1) % 3)
            vbot = vp, vtop = v1;
        else
            vbot = v1, vtop = v0;

        int len = depth[vbot] - depth[vtop] + 2;
        cout << len << '\n';
        cout << (vl + 1) << ' ' << (vbot + 1);
        int v = vbot;
        while (v != vtop)
            v = parent[v], cout << ' ' << (v + 1);
        cout << '\n';
    }

    return 0;
}