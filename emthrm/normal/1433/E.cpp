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

template <typename T>
std::vector<std::vector<T>> pascal(int val) {
  std::vector<std::vector<T>> c(val + 1, std::vector<T>(val + 1, 0));
  for (int i = 0; i <= val; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
  }
  return c;
}

int main() {
  int n; cin >> n;
  auto c = pascal<ll>(n);
  vector<ll> fact(n + 1, 1);
  FOR(i, 1, n + 1) fact[i] = fact[i - 1] * i;
  cout << c[n][n / 2] * fact[n / 2 - 1] * fact[n / 2 - 1] / 2 << '\n';
  return 0;
}