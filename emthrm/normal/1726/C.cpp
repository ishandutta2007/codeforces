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
  vector<int> cls(n * 2, -1), ls;
  REP(i, n * 2) {
    if (s[i] == '(') {
      ls.emplace_back(i);
    } else if (s[i] == ')') {
      cls[ls.back()] = i;
      ls.pop_back();
    }
  }
  int ans = 0;
  const auto f = [&](auto&& f, const int l, const int r) -> void {
    if (r <= l) return;
    ++ans;
    for (int i = l; i < r; i = cls[i] + 1) {
      f(f, i + 1, cls[i]);
    }
  };
  f(f, 0, n * 2);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}