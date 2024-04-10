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
  int n; cin >> n;
  vector<ll> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
  __int128 item = accumulate(ALL(a), static_cast<__int128>(0)), ans = item * 2;
  map<ll, __int128> m;
  REP(i, n) m[b[i]] += a[i];
  while (true) {
    while (!m.empty() && m.rbegin()->first >= item) m.erase(prev(m.end()));
    if (m.empty()) break;
    __int128 one = min(m.rbegin()->second, item - m.rbegin()->first);
    item -= one;
    ans -= one;
    m.erase(prev(m.end()));
  }
  cout << static_cast<ll>(ans) << '\n';
  return 0;
}