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
  int h, w; cin >> h >> w;
  vector<string> s(h); REP(i, h) cin >> s[i];
  bool is_valid = true;
  REP(i, h) REP(j, w) is_valid &= s[i][j] != ((i + j) & 1 ? 'R' : 'W');
  if (is_valid) {
    cout << "YES\n";
    REP(i, h) {
      REP(j, w) cout << ((i + j) & 1 ? 'W' : 'R');
      cout << '\n';
    }
    return;
  }
  is_valid = true;
  REP(i, h) REP(j, w) is_valid &= s[i][j] != ((i + j) & 1 ? 'W' : 'R');
  if (is_valid) {
    cout << "YES\n";
    REP(i, h) {
      REP(j, w) cout << ((i + j) & 1 ? 'R' : 'W');
      cout << '\n';
    }
    return;
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}