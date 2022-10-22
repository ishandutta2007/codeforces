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
  int n, a, b; cin >> n >> a >> b;
  if (a + b > n - 2 || abs(a - b) > 1) {
    cout << "-1\n";
    return;
  }
  vector<int> ans;
  if (a == b) {
    ans.emplace_back(1);
    int l = 2, r = n;
    REP(_, a) {
      ans.emplace_back(r--);
      ans.emplace_back(l++);
    }
    FOR(i, l, r + 1) ans.emplace_back(i);
  } else if (a == b + 1) {
    ans.emplace_back(1);
    int l = 2, r = n;
    REP(_, b) {
      ans.emplace_back(r--);
      ans.emplace_back(l++);
    }
    for (int i = r; i >= l; --i) ans.emplace_back(i);
  } else {  // a + 1 == b
    ans.emplace_back(n);
    int l = 1, r = n - 1;
    REP(_, a) {
      ans.emplace_back(l++);
      ans.emplace_back(r--);
    }
    FOR(i, l, r + 1) ans.emplace_back(i);
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}