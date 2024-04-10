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

void solve() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  auto f = [&](auto&& f, int par, int ver) -> int {
    int p = 0, q = INF;
    for (int e : graph[ver]) {
      if (e != par) {
        const int c = f(f, ver, e);
        if (c == 0) {
          q = min(p, q + 1);
          ++p;
        } else {
          p += c;
          q += c;
        }
      }
    }
    return min(p, q);
  };
  REP(i, n) {
    if (graph[i].size() >= 3) {
      cout << f(f, -1, i) << '\n';
      return;
    }
  }
  cout << 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}