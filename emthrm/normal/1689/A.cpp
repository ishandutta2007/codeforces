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
  int n, m, k; string a, b; cin >> n >> m >> k >> a >> b;
  sort(ALL(a), greater<char>());
  sort(ALL(b), greater<char>());
  string ans = "";
  int pick_a = 2, rem = k;
  while (!a.empty() && !b.empty()) {
    bool flag = true;
    if (rem == 0) {
      flag = (pick_a == 1);
    } else if (a.back() < b.back()) {
      flag = true;
    } else {
      flag = false;
    }
    if (flag) {
      if (pick_a != 0) {
        pick_a = 0;
        rem = k;
      }
      --rem;
      ans += a.back();
      a.pop_back();
    } else {
      if (pick_a != 1) {
        pick_a = 1;
        rem = k;
      }
      --rem;
      ans += b.back();
      b.pop_back();
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}