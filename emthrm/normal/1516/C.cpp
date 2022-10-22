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
  constexpr int M = 100 * 2000 / 2;
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int x = accumulate(ALL(a), 0);
  if (x & 1) {
    cout << 0 << '\n';
    return 0;
  }
  auto f = [&](int rem) -> bool {
    if (rem != -1 && (a[rem] & 1)) return false;
    bitset<M + 1> bit = 0;
    bit.set(0);
    REP(i, n) {
      if (i != rem) bit |= bit << a[i];
    }
    return bit[(x - (rem == -1 ? 0 : a[rem])) / 2];
  };
  if (!f(-1)) {
    cout << 0 << '\n';
    return 0;
  }
  REP(i, n) {
    if (!f(i)) {
      cout << 1 << '\n' << i + 1 << '\n';
      return 0;
    }
  }
  assert(false);
}