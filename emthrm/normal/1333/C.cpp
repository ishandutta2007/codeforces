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
  int n; cin >> n;
  vector<ll> a(n); REP(i, n) cin >> a[i];
  vector<ll> sum(a);
  map<ll, set<int>> mp;
  REP(i, n) {
    if (i > 0) sum[i] += sum[i - 1];
    mp[sum[i]].emplace(i);
  }
  vector<int> r(n);
  ll now = 0;
  REP(i, n) {
    if (mp.count(now) == 0) {
      r[i] = n;
    } else {
      r[i] = *mp[now].lower_bound(i);
    }
    mp[sum[i]].erase(i);
    if (mp[sum[i]].empty()) mp.erase(sum[i]);
    now += a[i];
  }
  for (int i = n - 2; i >= 0; --i) chmin(r[i], r[i + 1]);
  ll ans = 0;
  REP(i, n) ans += r[i] - i;
  cout << ans << '\n';
  return 0;
}