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
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<int> l(n), r(n); REP(i, n) cin >> l[i] >> r[i];
  int ans = 0;
  auto f = [&](auto&& f, int ver) -> ll {
    if (graph[ver].empty()) {
      ++ans;
      return r[ver];
    }
    ll s = 0;
    for (int e : graph[ver]) s += f(f, e);
    chmin(s, r[ver]);
    if (s < l[ver]) {
      ++ans;
      s = r[ver];
    }
    return s;
  };
  f(f, 0);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}