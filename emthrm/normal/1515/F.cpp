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
  int n, m, X; cin >> n >> m >> X;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  if (accumulate(ALL(a), 0LL) < (n - 1LL) * X) {
    cout << "NO\n";
    return 0;
  }
  vector<int> x(m), y(m);
  vector<unordered_set<int>> graph(n);
  REP(i, m) {
    cin >> x[i] >> y[i]; --x[i]; --y[i];
    graph[x[i]].emplace(i);
    graph[y[i]].emplace(i);
  }
  set<pair<ll, int>> que;
  REP(i, n) que.emplace(-a[i], i);
  UnionFind uf(n);
  vector<int> ans;
  while (uf.size(0) < n && !que.empty()) {
    auto [_, id] = *que.begin();
    que.erase(que.begin());
    while ((que.empty() || a[id] >= -que.begin()->first) && !graph[id].empty()) {
      int edge = *graph[id].begin(), dst = uf.root(uf.root(x[edge]) == id ? y[edge] : x[edge]);
      graph[id].erase(edge);
      graph[dst].erase(edge);
      if (id != dst) {
        ans.emplace_back(edge);
        ll ton = a[id] + a[dst] - X;
        que.erase({-a[dst], dst});
        a[id] = a[dst] = 0;
        if (graph[id].size() < graph[dst].size()) swap(graph[id], graph[dst]);
        while (!graph[dst].empty()) {
          graph[id].emplace(*graph[dst].begin());
          graph[dst].erase(graph[dst].begin());
        }
        assert(uf.unite(id, dst));
        if (uf.root(id) != id) {
          swap(graph[id], graph[dst]);
          id = uf.root(id);
        }
        a[id] = ton;
      }
    }
    if (!graph[id].empty()) que.emplace(-a[id], id);
  }
  cout << "YES\n";
  REP(i, n - 1) cout << ans[i] + 1 << '\n';
  return 0;
}