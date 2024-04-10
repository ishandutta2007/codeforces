#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<char> c(n * 2);
  vector<int> x(n * 2);
  REP(i, n * 2) {
    cin >> c[i];
    if (c[i] == '-') cin >> x[i], --x[i];
  }
  vector<int> ans, sta;
  for (int i = n * 2 - 1; i >= 0; --i) {
    if (c[i] == '+') {
      if (sta.empty()) {
        cout << "NO\n";
        return 0;
      }
      ans.emplace_back(sta.back());
      sta.pop_back();
    } else if (c[i] == '-') {
      if (!sta.empty() && x[i] > sta.back()) {
        cout << "NO\n";
        return 0;
      }
      sta.emplace_back(x[i]);
    }
  }
  assert(ans.size() == n);
  cout << "YES\n";
  reverse(ALL(ans));
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}