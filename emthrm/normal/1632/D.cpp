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
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  int ans = 0;
  vector<tuple<int, int, int>> gs;
  REP(i, n) {
    int a; cin >> a;
    vector<tuple<int, int, int>> tmp;
    for (const auto [l, r, g] : gs) {
      tmp.emplace_back(l + 1, r + 1, gcd(g, a));
    }
    tmp.emplace_back(1, 1, a);
    gs.clear();
    for (const auto [l, r, g] : tmp) {
      if (gs.empty() || get<2>(gs.back()) < g) {
        gs.emplace_back(l, r, g);
      } else {
        get<0>(gs.back()) = l;
      }
    }
    bool invalid = false;
    for (const auto [l, r, g] : gs) {
      if (l <= g && g <= r) {
        invalid = true;
        break;
      }
    }
    if (invalid) {
      ++ans;
      gs.clear();
    }
    cout << ans << " \n"[i + 1 == n];
  }
  return 0;
}