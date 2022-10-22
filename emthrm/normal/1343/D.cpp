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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  map<int, vector<int>> mp;
  vector<pair<int, int>> ins;
  REP(i, n >> 1) {
    mp[a[i] + a[n - 1 - i]].emplace_back(i);
    ins.emplace_back(a[i], i);
    ins.emplace_back(a[n - 1 - i], i);
  }
  sort(ALL(ins));
  // REP(i, n) cout << ins[i].first << " \n"[i + 1 == n];
  int ans = n, l = 0, r = 0;
  map<int, int> cnt;
  FOR(sum, 2, k + k + 1) {
    while (r < n && ins[r].first < sum) ++cnt[ins[r++].second];
    while (l < n && ins[l].first < sum - k) {
      --cnt[ins[l].second];
      if (cnt[ins[l].second] == 0) cnt.erase(ins[l].second);
      ++l;
    }
    int one = cnt.size(), two = n >> 1;
    if (mp.count(sum) == 1) {
      for (int e : mp[sum]) {
        if (cnt.count(e) == 1) {
          --one;
          --two;
        }
      }
    }
    two -= one;
    // cout << cnt.size() << ' ' << one << ' ' << v.size() << '\n';
    chmin(ans, one + two * 2);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}