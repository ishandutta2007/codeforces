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
std::vector<T> divisor(T val) {
  std::vector<T> res;
  for (T i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int lb = *max_element(ALL(a)), ac = accumulate(ALL(a), 0);
  for (int d : divisor(ac)) {
    if (d < lb) continue;
    bool ok = true;
    for (int i = 0; i < n;) {
      int sum = 0, j = i;
      while (j < n && sum + a[j] <= d) sum += a[j++];
      if (sum != d) {
        ok = false;
        break;
      }
      i = j;
    }
    if (ok) {
      cout << n - ac / d << '\n';
      return;
    }
  }
  cout << n - 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}