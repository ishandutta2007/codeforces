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

int main() {
  string s; cin >> s;
  const int n = s.length();
  if (n == 1) {
    cout << (s == "0" || s == "_" || s == "X" ? 1 : 0) << '\n';
    return 0;
  }
  int ans = 0;
  for (int v = 25; ; v += 25) {
    string t = to_string(v);
    if (t.length() > n) break;
    if (t.length() < n) continue;
    bool is_valid = true;
    char x = '$';
    REP(i, n) {
      if (s[i] == 'X') {
        if (x == '$') {
          x = t[i];
        } else {
          is_valid &= x == t[i];
        }
      } else if (s[i] != '_') {
        is_valid &= s[i] == t[i];
      }
    }
    ans += is_valid;
  }
  cout << ans << '\n';
  return 0;
}