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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

std::vector<std::vector<int>> subsequence_dp(const std::string &s, const char basis = 'a', const int sigma = 26) {
  const int n = s.size();
  std::vector<std::vector<int>> nx(n, std::vector<int>(sigma, n));
  nx[n - 1][s[n - 1] - basis] = n - 1;
  for (int i = n - 2; i >= 0; --i) {
    std::copy(nx[i + 1].begin(), nx[i + 1].end(), nx[i].begin());
    nx[i][s[i] - basis] = i;
  }
  return nx;
}

std::vector<int> topological_sort(const std::vector<std::vector<int>> &graph) {
  const int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  while (!que.empty()) {
    const int ver = que.front(); que.pop();
    res.emplace_back(ver);
    for (const int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>();
}

constexpr int C = 52;

void solve() {
  int n; cin >> n;
  vector<vector<int>> s(n);
  REP(i, n) {
    string t; cin >> t;
    for (char c : t) s[i].emplace_back('A' <= c && c <= 'Z' ? c - 'A' : c - 'a' + C / 2);
  }
  vector pos(n, vector(C, vector<int>{}));
  REP(i, n) REP(j, s[i].size()) pos[i][s[i][j]].emplace_back(j);
  map<vector<int>, int> node[C]{};
  vector<char> ch;
  int m = 0;
  REP(c, C) {
    vector<int> v;
    const auto f = [&](auto&& f, int i) -> void {
      if (i == n) {
        node[c][v] = m++;
        ch.emplace_back(c);
        return;
      }
      for (int j : pos[i][c]) {
        v.emplace_back(j);
        f(f, i + 1);
        v.pop_back();
      }
    };
    f(f, 0);
  }
  if (m == 0) {
    cout << 0 << '\n';
    return;
  }
  vector<vector<int>> graph(m);
  vector<vector<vector<int>>> dp(n);
  REP(i, n) {
    const int l = s[i].size();
    dp[i] = vector(l, vector(C, l));
    dp[i][l - 1][s[i].back()] = l - 1;
    for (int j = l - 2; j >= 0; --j) {
      copy(dp[i][j + 1].begin(), dp[i][j + 1].end(), dp[i][j].begin());
      dp[i][j][s[i][j]] = j;
    }
  }
  for (const map<vector<int>, int>& node_c : node) {
    for (const auto [v, id] : node_c) {
      bool is_end = false;
      REP(i, n) is_end |= v[i] + 1 == s[i].size();
      if (is_end) continue;
      REP(c, C) {
        vector<int> u(n);
        bool has_r = false;
        REP(i, n) {
          u[i] = dp[i][v[i] + 1][c];
          if (u[i] == s[i].size()) {
            has_r = true;
            break;
          }
        }
        if (has_r) continue;
        graph[id].emplace_back(node[c][u]);
      }
    }
  }
  const vector<int> order = topological_sort(graph);
  vector<int> dist(m, 1), to(m, -1);
  for (int i = m - 1; i >= 0; --i) {
    const int u = order[i];
    for (int v : graph[u]) {
      if (chmax(dist[u], dist[v] + 1)) to[u] = v;
    }
  }
  string ans = "";
  for (int p = max_element(ALL(dist)) - dist.begin(); p != -1; p = to[p]) {
    ans += (ch[p] < C / 2 ? 'A' + ch[p] : 'a' + (ch[p] - C / 2));
  }
  cout << ans.length() << '\n' << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}