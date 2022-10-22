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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  int m = *max_element(ALL(a)) + 1;
  if (m >= n) {
    cout << "0\n";
    return;
  }
  vector<int> l1, l2;
  vector<bool> used(m, false);
  REP(i, n) {
    if (used[a[i]]) {
      if (i == m) {
        vector<int> r(a.begin() + i, a.end());
        sort(ALL(r));
        r.erase(unique(ALL(r)), r.end());
        if (r.size() == n - m && r[0] == 0 && r[n - m - 1] == n - m - 1) {
          l1.emplace_back(i);
          l2.emplace_back(n - i);
        }
      }
      break;
    }
    used[a[i]] = true;
  }
  fill(ALL(used), false);
  reverse(ALL(a));
  REP(i, n) {
    if (used[a[i]]) {
      if (i == m) {
        vector<int> r(a.begin() + i, a.end());
        sort(ALL(r));
        r.erase(unique(ALL(r)), r.end());
        if (r.size() == n - m && r[0] == 0 && r[n - m - 1] == n - m - 1) {
          l2.emplace_back(i);
          l1.emplace_back(n - i);
        }
      }
      break;
    }
    used[a[i]] = true;
  }
  if (l1.size() == 2 && l1[0] == l1[1]) {
    l1.pop_back();
    l2.pop_back();
  }
  cout << l1.size() << '\n';
  REP(i, l1.size()) cout << l1[i] << ' ' << l2[i] << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}