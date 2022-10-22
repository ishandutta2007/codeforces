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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<int> a(n), b(n), m(n); REP(i, n) cin >> a[i] >> b[i] >> m[i];
  map<int, vector<int>> intercept;
  REP(i, n) intercept[a[i] + b[i] - m[i]].emplace_back(i);
  vector<int> lb(n), ub(n);
  REP(i, n) {
    {
      int tmp = min(a[i], m[i]);
      ub[i] = (b[i] - (m[i] - tmp)) - (a[i] - tmp);
    }
    {
      int tmp = min(b[i], m[i]);
      lb[i] = (b[i] - tmp) - (a[i] - (m[i] - tmp));
    }
  }
  int ans = 0;
  vector<int> y(n), is_visited(n, false);
  for (auto [_, dishes_] : intercept) {
    vector<int> dishes1 = dishes_, dishes2 = dishes_;
    sort(ALL(dishes1), [&](int l, int r) -> bool { return ub[l] < ub[r]; });
    sort(ALL(dishes2), [&](int l, int r) -> bool { return lb[l] > lb[r]; });
    for (int i : dishes1) {
      if (is_visited[i]) continue;
      ++ans;
      while (!dishes2.empty() && lb[dishes2.back()] <= ub[i]) {
        const int id = dishes2.back();
        is_visited[id] = true;
        y[id] = (b[id] - a[id] + m[id] - ub[i]) / 2;
        dishes2.pop_back();
      }
    }
  }
  cout << ans << '\n';
  REP(i, n) cout << m[i] - y[i] << ' ' << y[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}