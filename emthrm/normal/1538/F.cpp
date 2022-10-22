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

constexpr int D = 9;
int add[D + 1]{};

int f(int n) {
  string s = to_string(n);
  reverse(ALL(s));
  int ans = 0;
  REP(i, s.length()) ans += add[i] * (s[i] - '0');
  return ans;
}

void solve() {
  int l, r; cin >> l >> r;
  cout << f(r) - f(l) << '\n';
}

int main() {
  add[0] = 1;
  FOR(i, 1, D + 1) add[i] = add[i - 1] * 10 + 1;

  int t; cin >> t;
  while (t--) solve();
  return 0;
}