#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  int n, k; cin >> n >> k;
  vector<int> a, b, both, nei;
  while (n--) {
    int t, ai, bi; cin >> t >> ai >> bi;
    if (ai == 0 && bi == 0) {
      nei.emplace_back(t);
    } else if (ai == 0 && bi == 1) {
      b.emplace_back(t);
    } else if (ai == 1 && bi == 0) {
      a.emplace_back(t);
    } else if (ai == 1 && bi == 1) {
      both.emplace_back(t);
    }
  }
  sort(ALL(a));
  FOR(i, 1, a.size()) a[i] += a[i - 1];
  sort(ALL(b));
  FOR(i, 1, b.size()) b[i] += b[i - 1];
  sort(ALL(both));
  FOR(i, 1, both.size()) both[i] += both[i - 1];
  sort(ALL(nei));
  if (min(a.size(), b.size()) + both.size() < k) {
    cout << -1 << '\n';
    return 0;
  }
  ll ans = LINF;
  if (a.size() >= k && b.size() >= k) chmin(ans, a[k - 1] + b[k - 1]);
  for (int i = 0; i + 1 < k && i < both.size(); ++i) {
    if (a.size() >= k - 1 - i && b.size() >= k - 1 - i) {
      chmin(ans, both[i] + a[k - 2 - i] + b[k - 2 - i]);
    }
  }
  if (both.size() >= k) chmin(ans, both[k - 1]);
  cout << ans << '\n';
  return 0;
}