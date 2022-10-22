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
  int n; ll W; cin >> n >> W;
  vector<pair<int, int>> w(n);
  REP(i, n) {
    w[i].second = i;
    cin >> w[i].first;
  }
  sort(ALL(w));
  while (!w.empty() && w.back().first > W) w.pop_back();
  n = w.size();
  ll sum = 0;
  REP(i, n) sum += w[i].first;
  if (sum < (W + 1) / 2) {
    cout << "-1\n";
    return;
  }
  sum = 0;
  vector<int> ans;
  for (int i = n - 1; i >= 0; --i) {
    if (sum + w[i].first <= W) {
      sum += w[i].first;
      ans.emplace_back(w[i].second);
    }
  }
  assert(sum >= (W + 1) / 2);
  int m = ans.size();
  cout << m << '\n';
  REP(i, m) cout << ans[i] + 1 << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}