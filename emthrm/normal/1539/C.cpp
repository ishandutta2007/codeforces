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
  int n; ll k, x; cin >> n >> k >> x;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  vector<ll> diff;
  FOR(i, 1, n) {
    if (a[i] - a[i - 1] > x) diff.emplace_back(a[i] - a[i - 1]);
  }
  sort(ALL(diff), greater<ll>());
  while (!diff.empty() && k > 0) {
    ll need = (diff.back() - 1) / x;
    if (need > k) break;
    diff.pop_back();
    k -= need;
  }
  cout << diff.size() + 1 << '\n';
  return 0;
}