#ifndef LOCAL
#define FAST_IO
#endif

// ===== template.hpp =====
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define OVERRIDE(a, b, c, d, ...) d
#define REP2(i, n) for (i32 i = 0; i < (i32) (n); ++i)
#define REP3(i, m, n) for (i32 i = (i32) (m); i < (i32) (n); ++i)
#define REP(...) OVERRIDE(__VA_ARGS__, REP3, REP2)(__VA_ARGS__)
#define PER(i, n) for (i32 i = (i32) (n) - 1; i >= 0; --i)
#define ALL(x) begin(x), end(x)

using namespace std;

using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;
using i32 = signed int;
using i64 = signed long long;
using i128 = __int128_t;
using f64 = double;
using f80 = long double;

template <typename T>
using Vec = vector<T>;

template <typename T>
bool chmin(T &x, const T &y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &x, const T &y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

istream &operator>>(istream &is, i128 &x) {
    i64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, i128 x) {
    os << (i64) x;
    return os;
}
istream &operator>>(istream &is, u128 &x) {
    u64 v;
    is >> v;
    x = v;
    return is;
}
ostream &operator<<(ostream &os, u128 x) {
    os << (u64) x;
    return os;
}

[[maybe_unused]] constexpr i32 INF = 1000000100;
[[maybe_unused]] constexpr i64 INF64 = 3000000000000000100;
struct SetUpIO {
    SetUpIO() {
#ifdef FAST_IO
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
#endif
        cout << fixed << setprecision(15);
    }
} set_up_io;
// ===== template.hpp =====

#ifdef DEBUGF
#include "cpl/template/debug.hpp"
#else
#define DBG(x) (void) 0
#endif

// ===== heavy_light_decomposition.hpp =====

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

class HeavyLightDecomposition {
    std::vector<int> siz;
    std::vector<int> par;
    std::vector<int> hea;
    std::vector<int> in;
    std::vector<int> out;
    std::vector<int> dep;
    std::vector<int> rev;

    template <typename G>
    void dfs1(G &g, int v) {
        if (!g[v].empty() && (int) g[v][0] == par[v]) {
            std::swap(g[v][0], g[v].back());
        }
        for (auto &e : g[v]) {
            int u = (int)e;
            if (u != par[v]) {
                par[u] = v;
                dfs1(g, u);
                siz[v] += siz[u];
                if (siz[u] > siz[g[v][0]]) {
                    std::swap(g[v][0], e);
                }
            }
        }
    }

    template <typename G>
    void dfs2(const G &g, int v, int &time) {
        in[v] = time;
        rev[time++] = v;
        for (auto &e : g[v]) {
            int u = (int)e;
            if (u == par[v]) {
                continue;
            }
            if (u == (int) g[v][0]) {
                hea[u] = hea[v];
            } else {
                hea[u] = u;
            }
            dep[u] = dep[v] + 1;
            dfs2(g, u, time);
        }
        out[v] = time;
    }

public:
    template <typename G>
    HeavyLightDecomposition(G &g, int root = 0) :
        siz(g.size(), 1),
        par(g.size(), root),
        hea(g.size(), root),
        in(g.size(), 0),
        out(g.size(), 0),
        dep(g.size(), 0),
        rev(g.size(), 0) {
        assert(root >= 0 && root < static_cast<int>(g.size()));
        dfs1(g, root);
        int time = 0;
        dfs2(g, root, time);
    }

    int subtree_size(int v) const {
        assert(v >= 0 && v < static_cast<int>(siz.size()));
        return siz[v];
    }

    int parent(int v) const {
        assert(v >= 0 && v < static_cast<int>(par.size()));
        return par[v];
    }

    int in_time(int v) const {
        assert(v >= 0 && v < static_cast<int>(in.size()));
        return in[v];
    }

    int out_time(int v) const {
        assert(v >= 0 && v < static_cast<int>(out.size()));
        return out[v];
    }

    int depth(int v) const {
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        return dep[v];
    }

    int time_to_vertex(int t) const {
        assert(t >= 0 && t < static_cast<int>(rev.size()));
        return rev[t];
    }
    
    int la(int v, int k) const {
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        assert(k >= 0);
        while (true) {
            int u = hea[v];
            if (in[u] + k <= in[v]) {
                return rev[in[v] - k];
            }
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
        return 0;
    }
    
    int forward(int v, int dst) const {
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        assert(dst >= 0 && dst < static_cast<int>(dep.size()));
        assert(v != dst);
        int l = lca(v, dst);
        if (l == v) {
            return la(dst, dist(v, dst) - 1);
        } else {
            return par[v];
        }
    }

    int lca(int u, int v) const {
        assert(u >= 0 && u < static_cast<int>(dep.size()));
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        while (u != v) {
            if (in[u] > in[v]) {
                std::swap(u, v);
            }
            if (hea[u] == hea[v]) {
                v = u;
            } else {
                v = par[hea[v]];
            }
        }
        return u;
    }

    int dist(int u, int v) const {
        assert(u >= 0 && u < static_cast<int>(dep.size()));
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }

    std::vector<std::pair<int, int>> path(int u, int v, bool edge) const {
        assert(u >= 0 && u < static_cast<int>(dep.size()));
        assert(v >= 0 && v < static_cast<int>(dep.size()));
        std::vector<std::pair<int, int>> fromu, fromv;
        bool rev = false;
        while (true) {
            if (u == v && edge) {
                break;
            }
            if (in[u] > in[v]) {
                std::swap(u, v);
                std::swap(fromu, fromv);
                rev ^= true;
            }
            if (hea[u] == hea[v]) {
                fromv.emplace_back(in[v], in[u] + (int)edge);
                v = u;
                break;
            } else {
                fromv.emplace_back(in[v], in[hea[v]]);
                v = par[hea[v]];
            }
        }
        if (rev) {
            std::swap(fromu, fromv);
        }
        std::reverse(fromv.begin(), fromv.end());
        fromu.reserve(fromv.size());
        for (auto [x, y] : fromv) {
            fromu.emplace_back(y, x);
        }
        return fromu;
    }
};

// ===== heavy_light_decomposition.hpp =====

int main() {
    i32 n, q;
    cin >> n >> q;
    Vec<Vec<i32>> g(n);
    REP(i, 1, n) {
        i32 p;
        cin >> p;
        --p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    
    HeavyLightDecomposition hld(g);
    
    Vec<i32> dfs_order(n, 0);
    REP(i, n) {
        dfs_order[hld.in_time(i)] = i;
    }
    DBG(dfs_order);
    
    Vec<i32> cent(n, 0);
    Vec<i32> subtree_max(n, 0);
    PER(i, n) {
        i32 v = dfs_order[i];
        i32 sz = hld.subtree_size(v);
        
        i32 mx = 0;
        i32 mx_sub = -1;
        for (i32 u : g[v]) {
            if (u == hld.parent(v)) {
                continue;
            }
            if (chmax(mx, hld.subtree_size(u))) {
                mx_sub = u;
            }
        }
        subtree_max[v] = mx;
        
        if (2 * mx <= sz) {
            cent[v] = v;
            continue;
        }
        
        i32 ok = cent[mx_sub];
        i32 ok_dep = hld.depth(ok);
        DBG(v);
        DBG(ok);
        
        i32 d0 = hld.depth(v);
        i32 d1 = ok_dep;
        while (d1 - d0 > 1) {
            i32 mid = (d0 + d1) / 2;
            i32 x = hld.la(ok, ok_dep - mid);
            if (2 * subtree_max[x] <= sz) {
                d1 = mid;
            } else {
                d0 = mid;
            }
        }
        
        cent[v] = hld.la(ok, ok_dep - d1);
    }
    
    DBG(cent);
    DBG(subtree_max);
    
    while (q--) {
        i32 x;
        cin >> x;
        --x;
        cout << cent[x] + 1 << '\n';
    }
}