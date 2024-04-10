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

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> graph(n);
  REP(_, m) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  if (1LL * k * (k - 1) / 2 > m) {
    cout << "-1\n";
    return;
  }
  vector<int> deg(n);
  REP(i, n) {
    sort(ALL(graph[i]));
    deg[i] = graph[i].size();
  }
  set<pair<int, int>> st;
  REP(i, n) st.emplace(deg[i], i);
  vector<bool> ans(n, true);
  int vers = n;
  auto is_clique = [&](int root) {
    vector<int> cand;
    for (int e : graph[root]) {
      if (ans[e]) cand.emplace_back(e);
    }
    for (int vi : cand) {
      for (int vj : cand) {
        if (vj != vi) {
          auto it = lower_bound(ALL(graph[vi]), vj);
          if (it == graph[vi].end() || *it != vj) return false;
        }
      }
    }
    return true;
  };
  while (st.begin()->first < k && vers >= k + 1) {
    auto [d, v] = *st.begin();
    if (k * (k - 1) / 2 <= m && d == k - 1 && is_clique(v)) {
      cout << "2\n";
      for (int e : graph[v]) {
        if (ans[e]) cout << e + 1 << ' ';
      }
      cout << v + 1 << '\n';
      return;
    }
    m -= d;
    st.erase(st.begin());
    for (int e : graph[v]) {
      if (ans[e]) {
        st.erase({deg[e], e});
        st.emplace(--deg[e], e);
      }
    }
    --vers;
    ans[v] = false;
  }
  auto output = [&]() {
    vector<int> subgraph;
    REP(i, n) {
      if (ans[i]) subgraph.emplace_back(i);
    }
    REP(i, subgraph.size()) cout << subgraph[i] + 1 << " \n"[i + 1 == subgraph.size()];
  };
  if (vers >= k + 1) {
    cout << "1 " << vers << '\n';
    output();
  } else if (m == k * (k - 1) / 2) {
    cout << "2\n";
    output();
  } else {
    cout << "-1\n";
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}