#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  const int X = 1000000000;
  int n, m; cin >> n >> m;
  if (n <= 2) {
    if (m > 0) {
      cout << "-1\n";
    } else if (n == 1) {
      cout << "1\n";
    } else {
      cout << "1 2\n";
    }
    return 0;
  }
  vector<int> a(n, -1);
  a[0] = 1; a[1] = 2;
  FOR(i, 2, n) {
    if (m == 0) break;
    if (m >= i / 2) {
      a[i] = a[i - 1] + 1;
      m -= i / 2;
    } else {
      a[i] = a[i - 1] + a[i - m * 2];
      m = 0;
      // cout << a[i] << ' ' << a[i - 1] + a[i - m * 2] << '\n';
    }
  }
  if (m > 0) {
    cout << "-1\n";
    return 0;
  }
  int pos = 0;
  for (; pos < n; ++pos) {
    if (a[pos] == -1) break;
  }
  if (a[n - 1] == -1) a[n - 1] = X;
  for (int i = n - 2; i >= pos; --i) {
    a[i] = a[i + 1] - (pos + 1);
  }
  REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  return 0;
}