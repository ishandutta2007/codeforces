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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

struct HopcroftKarp {
  std::vector<int> match;

  explicit HopcroftKarp(const int left, const int right)
      : match(left + right, -1), left(left), t(0), level(left),
        is_used(left, -1), graph(left) {}

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
        for (const int dst : graph[ver]) {
          if (match[dst] != -1 && level[match[dst]] == -1) {
            level[match[dst]] = level[ver] + 1;
            que.emplace(match[dst]);
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
      if (tmp == 0) break;
      res += tmp;
    }
    return res;
  }

 private:
  const int left;
  int t;
  std::vector<int> level, is_used;
  std::vector<std::vector<int>> graph;

  bool dfs(const int ver) {
    is_used[ver] = t;
    for (const int dst : graph[ver]) {
      const int m = match[dst];
      if (m == -1 || (is_used[m] < t && level[m] == level[ver] + 1 && dfs(m))) {
        is_used[ver] = t;
        match[ver] = dst;
        match[dst] = ver;
        return true;
      }
    }
    return false;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> d1(n), d2(n);
  REP(i, n) cin >> d1[i];
  sort(ALL(d1));
  REP(i, n) cin >> d2[i];
  sort(ALL(d2));
  set<int> pruning;
  const auto f = [&](const ll d) -> bool {
    if (!pruning.emplace(d).second) return false;
    vector<int> ans;
    const auto index = [&](const int x) -> vector<int> {
      vector<int> res;
      for (int i = lower_bound(ALL(d2), x) - d2.begin(); i < n && d2[i] == x; ++i) {
        res.emplace_back(i);
      }
      return res;
    };
    HopcroftKarp hopcroft_karp(n, n);
    REP(i, n) {
      if (d1[i] <= d) {
        for (const int j : index(d - d1[i])) {
          hopcroft_karp.add_edge(i, j);
        }
      } else {
        for (const int j : index(d1[i] - d)) {
          hopcroft_karp.add_edge(i, j);
        }
      }
      for (const int j : index(d1[i] + d)) {
        hopcroft_karp.add_edge(i, j);
      }
    }
    if (hopcroft_karp.solve() < n) return false;
    REP(i, n) {
      const int j = hopcroft_karp.match[i] - n;
      ans.emplace_back(d1[i] + d2[j] == d || d1[i] - d == d2[j] ? d1[i] : -d1[i]);
    }
    const ll least = *min_element(ALL(ans));
    cout << "YES\n";
    if (least < 0) {
      REP(i, n) cout << ans[i] - least << " \n"[i + 1 == n];
      cout << -least << ' ' << d - least << '\n';
    } else {
      REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
      cout << 0 << ' ' << d << '\n';
    }
    return true;
  };
  REP(j, n) {
    if (f(d1.front() + d2[j]) || f(abs(d1.front() - d2[j]))) return;
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}