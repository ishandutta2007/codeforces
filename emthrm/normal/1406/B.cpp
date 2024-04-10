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

void solve() {
  int n; cin >> n;
  vector<int> neg, pos;
  while (n--) {
    int a; cin >> a;
    (a < 0 ? neg : pos).emplace_back(a);
  }
  sort(ALL(neg));
  int neg_sz = neg.size();
  sort(ALL(pos));
  int pos_sz = pos.size();
  ll ans = -LINF;
  for (int i = 0; i <= pos_sz && i <= 5; ++i) {
    if (5 - i > neg_sz) continue;
    ll cur = 1;
    if (i & 1) {
      for (int j = pos_sz - 1; j >= pos_sz - i; --j) cur *= pos[j];
      REP(j, 5 - i) cur *= neg[j];
      assert(cur >= 0);
      chmax(ans, cur);
    } else {
      REP(j, i) cur *= pos[j];
      for (int j = neg_sz - 1; j >= neg_sz - (5 - i); --j) cur *= neg[j];
      assert(cur <= 0);
      chmax(ans, cur);
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}