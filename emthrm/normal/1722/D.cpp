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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; string s; cin >> n >> s;
  ll ans = 0;
  priority_queue<int> que;
  REP(i, n) {
    if (s[i] == 'L') {
      ans += i;
      if (n - 1 - i > i) que.emplace((n - 1 - i) - i);
    } else if (s[i] == 'R') {
      ans += n - 1 - i;
      if (i > n - 1 - i) que.emplace(i - (n - 1 - i));
    }
  }
  REP(k, n) {
    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
    cout << ans << " \n"[k + 1 == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}