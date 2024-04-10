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

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  std::vector<int> data;
};

int main() {
  int n, m1, m2; cin >> n >> m1 >> m2;
  UnionFind mocha(n), diana(n);
  // UnionFind mocha_copy1(n), mocha_copy2(n), diana_copy1(n), diana_copy2(n);
  while (m1--) {
    int u, v; cin >> u >> v; --u; --v;
    mocha.unite(u, v);
    // mocha_copy1.unite(u, v);
    // mocha_copy2.unite(u, v);
  }
  while (m2--) {
    int u, v; cin >> u >> v; --u; --v;
    diana.unite(u, v);
    // diana_copy1.unite(u, v);
    // diana_copy2.unite(u, v);
  }
  map<int, vector<int>> mocha_component;
  REP(i, n) mocha_component[mocha.root(i)].emplace_back(i);
  vector<map<int, int>> group;
  for (auto [_, nodes] : mocha_component) {
    group.emplace_back();
    for (int node : nodes) group.back()[diana.root(node)] = node;
  }
  sort(ALL(group), [](const map<int, int> &a, const map<int, int> &b) -> bool { return a.size() > b.size(); });
  // REP(i, group.size()) {
  //   for (auto it = group[i].begin(); it != group[i].end(); it = next(it)) {
  //     auto [root, node] = *it;
  //     cerr << '{' << root << ", " << node << '}' << " \n"[next(it) == group[i].end()];
  //   }
  // }
  vector<int> u, v;
  int alone_root = -1;
  vector<int> alone;
  while (!group.empty()) {
    const int id = group.size() - 1;
    while (!alone.empty()) {
      if (group[id].size() == 1 && group[id].begin()->first == alone_root) break;
      auto it = group[id].lower_bound(alone_root);
      if (it != group[id].end() && it->first == alone_root) it = next(it);
      if (it == group[id].end()) it = group[id].begin();
      const int node = it->second;
      u.emplace_back(node);
      v.emplace_back(alone.back());
      diana.unite(it->first, alone_root);
      group[id].erase(it);
      group[id].erase(alone.back());
      alone.pop_back();
      alone_root = diana.root(alone_root);
      group[id][alone_root] = node;
      if (alone.empty()) alone_root = -1;
    }
    if (id > 0) {
      map<int, int> updated_group;
      for (auto [_, node] : group[id - 1]) updated_group[diana.root(node)] = node;
      group[id - 1].swap(updated_group);
    }
    if (group[id].size() == 1) {
      assert(alone_root == -1 || group[id].begin()->first == alone_root);
      alone_root = group[id].begin()->first;
      alone.emplace_back(group[id].begin()->second);
    } else {
      assert(alone_root == -1);
      if (id == 0) break;
      if (group[id - 1].size() < group[id].size()) swap(group[id - 1], group[id]);
      auto [u_root, u_node] = *group[id - 1].begin();
      auto it = group[id].lower_bound(u_root);
      if (it != group[id].end() && it->first == u_root) it = next(it);
      if (it == group[id].end()) it = group[id].begin();
      auto [v_root, v_node] = *it;
      group[id - 1].erase(group[id - 1].begin());
      group[id - 1].erase(v_root);
      group[id].erase(it);
      group[id].erase(u_root);
      u.emplace_back(u_node);
      v.emplace_back(v_node);
      diana.unite(u_root, v_root);
      group[id - 1][diana.root(u_root)] = u_node;
      for (auto [root, node] : group[id]) group[id - 1][root] = node;
    }
    group.pop_back();
  }
  const int h = u.size();
  // REP(i, h) assert(mocha_copy1.unite(u[i], v[i]) && diana_copy1.unite(u[i], v[i]));
  // int true_h = 0;
  // REP(i, n) FOR(j, i + 1, n) {
  //   if (!mocha_copy2.same(i, j) && !diana_copy2.same(i, j)) {
  //     ++true_h;
  //     mocha_copy2.unite(i, j);
  //     diana_copy2.unite(i, j);
  //   }
  // }
  // assert(true_h == h);
  cout << h << '\n';
  REP(i, h) cout << u[i] + 1 << ' ' << v[i] + 1 << '\n';
  return 0;
}