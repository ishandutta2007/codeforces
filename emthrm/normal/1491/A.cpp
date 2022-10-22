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
  int n, q; cin >> n >> q;
  vector<int> a(n);
  int cnt[2] = {};
  REP(i, n) {
    cin >> a[i];
    ++cnt[a[i]];
  }
  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int x; cin >> x; --x;
      REP(i, 2) ++cnt[i];
      cnt[a[x]] -= 2;
      a[x] ^= 1;
    } else {
      int k; cin >> k;
      cout << (cnt[1] >= k ? 1 : 0) << '\n';
    }
  }
  return 0;
}