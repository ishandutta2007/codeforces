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

const map<char, int> colors{
  {'r', 0},
  {'g', 1},
  {'y', 2},
};

int input() {
  char c; cin >> c;
  return colors.at(c);
}

void solve() {
  int n; cin >> n;
  const int c = input();
  string s; cin >> s;
  vector<int> t[3]{};
  REP(i, n) t[colors.at(s[i])].emplace_back(i);
  REP(i, n) t[colors.at(s[i])].emplace_back(i + n);
  int ans = 0;
  for (const int i : t[c]) {
    if (i >= n) break;
    chmax(ans, *lower_bound(ALL(t[1]), i) - i);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}