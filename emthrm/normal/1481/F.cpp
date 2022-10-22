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

int main() {
  int n, x; cin >> n >> x;
  vector<vector<int>> graph(n);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<vector<int>> dep(n);
  auto f = [&](auto &&f, int v, int d) -> void {
    dep[d].emplace_back(v);
    for (int e : graph[v]) f(f, e, d + 1);
  };
  f(f, 0, 0);
  while (dep.back().empty()) dep.pop_back();
  vector<vector<int>> cnt(n + 1);
  REP(i, dep.size()) cnt[dep[i].size()].emplace_back(i);
  vector<int> a, b;
  REP(i, n + 1) {
    if (!cnt[i].empty()) {
      a.emplace_back(i);
      b.emplace_back(cnt[i].size());
    }
  }
  int m = a.size();
  vector dp(m + 1, vector(x + 1, false));
  vector prev(m + 1, vector(x + 1, -1));
  dp[0][0] = true;
  REP(i, m) {
    vector<int> last(a[i], -1);
    REP(j, x + 1) {
      if (dp[i][j]) last[j % a[i]] = j;
      if (last[j % a[i]] != -1 && j / a[i] - last[j % a[i]] / a[i] <= b[i]) {
        dp[i + 1][j] = true;
        prev[i + 1][j] = last[j % a[i]];
      }
    }
  }
  if (dp[m][x]) {
    string ans(n, 'b');
    for (int i = m; i > 0; --i) {
      int as = (x - prev[i][x]) / a[i - 1];
      x -= as * a[i - 1];
      while (as--) {
        int d = cnt[a[i - 1]].back();
        cnt[a[i - 1]].pop_back();
        for (int e : dep[d]) ans[e] = 'a';
      }
    }
    cout << dep.size() << '\n' << ans << '\n';
  } else {
    int y = n - x;
    string ans(n, 'b');
    for (const vector<int> &d : dep) {
      int l = d.size();
      if (l <= x) {
        for (int e : d) ans[e] = 'a';
        x -= l;
      } else if (l <= y) {
        y -= l;
      } else {
        vector<int> leaf, not_leaf;
        for (int e : d) (graph[e].empty() ? leaf : not_leaf).emplace_back(e);
        if (not_leaf.size() <= x) {
          for (int e : not_leaf) ans[e] = 'a';
          x -= not_leaf.size();
          while (x--) {
            ans[leaf.back()] = 'a';
            leaf.pop_back();
          }
          y -= leaf.size();
        } else {
          assert(not_leaf.size() <= y);
          y -= not_leaf.size();
          while (y--) leaf.pop_back();
          for (int e : leaf) ans[e] = 'a';
          x -= leaf.size();
        }
      }
    }
    cout << dep.size() + 1 << '\n' << ans << '\n';
  }
  return 0;
}