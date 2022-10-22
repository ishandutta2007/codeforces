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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int>> right(n);
  REP(i, n) {
    FOR(j, i + 1, n) {
      if (a[i] > a[j]) right[i].emplace_back(j);
    }
    sort(ALL(right[i]), [&](int l, int r) {
      return a[l] == a[r] ? l > r : a[l] > a[r];
    });
  }
  vector<int> u, v;
  REP(i, n) {
    for (int idx : right[i]) {
      u.emplace_back(i);
      v.emplace_back(idx);
      swap(a[i], a[idx]);
    }
  }
  // REP(i, n) cout << a[i] << " \n"[i + 1 == n];
  assert(is_sorted(ALL(a)));
  int m = u.size();
  cout << m << '\n';
  REP(i, m) cout << u[i] + 1 << ' ' << v[i] + 1 << '\n';
  return 0;


  // vector<pair<int, int>> p;
  // REP(i, n) FOR(j, i + 1, n) {
  //   if (a[i] > a[j]) p.emplace_back(i, j);
  // }
  // vector<int> idx(p.size());
  // iota(ALL(idx), 0);
  // do {
  //   vector<int> b(a);
  //   REP(i, p.size()) {
  //     auto [x, y] = p[idx[i]];
  //     swap(b[x], b[y]);
  //   }
  //   if (is_sorted(ALL(b))) {
  //     REP(i, p.size()) {
  //       auto [x, y] = p[idx[i]];
  //       cout << x << ' ' << y << '\n';
  //     }
  //     return 0;
  //   }
  // } while (next_permutation(ALL(idx)));
}