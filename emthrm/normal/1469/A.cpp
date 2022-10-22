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
  string s; cin >> s;
  int n = s.length(), l = count(ALL(s), '(');
  if ((n & 1) || l > n / 2) {
    cout << "NO\n";
    return;
  }
  REP(i, n) {
    if (s[i] == '?' && l < n / 2) {
      s[i] = '(';
      ++l;
    }
  }
  REP(i, n) {
    if (s[i] == '?') s[i] = ')';
  }
  int nest = 0;
  for (char c : s) {
    nest += c == '(' ? 1 : -1;
    if (nest < 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}