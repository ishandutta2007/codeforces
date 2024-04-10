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
  int n, h, m, k; cin >> n >> h >> m >> k;
  vector<int> hi(n), mi(n); REP(i, n) cin >> hi[i] >> mi[i];
  vector<int> comp{0, m / 2};
  REP(i, n) {
    mi[i] %= m / 2;
    {
      int l = mi[i] + 1, r = min(mi[i] + k - 1, m / 2 - 1);
      // cout << l << ' ' << r << " & ";
      if (l <= r) {
        comp.emplace_back(l);
        comp.emplace_back(r + 1);
      }
    }
    {
      int l = 0, r = mi[i] + k - 1 - m / 2;
      // cout << l << ' ' << r << '\n';
      if (l <= r) {
        comp.emplace_back(l);
        comp.emplace_back(r + 1);
      }
    }
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  int x = comp.size();
  vector cnt(x, 0);
  REP(i, n) {
    {
      int l = mi[i] + 1, r = min(mi[i] + k - 1, m / 2 - 1);
      if (l <= r) {
        ++cnt[lower_bound(ALL(comp), l) - comp.begin()];
        --cnt[lower_bound(ALL(comp), r + 1) - comp.begin()];
      }
    }
    {
      int l = 0, r = mi[i] + k - 1 - m / 2;
      if (l <= r) {
        ++cnt[lower_bound(ALL(comp), l) - comp.begin()];
        --cnt[lower_bound(ALL(comp), r + 1) - comp.begin()];
      }
    }
  }
  FOR(i, 1, x) cnt[i] += cnt[i - 1];
  int idx = min_element(cnt.begin(), cnt.begin() + x - 1) - cnt.begin();
  vector<int> ans;
  REP(i, n) {
    bool to_be_removed = false;
    {
      int l = mi[i] + 1, r = min(mi[i] + k - 1, m / 2 - 1);
      if (l <= r) {
        l = lower_bound(ALL(comp), l) - comp.begin();
        r = lower_bound(ALL(comp), r + 1) - comp.begin();
        if (l <= idx && idx < r) to_be_removed = true;
      }
    }
    {
      int l = 0, r = mi[i] + k - 1 - m / 2;
      if (l <= r) {
        l = lower_bound(ALL(comp), l) - comp.begin();
        r = lower_bound(ALL(comp), r + 1) - comp.begin();
        if (l <= idx && idx < r) to_be_removed = true;
      }
    }
    if (to_be_removed) ans.emplace_back(i);
  }
  int sz = ans.size();
  cout << sz << ' ' << comp[idx] << '\n';
  REP(i, sz) cout << ans[i] + 1 << " \n"[i + 1 == sz];
  return 0;
}