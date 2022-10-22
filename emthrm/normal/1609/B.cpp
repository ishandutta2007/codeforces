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

int main() {
  int n, q; string s; cin >> n >> q >> s;
  set<int> abc;
  FOR(i, 2, n) {
    if (s.substr(i - 2, 3) == "abc") abc.emplace(i - 2);
  }
  while (q--) {
    int i; char c; cin >> i >> c; --i;
    REP(d, 3) abc.erase(i - d);
    s[i] = c;
    REP(d, 3) {
      if (i - d < 0) break;
      if (s.substr(i - d, 3) == "abc") abc.emplace(i - d);
    }
    cout << abc.size() << '\n';
  }
  return 0;
}