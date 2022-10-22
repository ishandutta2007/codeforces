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

void solve() {
  int n; string s; cin >> n >> s;
  auto f = [&](int a, int l, int r) -> bool {
    if ((r - l - a + 1) / 2 >= a) return false;
    int most = 0;
    for (char c : vector<char>{'b', 'c'}) {
      chmax(most, count(s.begin() + l, s.begin() + r, c));
    }
    return most < a;
  };
  vector<int> a;
  REP(i, n) {
    if (s[i] == 'a') a.emplace_back(i);
  }
  int ans = INF;
  FOR(i, 1, a.size()) {
    if (f(2, a[i - 1], a[i] + 1)) chmin(ans, a[i] - a[i - 1] + 1);
  }
  FOR(i, 2, a.size()) {
    if (f(3, a[i - 2], a[i] + 1)) chmin(ans, a[i] - a[i - 2] + 1);
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}