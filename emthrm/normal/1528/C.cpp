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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

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

template <typename Abelian>
struct FenwickTreeSupportingRangeAddQuery {
  FenwickTreeSupportingRangeAddQuery(int n_, const Abelian ID = 0) : n(n_), ID(ID) {
    ++n;
    dat_const.assign(n, ID);
    dat_linear.assign(n, ID);
  }

  void add(int left, int right, Abelian val) {
    if (right < ++left) return;
    for (int i = left; i < n; i += i & -i) {
      dat_const[i] -= val * (left - 1);
      dat_linear[i] += val;
    }
    for (int i = right + 1; i < n; i += i & -i) {
      dat_const[i] += val * right;
      dat_linear[i] -= val;
    }
  }

  Abelian sum(int idx) const {
    Abelian res = ID;
    for (int i = idx; i > 0; i -= i & -i) res += dat_linear[i];
    res *= idx;
    for (int i = idx; i > 0; i -= i & -i) res += dat_const[i];
    return res;
  }

  Abelian sum(int left, int right) const {
    return left < right ? sum(right) - sum(left) : ID;
  }

  Abelian operator[](const int idx) const { return sum(idx, idx + 1); }

private:
  int n;
  const Abelian ID;
  std::vector<Abelian> dat_const, dat_linear;
};

void solve() {
  int n; cin >> n;
  vector<vector<int>> soroush(n), keshi(n);
  FOR(i, 1, n) {
    int a; cin >> a; --a;
    soroush[a].emplace_back(i);
  }
  FOR(i, 1, n) {
    int b; cin >> b; --b;
    keshi[b].emplace_back(i);
  }
  int h = 1;
  while ((1 << h) <= n) ++h;
  vector<int> depth(n, 0);
  vector par(h, vector<int>(n, -1));
  auto g = [&](auto &&g, int ver) -> void {
    for (int e : keshi[ver]) {
      depth[e] = depth[ver] + 1;
      par[0][e] = ver;
      g(g, e);
    }
  };
  g(g, 0);
  for (int i = 0; i + 1 < h; ++i) REP(j, n) {
    par[i + 1][j] = (par[i][j] == -1 ? -1 : par[i][par[i][j]]);
  }
  auto anc = [&](int ver, int step) -> int {
    for (int b = 0; step > 0; step >>= 1, ++b) {
      if (step & 1) ver = par[b][ver];
    }
    return ver;
  };
  int ans = 1, cur = 0;
  HeavyLightDecomposition hld(keshi, 0);
  FenwickTreeSupportingRangeAddQuery<ll> bit(n);
  vector<bool> is_in(n, false), affect(n, false);
  auto f = [&](auto &&f, int ver) -> void {
    // cout << "add: " << ver << endl;
    if (ll tmp = bit[hld.id[ver]]; tmp == 0) {
      int lb = 0, ub = depth[ver] + 1;
      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        (bit[hld.id[anc(ver, mid)]] == tmp ? lb : ub) = mid;
      }
      if (int cand = (ub <= depth[ver] ? anc(ver, ub) : -1); cand != -1 && affect[cand]) {
        --cur;
        affect[cand] = false;
      }
      ++cur;
      affect[ver] = true;
    }
    hld.v_update(0, ver, [&](int u, int v) -> void { bit.add(u, v, 1); });
    is_in[ver] = true;
    chmax(ans, cur);
    // REP(i, n) cout << affect[i];
    // cout << endl;
    // REP(i, n) cout << bit[hld.id[i]] << " \n"[i + 1 == n];
    for (int e : soroush[ver]) f(f, e);
    is_in[ver] = false;
    hld.v_update(0, ver, [&](int u, int v) -> void { bit.add(u, v, -1); });
    if (affect[ver]) {
      --cur;
      affect[ver] = false;
      ll tmp = bit[hld.id[ver]];
      int lb = 0, ub = depth[ver] + 1;
      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        (bit[hld.id[anc(ver, mid)]] == tmp ? lb : ub) = mid;
      }
      if (ub <= depth[ver]) {
        int cand = anc(ver, ub);
        assert(!affect[cand]);
        if (is_in[cand]
            && hld.subtree_v_query<ll>(cand, [&](int u, int v) -> ll { return bit.sum(u, v); }) == 1) {
          ++cur;
          affect[cand] = true;
        }
      }
    }
    // cout << "erase: " << ver << endl;
    // REP(i, n) cout << affect[i];
    // cout << endl;
    // REP(i, n) cout << bit[hld.id[i]] << " \n"[i + 1 == n];
  };
  f(f, 0);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}