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
  vector<int> a(n * 2); REP(i, n * 2) cin >> a[i];
  sort(ALL(a));
  for (int i = n * 2 - 2; i >= 0; --i) {
    set<pair<int, int>> st;
    REP(j, n * 2 - 1) {
      if (j != i) st.emplace(a[j], j);
    }
    vector<int> ans1(n, a[n * 2 - 1]), ans2(n, a[i]);
    vector<bool> used(n * 2, false);
    used[n * 2 - 1] = used[i] = true;
    int x = a[n * 2 - 1], pos = n * 2 - 2;
    FOR(j, 1, n) {
      while (used[pos]) --pos;
      auto it = st.lower_bound({x - a[pos], 0});
      if (it == st.end() || it->first + a[pos] > x) break;
      ans1[j] = a[pos];
      ans2[j] = it->first;
      used[pos] = used[it->second] = true;
      x = a[pos];
      st.erase(it);
    }
    if (count(ALL(used), false) == 0) {
      cout << "YES\n" << ans1[0] + ans2[0] << '\n';
      REP(j, n) cout << ans1[j] << ' ' << ans2[j] << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}