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

void solve() {
  int n; cin >> n;
  vector<ll> d(n * 2); REP(i, n * 2) cin >> d[i];
  sort(ALL(d));
  for (int i = 0; i < n * 2; i += 2) {
    if (d[i] != d[i + 1] || d[i] % 2 == 1) {
      cout << "NO\n";
      return;
    }
  }
  if (d.back() % (n * 2) != 0) {
    cout << "NO\n";
    return;
  }
  vector<ll> a(n, d.back() / (n * 2)), b(n, d.back() / (n * 2));
  for (int i = n - 2; i >= 0; --i) {
    ll v = d[i * 2] - b[i + 1] * 2;
    if (v <= 0 || v % (n * 2 - (n - 1 - i) * 2) > 0) {
      cout << "NO\n";
      return;
    }
    a[i] = v / (n * 2 - (n - 1 - i) * 2);
    if (a[i] >= a[i + 1]) {
      cout << "NO\n";
      return;
    }
    b[i] = b[i + 1] + a[i];
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}