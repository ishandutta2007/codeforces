#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

bool is_prime(long long val) {
  if (val <= 1) return false;
  for (long long i = 2; i * i <= val; ++i) {
    if (val % i == 0) return false;
  }
  return true;
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= 10000; ++i) {
    if (!is_prime(i) && is_prime(n - 1 + i) && is_prime(i * (n - 1) + 1)) {
      REP(y, n - 1) {
        REP(x, n - 1) cout << 1 << ' ';
        cout << i << '\n';
      }
      REP(x, n - 1) cout << i << ' ';
      cout << 1 << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}