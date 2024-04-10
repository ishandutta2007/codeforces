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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  map<int, int> nums;
  REP(i, n) ++nums[a[i]];
  vector<pair<int, int>> b;
  b.reserve(nums.size());
  for (const auto [a_i, num] : nums) b.emplace_back(num, a_i);
  sort(ALL(b));
  const int m = b.size();
  map<int, vector<int>> to;
  vector<int> deg(m);
  REP(i, m) deg[i] = b[i].first;
  for (int i = 0, d = b.back().first; i < m; ++i) {
    for (; deg[i] > 0 && d > 0; --deg[i], --d) {
      to[b.back().second].emplace_back(b[i].second);
    }
  }
  for (int i = 0, j = 0; i < m - 1; ++i) {
    for (int d = b[i].first; d > 0; --d) {
      while (deg[j] == 0) ++j;
      to[b[i].second].emplace_back(b[j].second);
      --deg[j];
    }
  }
  REP(i, n) {
    cout << to[a[i]].back() << " \n"[i + 1 == n];
    to[a[i]].pop_back();
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}