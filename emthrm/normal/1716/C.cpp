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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

vector<int> make_l(const vector<int>& a) {
  const int m = a.size();
  vector<int> l(m, 0);
  l.back() = a.back() + 1;
  for (int j = m - 2, t = l.back() - 1; j >= 0; --j, --t) {
    if (t > a[j]) {
      l[j] = l[j + 1];
    } else {
      l[j] = a[j] + m - j;
      t = a[j] + 1;
    }
  }
  return l;
}

vector<int> make_r(const vector<int>& a) {
  const int m = a.size();
  vector<int> r(m, 0);
  r.back() = a.back() + 1;
  for (int j = m - 2, t = r.back() + 1; j >= 0; --j, ++t) {
    if (t > a[j]) {
      r[j] = r[j + 1];
    } else {
      t = a[j] + 1;
      r[j] = t - (m - 1 - j);
    }
  }
  return r;
}

void solve() {
  int m; cin >> m;
  vector a(2, vector(m, 0)); REP(i, 2) REP(j, m) cin >> a[i][j];
  a[0][0] = -1;
  vector<vector<int>> l(2), r(2);
  REP(i, 2) {
    l[i] = make_l(a[i]);
    r[i] = make_r(a[i]);
  }
  auto step = [&](const int y, const int x, const int t) -> int {
    return max(t, a[y][x]) + 1;
  };
  int ans = max(r[1][0], max(m - 1, l[0][0]) + 1) + m - 1;
  for (int j = 1, t = step(0, 1, step(1, 1, step(1, 0, 0))); ; j += 2) {
    if (j + 1 == m) {
      chmin(ans, t);
      break;
    }
    chmin(ans, max(r[1][j + 1], max(t + m - 1 - j, l[0][j]) + 1) + m - 2 - j);
    if (j + 2 >= m) break;
    t = step(0, j + 1, t);
    t = step(1, j + 1, t);
    t = step(1, j + 2, t);
    t = step(0, j + 2, t);
  }
  for (int j = 0, t = step(1, 0, 0); ; j += 2) {
    if (j + 1 == m) {
      chmin(ans, t);
      break;
    }
    chmin(ans, max(r[0][j + 1], max(t + m - 1 - j, l[1][j]) + 1) + m - 2 - j);
    if (j + 2 >= m) break;
    t = step(1, j + 1, t);
    t = step(0, j + 1, t);
    t = step(0, j + 2, t);
    t = step(1, j + 2, t);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}