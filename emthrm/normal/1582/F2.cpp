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

int main() {
  constexpr int A = 5000, M = 1 << 13;
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> pos[A + 1]{};
  REP(i, n) pos[a[i]].emplace_back(i);
  int dp[M]{};
  fill(dp, dp + M, n);
  dp[0] = -1;
  REP(v, A + 1) {
    int nx[M]{};
    copy(dp, dp + M, nx);
    REP(i, M) {
      auto it = upper_bound(ALL(pos[v]), dp[i]);
      if (it != pos[v].end()) chmin(nx[i ^ v], *it);
    }
    swap(dp, nx);
  }
  vector<int> x;
  REP(i, M) {
    if (dp[i] < n) x.emplace_back(i);
  }
  const int k = x.size();
  cout << k << '\n';
  REP(i, k) cout << x[i] << " \n"[i + 1 == k];
  return 0;
}