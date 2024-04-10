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
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  n = a.size();
  vector<int> d(n);
  vector<vector<int>> indices(a.front());
  int maxi = -1;
  REP(i, n) {
    d[i] = a[i] / k;
    if (d[i] < a.front()) indices[d[i]].emplace_back(i);
    chmax(maxi, d[i]);
  }
  int ans = a.back() - a.front();
  REP(i, a.front()) {
    chmin(ans, maxi - i);
    for (const int id : indices[i]) {
      const int nxt = a[id] / (d[id] + 1);
      assert(nxt > 0);
      d[id] = a[id] / nxt;
      if (d[id] < a.front()) indices[d[id]].emplace_back(id);
      chmax(maxi, d[id]);
    }
    indices[i].clear();
    indices[i].shrink_to_fit();
  }
  chmin(ans, maxi - a.front());
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}