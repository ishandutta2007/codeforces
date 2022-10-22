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

bool is_crossed(int x1, int y1, int x2, int y2) {
  if (x1 > y1) swap(x1, y1);
  return (x1 < x2 && x2 < y1) ^ (x1 < y2 && y2 < y1);
}

void solve() {
  int n, k; cin >> n >> k;
  vector<int> x(k), y(k); REP(i, k) cin >> x[i] >> y[i], --x[i], --y[i];
  vector<int> is_endpoint(n * 2, false);
  REP(i, k) is_endpoint[x[i]] = is_endpoint[y[i]] = true;
  vector<int> v;
  REP(i, n * 2) {
    if (!is_endpoint[i]) v.emplace_back(i);
  }
  REP(i, n - k) {
    x.emplace_back(v[i]);
    y.emplace_back(v[n - k + i]);
  }
  int ans = 0;
  REP(i, n) FOR(j, i + 1, n) ans += is_crossed(x[i], y[i], x[j], y[j]);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}