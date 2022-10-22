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
  vector<ll> b(n); REP(i, n) cin >> b[i];
  ll s = accumulate(ALL(b), 0LL);
  if (s % (n * (n + 1) / 2) != 0) {
    cout << "NO\n";
    return;
  }
  s /= n * (n + 1) / 2;
  vector<ll> c(n, 0);
  REP(i, n) {
    const ll x = b[i] - b[(i - 1 + n) % n], y = b[(i + 1) % n] - b[i];
    ll z = y - x;
    if (z % n != 0) {
      cout << "NO\n";
      return;
    }
    z /= n;
    if (i + 1 == n) {
      if (c[i] - z != 0) {
        cout << "NO\n";
        return;
      }
    } else {
      c[i + 1] = c[i] - z;
    }
  }
  s -= accumulate(ALL(c), 0LL);
  if (s % n != 0 || s / n + *min_element(ALL(c)) <= 0) {
    cout << "NO\n";
    return;
  }
  s /= n;
  cout << "YES\n";
  REP(i, n) cout << s + c[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}