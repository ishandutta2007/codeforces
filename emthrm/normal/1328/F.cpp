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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> comp(a);
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  int m = comp.size();
  vector<int> cnt(m, 0);
  REP(i, n) {
    a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
    ++cnt[a[i]];
  }
  REP(i, m) {
    if (cnt[i] >= k) {
      cout << "0\n";
      return 0;
    }
  }
  int l_sz = 0, r_sz = 0;
  ll l = 0, r = 0;
  FOR(i, 1, m) {
    r += 1LL * (comp[i] - comp[0]) * cnt[i];
    r_sz += cnt[i];
  }
  ll ans = LINF;
  REP(i, m) {
    if (cnt[i] + l_sz >= k) chmin(ans, l - (cnt[i] + l_sz - k));
    if (cnt[i] + r_sz >= k) chmin(ans, r - (cnt[i] + r_sz - k));
    if (cnt[i] + l_sz < k && cnt[i] + r_sz < k) chmin(ans, l + r - (n - k));
    l_sz += cnt[i];
    if (i + 1 < m) {
      l += 1LL * (comp[i + 1] - comp[i]) * l_sz;
      r -= 1LL * (comp[i + 1] - comp[i]) * r_sz;
      r_sz -= cnt[i + 1];
    }
  }
  cout << ans << '\n';
  return 0;
}