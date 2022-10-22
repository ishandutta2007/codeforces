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
  constexpr int X = 20;
  int l, r; cin >> l >> r;
  vector<int> a, b, c;
  REP(i, X - 1) REP(j, i + 1) {
    a.emplace_back(j);
    b.emplace_back(i + 1);
    c.emplace_back(1 << i);
  }
  a.emplace_back(X);
  b.emplace_back(X + 1);
  c.emplace_back(1);
  if (r < (1 << (X - 1)) && __builtin_popcount(r) > 1) {
    int msb = 31 - __builtin_clz(r), low = (1 << msb) + 1, len = r - low + 1;
    if (l <= low) {
      REP(i, X - 1) {
        if (len >> i & 1) {
          a.emplace_back(i + 1);
          b.emplace_back(X);
          c.emplace_back(low - (1 << i) - 1);
          low += 1 << i;
        }
      }
      assert(low - 1 == r);
      r = 1 << msb;
    }
  } else if (r > (1 << (X - 1))) {
    int msb = 31 - __builtin_clz(r), low = (1 << msb) + 1, len = r - low + 1;
    if (l <= low) {
      REP(i, X - 1) {
        if (len >> i & 1) {
          a.emplace_back(i + 1);
          b.emplace_back(X);
          c.emplace_back(low - (1 << i) - 1);
          low += 1 << i;
        }
      }
      assert(low - 1 == r);
      r = 1 << msb;
    }
  }
  for (int i = X - 2; i >= 0; --i) {
    if ((1 << (i + 1)) - 1 < r) {
      int w = r - ((1 << (i + 1)) - 1);
      if ((1 << i) + w >= l) {
        a.emplace_back(i + 1);
        b.emplace_back(X + 1);
        c.emplace_back(w);
        r = (1 << i) + w - 1;
      }
    }
  }
  if (l == 1 && l <= r) {
    assert(r == 1);
    a.emplace_back(0);
    b.emplace_back(X + 1);
    c.emplace_back(1);
    r = 0;
  }
  assert(r < l);
  int m = a.size();
  cout << "YES\n" << X + 2 << ' ' << m << '\n';
  REP(i, m) cout << a[i] + 1 << ' ' << b[i] + 1 << ' ' << c[i] << '\n';
  return 0;
}