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

int main() {
  int n; cin >> n;
  if (n <= 2) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> x, y;
  function<void(int, int)> solve = [&](int l, int r) {
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    FOR(i, l, m) {
      x.emplace_back(i);
      y.emplace_back(m + (i - l));
    }
  };
  for (int i = 1; ; ++i) {
    if ((1 << i) >= (n + 1) / 2) {
      solve(0, 1 << i);
      if ((1 << i) + 1 < n) {
        for (int j = 1; ; ++j) {
          if ((1 << i) + (1 << j) >= n) {
            solve(n - (1 << j), n);
            break;
          }
        }
      }
      break;
    }
  }
  int q = x.size();
  assert(q <= 500000);
  cout << q << '\n';
  REP(i, q) cout << x[i] + 1 << ' ' << y[i] + 1 << '\n';
  return 0;
}