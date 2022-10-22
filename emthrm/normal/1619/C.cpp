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
  string a, s; cin >> a >> s;
  reverse(ALL(a));
  reverse(ALL(s));
  string ans = "";
  int idx = 0;
  for (char c : a) {
    if (idx == s.length()) {
      cout << "-1\n";
      return;
    }
    const int av = c - '0';
    int sv = s[idx++] - '0';
    if (sv < av) {
      if (idx == s.length() || s[idx++] != '1') {
        cout << "-1\n";
        return;
      }
      sv += 10;
    }
    ans += '0' + (sv - av);
  }
  ans += s.substr(idx);
  while (ans.back() == '0') ans.pop_back();
  reverse(ALL(ans));
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}