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

bool query(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  const int len = r - l + 1;
  int parity = 0;
  {
    int a_1; cin >> a_1;
    assert(a_1 != -1);
    parity ^= l <= a_1 && a_1 <= r;
  }
  FOR(i, 1, len) {
    int a_i; cin >> a_i;
    parity ^= l <= a_i && a_i <= r;
  }
  return parity;
}

void solve() {
  int n; cin >> n;
  int l = 1, r = n;
  while (r - l + 1 > 1) {
    const int m = (l + r) / 2;
    if (query(l, m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << "! " << l << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}