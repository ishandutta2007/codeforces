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

struct UnionFind {
  UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -data[root(ver)];
  }

private:
  std::vector<int> data;
};

int main() {
  int n; cin >> n;
  vector<int> c(n); REP(i, n) cin >> c[i];
  vector<set<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace(v);
    graph[v].emplace(u);
  }
  const int black = count(ALL(c), 1);
  vector<int> subtree(n, 0);
  REP(i, n) subtree[i] = (c[i] == 1);
  const auto f = [&](auto&& f, int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        subtree[ver] += subtree[e];
      }
    }
  };
  int root = -1;
  REP(i, n) {
    if (c[i] == 1) {
      root = i;
      f(f, -1, i);
      break;
    }
  }
  assert(subtree[root] = black);
  const auto g = [&](auto&& g, int par, int ver, int par_subtree) -> void {
    if (c[ver] == 1) {
      int cnt = (par_subtree > 0);
      for (int e : graph[ver]) {
        if (e != par) cnt += subtree[e] > 0;
      }
      if (cnt >= 2) {
        REP(i, n) cout << 1 << " \n"[i + 1 == n];
        exit(0);
      }
    }
    for (int e : graph[ver]) {
      if (e != par) g(g, ver, e, black - subtree[e]);
    }
  };
  g(g, -1, root, 0);
  vector<int> is_visited(n, false);
  set<int> pinch;
  queue<int> que;
  for (int e : graph[root]) {
    if (subtree[e] > 0) {
      if (c[e] == 1) {
        REP(i, n) cout << 1 << " \n"[i + 1 == n];
        return 0;
      }
      is_visited[root] = is_visited[e] = true;
      pinch.emplace(e);
      que.emplace(e);
    }
  }
  while (!que.empty()) {
    const int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (!is_visited[e] && c[e] == 0) {
        is_visited[e] = true;
        pinch.emplace(e);
        que.emplace(e);
      }
    }
  }
  // cerr << "pinch:";
  // for (int e : pinch) cerr << ' ' << e + 1;
  // cerr << '\n';
  for (int e : pinch) {
    if (graph[e].size() == 1) que.emplace(e);
  }
  vector<int> leaf;
  UnionFind union_find(n);
  while (!que.empty()) {
    const int ver = que.front(); que.pop();
    pinch.erase(ver);
    leaf.emplace_back(ver);
    const int dst = *graph[ver].begin();
    graph[ver].clear();
    graph[dst].erase(ver);
    union_find.unite(ver, dst);
    if (graph[dst].size() == 1) que.emplace(dst);
  }
  // cerr << "leaf:";
  // for (int e : leaf) cerr << ' ' << e + 1;
  // cerr << '\n';
  vector<int> ans(n, 1), rt(n, -1);
  for (int e : pinch) ans[e] = 0;
  for (int e : pinch) {
    if (graph[e].size() >= 3) {
      for (int child : graph[e]) {
        if (c[child] == 1) {
          REP(i, n) cout << 1 << " \n"[i + 1 == n];
          return 0;
        }
      }
    } else {
      bool can_reach = false;
      for (int child : graph[e]) can_reach |= c[child] == 1;
      if (can_reach) ans[e] = 1;
    }
    rt[union_find.root(e)] = e;
  }
  for (int e : leaf) {
    ans[e] = ans[rt[union_find.root(e)]];
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
  return 0;
}