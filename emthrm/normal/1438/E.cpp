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

int solve(const vector<int> &a) {
  int n = a.size();
  vector<ll> b(n, 0);
  REP(i, n) b[i] = a[i] + (i > 0 ? b[i - 1] : 0);
  vector<vector<int>> clz(30);
  REP(i, n) clz[31 - __builtin_clz(a[i])].emplace_back(i);
  int ans = 0;
  REP(i, n) {
    int c = 31 - __builtin_clz(a[i]);
    if (int nxt = upper_bound(ALL(clz[c]), i) - clz[c].begin(); nxt < clz[c].size()) {
      nxt = clz[c][nxt];
      if (i + 1 < nxt && nxt < n && a[i] > a[nxt]) ans += (a[i] ^ a[nxt]) == b[nxt - 1] - b[i];
    }
    int lb = i, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) >> 1;
      (b[mid] - b[i] < (1 << c) ? lb : ub) = mid;
    }
    ++lb;
    while (lb + 1 < n && b[lb] - b[i] < (1 << (c + 1))) {
      if (a[i] > a[lb + 1]) ans += (a[i] ^ a[lb + 1]) == b[lb] - b[i];
      ++lb;
    }
  }
  return ans;
}

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  int ans = solve(a);
  reverse(ALL(a));
  ans += solve(a);
  cout << ans << '\n';
  return 0;
}