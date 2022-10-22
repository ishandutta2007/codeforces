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

struct Xor128 {
  int rand() {
    unsigned int t = x ^ (x << 11);
    x = y; y = z; z = w; w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    return static_cast<int>(w);
  }
  int rand(int ub) {
    int res = rand() % ub;
    return res < 0 ? res + ub : res;
  }
  int rand(int lb, int ub) { return lb + rand(ub - lb); }
  long long randll() {
    unsigned long long res = static_cast<unsigned long long>(rand()) << 32;
    return static_cast<long long>(res | rand());
  }
  long long randll(long long ub) {
    long long res = randll() % ub;
    return res < 0 ? res + ub : res;
  }
  long long randll(long long lb, long long ub) { return lb + randll(ub - lb); }
private:
  unsigned int x = 123456789, y = 362436069, z = 521288629, w = static_cast<unsigned int>(std::time(nullptr));
} xor128;

void solve() {
  int n; cin >> n;
  vector<int> s(n);
  REP(i, n) cin >> s[i];
  // REP(i, n) s[i] = xor128.rand(1, 1000000001);
  // REP(i, n) cout << s[i] << " \n"[i + 1 == n];
  // vector<int> t(s);
  vector<ll> prev(n, 0);
  ll ans = 0;
  REP(i, n) {
    for (int j = i + 2; j < n && j <= i + s[i]; ++j) ++prev[j];
    if (i + 1 < n && s[i] - 1 < prev[i]) prev[i + 1] += prev[i] - (s[i] - 1);
    if (s[i] > 1) {
      s[i] = max(s[i] - prev[i], 1LL);
      ans += max(s[i] - 1, 0);
    }
  }
  cout << ans << '\n';
  // {
  //   s = t;
  //   ll ans = 0;
  //   REP(i, n) {
  //     if (s[i] > 1) {
  //       ans += max(s[i] - (n - i), 0);
  //       chmin(s[i], n - i);
  //       while (s[i] > 1) {
  //         ++ans;
  //         int p = i;
  //         while (p < n) {
  //           int nx = p + s[p];
  //           s[p] = max(s[p] - 1, 1);
  //           p = nx;
  //         }
  //       }
  //     }
  //   }
  //   cout << ans << '\n';
  // }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}