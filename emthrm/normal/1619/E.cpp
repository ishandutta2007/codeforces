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

void solve() {
  int n; cin >> n;
  vector<int> num(n + 1, 0);
  REP(i, n) {
    int a; cin >> a;
    ++num[a];
  }
  ll ans = 0;
  bool is_finished = false;
  multiset<int> can_use;
  REP(mex, n + 1) {
    if (is_finished) {
      cout << "-1" << " \n"[mex == n];
      continue;
    }
    if (num[mex] == 0) {
      cout << ans << " \n"[mex == n];
      if (can_use.empty()) {
        is_finished = true;
      } else {
        ans += mex - *can_use.rbegin();
        can_use.erase(prev(can_use.end()));
      }
    } else {
      cout << ans + num[mex] << " \n"[mex == n];
      REP(_, num[mex] - 1) can_use.emplace(mex);
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}