#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n), b(n), c(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n) cin >> c[i];
  cout << a[0] << ' ';
  bool is_a = true;
  FOR(i, 1, n - 1) {
    if (is_a) {
      if (a[i - 1] == a[i]) {
        cout << b[i] << " \n"[i + 1 == n];
        is_a = false;
      } else {
        cout << a[i] << " \n"[i + 1 == n];
        is_a = true;
      }
    } else {
      if (b[i - 1] == a[i]) {
        cout << b[i] << " \n"[i + 1 == n];
        is_a = false;
      } else {
        cout << a[i] << " \n"[i + 1 == n];
        is_a = true;
      }
    }
  }
  if (is_a) {
    if (a[n - 2] != a[n - 1] && a[n - 1] != a[0]) {
      cout << a[n - 1] << '\n';
    } else if (a[n - 2] != b[n - 1] && b[n - 1] != a[0]) {
      cout << b[n - 1] << '\n';
    } else {
      cout << c[n - 1] << '\n';
    }
  } else {
    if (b[n - 2] != a[n - 1] && a[n - 1] != a[0]) {
      cout << a[n - 1] << '\n';
    } else if (b[n - 2] != b[n - 1] && b[n - 1] != a[0]) {
      cout << b[n - 1] << '\n';
    } else {
      cout << c[n - 1] << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}