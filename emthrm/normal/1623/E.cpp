#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename T>
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}

  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;
    lazy.assign(p2, T::o_id());
    dat.assign(p2 << 1, T::m_id());
    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];
    for (int i = p2 - 1; i > 0; --i) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  void set(int idx, const Monoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = val;
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int idx, const OperatorMonoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = T::apply(dat[idx], val);
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) return;
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sub_apply(l++, val);
      if (r & 1) sub_apply(--r, val);
    }
    for (int i = left >> (left_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
    for (int i = right >> (right_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  Monoid get(int left, int right) {
    if (right <= left) return T::m_id();
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    Monoid l_res = T::m_id(), r_res = T::m_id();
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = T::m_merge(l_res, dat[left++]);
      if (right & 1) r_res = T::m_merge(dat[--right], r_res);
    }
    return T::m_merge(l_res, r_res);
  }

  Monoid operator[](const int idx) {
    int node = idx + p2;
    for (int i = height; i > 0; --i) propagate(node >> i);
    return dat[node];
  }

  template <typename G>
  int find_right(int left, G g) {
    if (left >= n) return n;
    left += p2;
    for (int i = height; i > 0; --i) propagate(left >> i);
    Monoid val = T::m_id();
    do {
      while (!(left & 1)) left >>= 1;
      Monoid nx = T::m_merge(val, dat[left]);
      if (!g(nx)) {
        while (left < p2) {
          propagate(left);
          left <<= 1;
          nx = T::m_merge(val, dat[left]);
          if (g(nx)) {
            val = nx;
            ++left;
          }
        }
        return left - p2;
      }
      val = nx;
      ++left;
    } while (__builtin_popcount(left) > 1);
    return n;
  }

  template <typename G>
  int find_left(int right, G g) {
    if (right <= 0) return -1;
    right += p2;
    for (int i = height; i > 0; --i) propagate((right - 1) >> i);
    Monoid val = T::m_id();
    do {
      --right;
      while (right > 1 && (right & 1)) right >>= 1;
      Monoid nx = T::m_merge(dat[right], val);
      if (!g(nx)) {
        while (right < p2) {
          propagate(right);
          right = (right << 1) + 1;
          nx = T::m_merge(dat[right], val);
          if (g(nx)) {
            val = nx;
            --right;
          }
        }
        return right - p2;
      }
      val = nx;
    } while (__builtin_popcount(right) > 1);
    return -1;
  }

private:
  int n, p2, height = 0;
  std::vector<Monoid> dat;
  std::vector<OperatorMonoid> lazy;

  void sub_apply(int idx, const OperatorMonoid &val) {
    dat[idx] = T::apply(dat[idx], val);
    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx], val);
  }

  void propagate(int idx) {
    // assert(1 <= idx && idx < p2);
    sub_apply(idx << 1, lazy[idx]);
    sub_apply((idx << 1) + 1, lazy[idx]);
    lazy[idx] = T::o_id();
  }
};

namespace monoid {
template <typename T>
struct RangeMinimumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::max(); }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::max(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return b == o_id()? a : b; }
};

template <typename T>
struct RangeMaximumAndUpdateQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::lowest(); }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::lowest(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::max(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return b == o_id()? a : b; }
};

template <typename T, T Inf>
struct RangeMinimumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return a + b; }
};

template <typename T, T Inf>
struct RangeMaximumAndAddQuery {
  using Monoid = T;
  using OperatorMonoid = T;
  static constexpr Monoid m_id() { return -Inf; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::max(a, b); }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return a + b; }
};

template <typename T>
struct RangeSumAndUpdateQuery {
  using Monoid = struct {
    T sum;
    int len;
  };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(int n) { return std::vector<Monoid>(n, Monoid{0, 1}); }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::max(); }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return b == o_id() ? a : b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return Monoid{b == o_id() ? a.sum : b * a.len, a.len}; }
};

template <typename T>
struct RangeSumAndAddQuery {
  using Monoid = struct {
    T sum;
    int len;
  };
  using OperatorMonoid = T;
  static std::vector<Monoid> init(int n) { return std::vector<Monoid>(n, Monoid{0, 1}); }
  static constexpr Monoid m_id() { return {0, 0}; }
  static constexpr OperatorMonoid o_id() { return 0; }
  static Monoid m_merge(const Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }
  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid &b) { return a + b; }
  static Monoid apply(const Monoid &a, const OperatorMonoid &b) { return Monoid{a.sum + b * a.len, a.len}; }
};
}  // monoid

struct HeavyLightDecomposition {
  std::vector<int> parent, subtree, id, inv, head;

  HeavyLightDecomposition(const std::vector<std::vector<int>> &graph, int root = 0) : graph(graph) {
    int n = graph.size();
    parent.assign(n, -1);
    subtree.assign(n, 1);
    id.resize(n);
    inv.resize(n);
    head.resize(n);
    dfs1(root);
    head[root] = root;
    int now_id = 0;
    dfs2(root, now_id);
  }

  template <typename Fn>
  void v_update(int u, int v, Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      f(std::max(id[head[v]], id[u]), id[v] + 1);
      if (head[u] == head[v]) return;
      v = parent[head[v]];
    }
  }

  template <typename T, typename F, typename G>
  T v_query(int u, int v, F f, G g, const T ID) const {
    T left = ID, right = ID;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      left = g(left, f(std::max(id[head[v]], id[u]), id[v] + 1));
      if (head[u] == head[v]) break;
      v = parent[head[v]];
    }
    return g(left, right);
  }

  template <typename Fn>
  void subtree_v_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]); }

  template <typename T, typename Fn>
  T subtree_v_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver]); }

  template <typename Fn>
  void e_update(int u, int v, Fn f) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) {
        f(id[u], id[v]);
        break;
      } else {
        f(id[head[v]] - 1, id[v]);
        v = parent[head[v]];
      }
    }
  }

  template <typename T, typename F, typename G>
  T e_query(int u, int v, F f, G g, const T ID) const {
    T left = ID, right = ID;
    while (true) {
      if (id[u] > id[v]) {
        std::swap(u, v);
        std::swap(left, right);
      }
      if (head[u] == head[v]) {
        left = g(left, f(id[u], id[v]));
        break;
      } else {
        left = g(left, f(id[head[v]] - 1, id[v]));
        v = parent[head[v]];
      }
    }
    return g(left, right);
  }

  template <typename Fn>
  void subtree_e_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver] - 1); }

  template <typename T, typename Fn>
  T subtree_e_query(int ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver] - 1); }

  int lowest_common_ancestor(int u, int v) const {
    while (true) {
      if (id[u] > id[v]) std::swap(u, v);
      if (head[u] == head[v]) return u;
      v = parent[head[v]];
    }
  }

private:
  std::vector<std::vector<int>> graph;

  void dfs1(int ver) {
    for (int &e : graph[ver]) {
      if (e != parent[ver]) {
        parent[e] = ver;
        dfs1(e);
        subtree[ver] += subtree[e];
        if (subtree[e] > subtree[graph[ver].front()]) std::swap(e, graph[ver].front());
      }
    }
  }

  void dfs2(int ver, int &now_id) {
    id[ver] = now_id++;
    inv[id[ver]] = ver;
    for (int e : graph[ver]) {
      if (e != parent[ver]) {
        head[e] = (e == graph[ver].front() ? head[ver] : e);
        dfs2(e, now_id);
      }
    }
  }
};

int main() {
  int n, k; string c; cin >> n >> k >> c;
  vector<int> l(n), r(n);
  vector<vector<int>> graph(n);
  REP(i, n) {
    cin >> l[i] >> r[i]; --l[i]; --r[i];
    if (l[i] != -1) graph[i].emplace_back(l[i]);
    if (r[i] != -1) graph[i].emplace_back(r[i]);
  }
  vector<int> dfs;
  const auto f = [&](auto&& f, int ver) -> void {
    if (l[ver] != -1) f(f, l[ver]);
    dfs.emplace_back(ver);
    if (r[ver] != -1) f(f, r[ver]);
  };
  f(f, 0);
  HeavyLightDecomposition hld(graph);
  LazySegmentTree<monoid::RangeSumAndUpdateQuery<ll>> seg(
      vector<monoid::RangeSumAndUpdateQuery<ll>::Monoid>(n, {1, 1}));
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && c[dfs[i]] == c[dfs[j]]) ++j;
    if (j < n && c[dfs[i]] < c[dfs[j]]) {
      for (; i < j; ++i) {
        if (seg[hld.id[dfs[i]]].sum == 1) {
          const ll x =
              hld.v_query(0, dfs[i],
                          [&](int u, int v) -> ll { return seg.get(u, v).sum; },
                          [](ll x, ll y) -> ll { return x + y; },
                          0LL);
          if (x <= k) {
            k -= x;
            hld.v_update(0, dfs[i], [&](int u, int v) -> void { seg.apply(u, v, 0); });
          }
        }
      }
    } else {
      for (; i < j; ++i) {
        if (seg[hld.id[dfs[i]]].sum == 1) seg.set(hld.id[dfs[i]], {n + 1, 1});
      }
    }
  }
  REP(i, n) {
    cout << c[dfs[i]];
    if (seg[hld.id[dfs[i]]].sum == 0) cout << c[dfs[i]];
  }
  cout << '\n';
  return 0;
}