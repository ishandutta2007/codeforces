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

void solve() {
  ll s, n, k; cin >> s >> n >> k;
  if (s == k) {
    cout << "YES\n";
    return;
  }
  if (k > s) {
    cout << "NO\n";
    return;
  }
  ll distinct = [&]() -> ll {
    if ((s + k + 1) % k == 0) return s + k + 1 - ((s + k + 1) / k % 2 == 1 ? k : 0);
    ll lb = s + 1, ub = s + k;
    while (ub - lb > 1) {
      ll mid = (lb + ub) / 2;
      (mid / k == (s + 1) / k ? lb : ub) = mid;
    }
    return s + k + 1 - (((s + 1) / k + 1) % 2 == 1 ? lb - (s + 1) + 1 : s + k - lb);
  } ();
  cout << (distinct < (n + 1) * 2 ? "YES\n" : "NO\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}