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

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

int main() {
  int n, k; cin >> n >> k;
  vector<int> p(n); REP(i, n) cin >> p[i], --p[i];
  vector<vector<int>> help(n);
  vector<int> deg(n, 0);
  while (k--) {
    int x, y; cin >> x >> y; --x; --y;
    help[x].emplace_back(y);
    ++deg[y];
  }
  vector<vector<int>> v;
  vector<int> id(n, -1), rank(n, -1);
  REP(i, n) {
    if (deg[i] == 0) {
      id[i] = v.size();
      rank[i] = 0;
      v.emplace_back(vector<int>{i});
      int pos = i;
      for (int r = 1; !help[pos].empty(); ++r) {
        assert(help[pos].size() == 1);
        pos = help[pos].front();
        id[pos] = id[i];
        rank[pos] = r;
        v.back().emplace_back(pos);
      }
    }
  }
  if (count(ALL(id), -1) > 0) {
    cout << "0\n";
    return 0;
  }
  int m = *max_element(ALL(id)) + 1;
  vector<vector<int>> graph(m);
  REP(i, n) {
    if (p[i] != -1) {
      int u = id[p[i]], v = id[i];
      if (u == v) {
        if (rank[p[i]] > rank[i]) {
          cout << "0\n";
          return 0;
        }
      } else {
        graph[u].emplace_back(v);
      }
    }
  }
  vector<int> ts = topological_sort(graph);
  if (ts.empty()) {
    cout << "0\n";
    return 0;
  }
  vector<int> q;
  for (int e : ts) copy(ALL(v[e]), back_inserter(q));
  assert(q.size() == n);
  REP(i, n) cout << q[i] + 1 << " \n"[i + 1 == n];
  return 0;
}