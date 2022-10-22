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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  if (m & 1) {
    cout << "YES\n";
    REP(i, m + 1) cout << (i & 1) + 1 << " \n"[i == m];
    return;
  }
  REP(i, n) FOR(j, i + 1, n) {
    if (s[i][j] == s[j][i]) {
      cout << "YES\n";
      REP(k, m + 1) cout << (k & 1 ? i : j) + 1 << " \n"[k == m];
      return;
    }
  }
  if (n == 2) {
    cout << "NO\n";
    return;
  }
  REP(i, n) {
    int a = -1, b = -1;
    REP(j, n) {
      if (s[i][j] == 'a') a = j;
      if (s[i][j] == 'b') b = j;
    }
    if (a == -1 || b == -1) continue;
    cout << "YES\n";
    if (m % 4 == 0) {
      cout << i + 1;
      for (int l = 0; l < m; l += 4) cout << ' ' << a + 1 << ' ' << i + 1 << ' ' << b + 1 << ' ' << i + 1;
      cout << '\n';
    } else {
      cout << a + 1 << ' ' << i + 1;
      for (int l = 1; l < m - 1; l += 4) cout << ' ' << a + 1 << ' ' << i + 1 << ' ' << b + 1 << ' ' << i + 1;
      cout << ' ' << b + 1 << '\n';
    }
    return;
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}