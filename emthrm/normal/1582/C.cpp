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

constexpr int C = 26;

void solve() {
  int n; string s; cin >> n >> s;
  if (equal(ALL(s), s.rbegin())) {
    cout << 0 << '\n';
    return;
  }
  int ans = INF;
  REP(c, C) {
    string t = "$";
    vector<int> p{-1};
    REP(i, n) {
      if (s[i] != 'a' + c) {
        t += s[i];
        p.emplace_back(i);
      }
    }
    t += '$';
    p.emplace_back(n);
    if (equal(ALL(t), t.rbegin())) {
      int era = n - (t.length() - 2), l = (t.length() + 1) / 2 - 1, r = t.length() / 2;
      if (l < r) era -= p[r] - p[l] - 1;
      for (; l > 0; --l, ++r) {
        era -= min(p[l] - p[l - 1] - 1, p[r + 1] - p[r] - 1) * 2;
      }
      chmin(ans, era);
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}