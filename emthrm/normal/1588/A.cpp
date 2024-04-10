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

struct HopcroftKarp {
  std::vector<int> match;

  HopcroftKarp(const int left, const int right)
  : left(left), graph(left), match(left + right, -1), level(left), is_used(left, -1) {}

  void add_edge(const int u, const int v) {
    graph[u].emplace_back(left + v);
  }

  int solve() {
    int res = 0;
    while (true) {
      std::fill(level.begin(), level.end(), -1);
      std::queue<int> que;
      for (int i = 0; i < left; ++i) {
        if (match[i] == -1) {
          que.emplace(i);
          level[i] = 0;
        }
      }
      while (!que.empty()) {
        const int ver = que.front();
        que.pop();
        for (const int e : graph[ver]) {
          if (match[e] != -1 && level[match[e]] == -1) {
            level[match[e]] = level[ver] + 1;
            que.emplace(match[e]);
          }
        }
      }
      int tmp = 0;
      for (int i = 0; i < left; ++i) {
        if (match[i] == -1) {
          tmp += dfs(i);
          ++t;
        }
      }
      if (tmp == 0) return res;
      res += tmp;
    }
  }

private:
  const int left;
  int t = 0;
  std::vector<std::vector<int>> graph;
  std::vector<int> level, is_used;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int e : graph[ver]) {
      const int m = match[e];
      if (m == -1 || (is_used[m] < t && level[m] == level[ver] + 1 && dfs(m))) {
        is_used[ver] = t;
        match[ver] = e;
        match[e] = ver;
        return true;
      }
    }
    return false;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  HopcroftKarp matching(n, n);
  REP(i, n) REP(j, n) {
    if (a[i] == b[j] || a[i] + 1 == b[j]) matching.add_edge(i, j);
  }
  cout << (matching.solve() == n ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}