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
  int n, k; cin >> n >> k;
  vector<int> a(n / 2), b(n / 2);
  iota(ALL(a), 0);
  REP(i, n / 2) b[i] = i ^ (n - 1);
  if (k == n - 1) {
    if (n == 4) {
      cout << "-1\n";
      return;
    }
    swap(b[0], a[1]);
    swap(b[0], b[n / 2 - 1]);
  } else {
    swap(b[0], k < n / 2 ? b[k] : a[k ^ (n - 1)]);
  }
  REP(i, n / 2) cout << a[i] << ' ' << b[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}