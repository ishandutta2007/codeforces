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

int main() {
  int n, m; cin >> n >> m;
  vector s(n + 1, vector(m + 1, 0));
  REP(i, n) REP(j, m) {
    char c; cin >> c;
    s[i][j] = (c == 'W' ? 0 : 1);
  }
  REP(i, n) REP(j, m) s[i][j] = s[i][j] ^ s[i + 1][j] ^ s[i][j + 1] ^ s[i + 1][j + 1];
  int ans = 0;
  REP(i, n) ans += accumulate(ALL(s[i]), 0);
  HopcroftKarp bm(n - 1, m - 1);
  FOR(i, 1, n) FOR(j, 1, m) {
    if (s[i - 1][j - 1] == 1 && s[n - 1][j - 1] == 1 && s[i - 1][m - 1] == 1) {
      bm.add_edge(i - 1, j - 1);
    }
  }
  int three = bm.solve();
  ans -= three;
  if (s[n - 1][m - 1] == 1 && !(s[n - 1][m - 1] ^ (three & 1))) {
    --ans;
  } else if (s[n - 1][m - 1] == 0 && (s[n - 1][m - 1] ^ (three & 1))) {
    ++ans;
  }
  cout << ans << '\n';
  return 0;
}