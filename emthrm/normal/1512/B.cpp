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
  int n; cin >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<int> r, c;
  REP(i, n) REP(j, n) {
    if (s[i][j] == '*') {
      r.emplace_back(i);
      c.emplace_back(j);
    }
  }
  if (r[0] == r[1]) {
    int nr = (r[0] == 0 ? 1 : r[0] - 1);
    s[nr][c[0]] = s[nr][c[1]] = '*';
  } else if (c[0] == c[1]) {
    int nc = (c[0] == 0 ? 1 : c[0] - 1);
    s[r[0]][nc] = s[r[1]][nc] = '*';
  } else {
    s[r[0]][c[1]] = s[r[1]][c[0]] = '*';
  }
  REP(i, n) cout << s[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}