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

int main() {
  int n; cin >> n;
  if (n == 2) {
    cout << 2 << ' ' << 2 << '\n'
         << 1 << ' ' << 1 << '\n';
    return 0;
  }
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector dp1(n, vector(2, 0));
  vector dp2(n, vector(2, LINF));
  auto f = [&](auto&& f, int par, int ver) -> void {
    dp1[ver][true] = dp2[ver][false] = 1;
    dp2[ver][true] = graph[ver].size();
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        dp1[ver][true] += dp1[e][false];
        dp2[ver][true] += dp2[e][false];
        dp1[ver][false] += max(dp1[e][true], dp1[e][false]);
        if (dp1[e][true] == dp1[e][false]) {
          dp2[ver][false] += min(dp2[e][true], dp2[e][false]);
        } else {
          dp2[ver][false] += dp2[e][dp1[e][true] > dp1[e][false]];
        }
      }
    }
  };
  f(f, -1, 0);
  vector<int> is_good(n, false);
  auto g = [&](auto&& g, int par, int ver, bool j) -> void {
    is_good[ver] = j;
    for (int e : graph[ver]) {
      if (e != par) {
        if (!j) {
          if (dp1[e][true] == dp1[e][false]) {
            g(g, ver, e, dp2[e][true] < dp2[e][false]);
          } else {
            g(g, ver, e, dp1[e][true] > dp1[e][false]);
          }
        } else {
          g(g, ver, e, false);
        }
      }
    }
  };
  if (dp1[0][true] == dp1[0][false]) {
    g(g, -1, 0, dp2[0][true] < dp2[0][false]);
  } else {
    g(g, -1, 0, dp1[0][true] > dp1[0][false]);
  }
  vector<int> w(n, 1);
  REP(i, n) {
    if (is_good[i]) w[i] = graph[i].size();
  }
  cout << max(dp1[0][true], dp1[0][false]) << ' ' << accumulate(ALL(w), 0LL) << '\n';
  REP(i, n) cout << w[i] << " \n"[i + 1 == n];
  return 0;
}