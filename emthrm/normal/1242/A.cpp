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

template <typename T>
std::vector<T> divisor(T n) {
  std::vector<T> res;
  for (T i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i);
      if (i * i != n) res.emplace_back(n / i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

int main() {
  ll n; cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  vector<ll> d = divisor(n);
  d.erase(d.begin());
  ll g = n;
  for (ll di : d) g = gcd(g, di);
  cout << g << '\n';
  return 0;
}