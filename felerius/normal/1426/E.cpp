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

struct Edge {
    int from, to, flow, cap;
    Edge* rev = nullptr;
};

vector<Edge*> adj[8];

void add_edge(int a, int b, int cap) {
    auto e = new Edge{a, b, 0, cap};
    auto er = new Edge{b, a, 0, 0, e};
    e->rev = er;
    adj[a].push_back(e);
    adj[b].push_back(er);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a1, a2, a3, b1, b2, b3; cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    ll mx = (ll)min(a1, b2) + min(a2, b3) + min(a3, b1);

    add_edge(0, 1, a1);
    add_edge(0, 2, a2);
    add_edge(0, 3, a3);

    add_edge(1, 4, INF);
    add_edge(1, 6, INF);
    add_edge(2, 5, INF);
    add_edge(2, 4, INF);
    add_edge(3, 6, INF);
    add_edge(3, 5, INF);

    add_edge(4, 7, b1);
    add_edge(5, 7, b2);
    add_edge(6, 7, b3);

    int flow = 0;
    while (1) {
        Edge* inc[8];
        fill(all(inc), nullptr);
        queue<int> q{{0}};
        while (sz(q)) {
            int v = q.front(); q.pop();
            for (auto e : adj[v])
                if (e->flow < e->cap && !inc[e->to])
                    inc[e->to] = e, q.push(e->to);
        }

        if (!inc[7])
            break;

        int aug = INF;
        for (int v = 7; v; v = inc[v]->from)
            aug = min(aug, inc[v]->cap - inc[v]->flow);
        for (int v = 7; v; v = inc[v]->from)
            inc[v]->flow += aug, inc[v]->rev->flow -= aug;
        flow += aug;
    }

    cout << (n - flow) << ' ' << mx << '\n';
    return 0;
}