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

int query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  int p; cin >> p;
  return p - 1;
}

int main() {
  int n; cin >> n;
  int p = query(0, n - 1);
  if (p > 0 && query(0, p) == p) {
    int l = 0, r = p;
    while (r - l > 1) {
      int m = (l + r) / 2;
      (query(m, p) == p ? l : r) = m;
    }
    cout << "! " << l + 1 << endl;
  } else {
    assert(p + 1 < n);
    int l = p, r = n - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      (query(p, m) == p ? r : l) = m;
    }
    cout << "! " << r + 1 << endl;
  }
  return 0;
}