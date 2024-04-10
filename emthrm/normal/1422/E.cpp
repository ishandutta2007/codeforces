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

int main() {
  string s; cin >> s;
  int n = s.length();
  vector<int> len(n);
  vector<string> ans(n);
  vector<char> nx(n + 1, '$');  // suf[min{i | suf[0] != suf[i]}]
  string suf = "";
  bool is_adj = true;
  char cur = '$';
  auto add = [&](char c) {
    suf += c;
    is_adj = true;
  };
  for (int i = n - 1; i >= 0; --i) {
    if (suf.empty()) {
      add(s[i]);
    } else if (suf.back() == s[i]) {
      if (is_adj && cur <= s[i]) {
        suf.pop_back();
        cur = nx[i + 2];
        is_adj = false;
      } else {
        add(s[i]);
      }
    } else {
      cur = suf.back();
      add(s[i]);
    }
    len[i] = suf.length();
    ans[i] = len[i] <= 10 ? suf : suf.substr(0, 2) + "..." + suf.substr(suf.length() - 5, 5);
    reverse(ALL(ans[i]));
    nx[i] = cur;
  }
  REP(i, n) cout << len[i] << ' ' << ans[i] << '\n';
  return 0;
}