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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct LowestCommonAncestorByDoubling {
  std::vector<int> depth, dist;

  explicit LowestCommonAncestorByDoubling(
      const std::vector<std::vector<int>>& graph)
      : is_built(false), n(graph.size()), table_h(1), graph(graph) {
    depth.resize(n);
    dist.resize(n);
    while ((1 << table_h) <= n) ++table_h;
    parent.resize(table_h, std::vector<int>(n));
  }

  void build(int root = 0) {
    is_built = true;
    dfs(-1, root, 0, 0);
    for (int i = 0; i + 1 < table_h; ++i) {
      for (int ver = 0; ver < n; ++ver) {
        parent[i + 1][ver] =
            (parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]]);
      }
    }
  }

  int query(int u, int v) const {
    assert(is_built);
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int i = 0; i < table_h; ++i) {
      if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];
    }
    if (u == v) return u;
    for (int i = table_h - 1; i >= 0; --i) {
      if (parent[i][u] != parent[i][v]) {
        u = parent[i][u];
        v = parent[i][v];
      }
    }
    return parent.front()[u];
  }

  int distance(const int u, const int v) const {
    assert(is_built);
    return dist[u] + dist[v] - dist[query(u, v)] * 2;
  }

  std::vector<std::vector<int>> parent;
 private:
  bool is_built;
  const int n;
  int table_h;
  const std::vector<std::vector<int>> graph;

  void dfs(const int par, const int ver, const int cur_depth,
           const int cur_dist) {
    depth[ver] = cur_depth;
    dist[ver] = cur_dist;
    parent.front()[ver] = par;
    for (const int e : graph[ver]) {
      if (e != par) dfs(ver, e, cur_depth + 1, cur_dist + 1);
    }
  }
};

struct TwoSat {
  explicit TwoSat(const int n)
      : n(n), graph(n << 1), rgraph(n << 1), is_visited(n << 1), ids(n << 1) {
    order.reserve(n << 1);
  }

  int negate(const int x) const { return (n + x) % (n << 1); }

  void add_or(const int x, const int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
    rgraph[y].emplace_back(negate(x));
    rgraph[x].emplace_back(negate(y));
  }

  void add_if(const int x, const int y) { add_or(negate(x), y); }

  void add_nand(const int x, const int y) { add_or(negate(x), negate(y)); }

  void set_true(const int x) { add_or(x, x); }

  void set_false(const int x) { set_true(negate(x)); }

  std::vector<bool> build() {
    std::fill(is_visited.begin(), is_visited.end(), false);
    std::fill(ids.begin(), ids.end(), -1);
    order.clear();
    for (int i = 0; i < (n << 1); ++i) {
      if (!is_visited[i]) dfs(i);
    }
    for (int i = (n << 1) - 1, id = 0; i >= 0; --i) {
      if (ids[order[i]] == -1) rdfs(order[i], id++);
    }
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) {
      if (ids[i] == ids[negate(i)]) return {};
      res[i] = ids[negate(i)] < ids[i];
    }
    return res;
  }

 private:
  const int n;
  std::vector<std::vector<int>> graph, rgraph;
  std::vector<bool> is_visited;
  std::vector<int> ids, order;

  void dfs(const int ver) {
    is_visited[ver] = true;
    for (const int dst : graph[ver]) {
      if (!is_visited[dst]) dfs(dst);
    }
    order.emplace_back(ver);
  }

  void rdfs(const int ver, const int cur_id) {
    ids[ver] = cur_id;
    for (const int dst : rgraph[ver]) {
      if (ids[dst] == -1) rdfs(dst, cur_id);
    }
  }
};

void no() {
  cout << "NO\n";
  exit(0);
}

int main() {
  int n, q; cin >> n >> q;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  LowestCommonAncestorByDoubling lca(graph);
  lca.build();
  vector<vector<int>> xy(q);
  vector<string> s(q);
  vector<int> is_fixed(q, 0);
  vector<char> ans(n, '$');
  vector<vector<tuple<char, char, int>>> cand(n);
  queue<int> que;
  auto process = [&](int node) -> void {
    assert(ans[node] != '$');
    for (const auto [c1, c2, id] : cand[node]) {
      if (c1 == ans[node]) {
        if (is_fixed[id] != 0) {
          if (is_fixed[id] == -1) no();
        } else {
          is_fixed[id] = 1;
          que.emplace(id);
        }
      } else if (c2 == ans[node]) {
        if (is_fixed[id] != 0) {
          if (is_fixed[id] == 1) no();
        } else {
          is_fixed[id] = -1;
          que.emplace(id);
        }
      } else {
        no();
      }
    }
    cand[node].clear();
  };
  auto dequeue = [&]() -> void {
    while (!que.empty()) {
      const int id = que.front(); que.pop();
      assert(is_fixed[id] != 0);
      if (is_fixed[id] == -1) reverse(ALL(xy[id]));
      const int l = s[id].size();
      REP(k, l) {
        const int node = xy[id][k];
        if (ans[node] != '$') {
          if (ans[node] != s[id][k]) no();
        } else {
          ans[node] = s[id][k];
        }
        process(node);
      }
    }
  };
  REP(i, q) {
    int x, y; cin >> x >> y >> s[i]; --x; --y;
    const int l = lca.query(x, y);
    for (; x != l; x = lca.parent[0][x]) xy[i].emplace_back(x);
    xy[i].emplace_back(l);
    vector<int> y_to_l;
    for (; y != l; y = lca.parent[0][y]) y_to_l.emplace_back(y);
    copy(y_to_l.rbegin(), y_to_l.rend(), back_inserter(xy[i]));
    const int len = s[i].length();
    REP(j, len) {
      const int node = xy[i][j];
      if (s[i][j] == s[i][len - 1 - j]) {
        if (ans[node] != '$') {
          if (ans[node] != s[i][j]) no();
        } else {
          ans[node] = s[i][j];
          process(node);
        }
      } else if (ans[node] != '$') {
        if (s[i][j] == ans[node]) {
          if (is_fixed[i] != 0) {
            if (is_fixed[i] == -1) no();
          } else {
            is_fixed[i] = 1;
            que.emplace(i);
          }
        } else if (s[i][len - 1 - j] == ans[node]) {
          if (is_fixed[i] != 0) {
            if (is_fixed[i] == 1) no();
          } else {
            is_fixed[i] = -1;
            que.emplace(i);
          }
        } else {
          no();
        }
      } else {
        char c1 = '$', c2 = '$';
        if (!cand[node].empty()) tie(c1, c2, ignore) = cand[node].back();
        if (cand[node].empty() || (c1 == s[i][j] && c2 == s[i][len - 1 - j]) || (c1 == s[i][len - 1 - j] && c2 == s[i][j])) {
          assert(s[i][j] != s[i][len - 1 - j]);
          cand[node].emplace_back(s[i][j], s[i][len - 1 - j], i);
        } else if (c1 == s[i][j] || c2 == s[i][j]) {
          if (is_fixed[i] != 0) {
            if (is_fixed[i] == -1) no();
          } else {
            is_fixed[i] = 1;
            que.emplace(i);
          }
        } else if (c1 == s[i][len - 1 - j] || c2 == s[i][len - 1 - j]) {
          if (is_fixed[i] != 0) {
            if (is_fixed[i] == 1) no();
          } else {
            is_fixed[i] = -1;
            que.emplace(i);
          }
        } else {
          no();
        }
      }
    }
    dequeue();
  }
  vector<int> is_checked(q, false);
  TwoSat two_sat(q);
  REP(i, n) {
    const int len = cand[i].size();
    REP(j, len) {
      const auto [c, _, id1] = cand[i][j];
      const auto [c1, c2, id2] = cand[i][(j + 1) % len];
      is_checked[id1] = true;
      assert(c1 != c2 && is_fixed[id1] == 0 && is_fixed[id2] == 0);
      if (c1 == c) {
        two_sat.add_if(id1, id2);
        two_sat.add_if(two_sat.negate(id1), two_sat.negate(id2));
      } else if (c2 == c) {
        two_sat.add_if(id1, two_sat.negate(id2));
        two_sat.add_if(two_sat.negate(id1), id2);
      } else {
        assert(false);
      }
    }
  }
  const vector<bool> tf = two_sat.build();
  if (tf.empty()) no();
  REP(i, q) {
    if (is_fixed[i] == 0) {
      if (!is_checked[i]) assert(equal(ALL(s[i]), s[i].rbegin()));
      is_fixed[i] = (tf[i] ? 1 : -1);
      que.emplace(i);
    }
  }
  dequeue();
  cout << "YES\n";
  REP(i, n) cout << (ans[i] == '$' ? 'a' : ans[i]);
  cout << '\n';
  return 0;
}