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

ll query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  ll x; cin >> x;
  assert(x != -1);
  return x;
}

void solve() {
  int n; cin >> n;
  const ll inv = query(0, n - 1);
  int l = 2, r = n - 1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    (query(0, m) == inv ? r : l) = m;
  }
  const int j = r - (inv - query(0, r - 1));
  const int i = (j - 1) - (query(0, j - 1) - query(0, j - 2));
  cout << "! " << i + 1 << ' ' << j + 1 << ' ' << r + 1 << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}