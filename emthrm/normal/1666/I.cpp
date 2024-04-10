#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }

bool dig(int r, int c) {
  cout << "DIG " << r + 1 << ' ' << c + 1 << endl;
  int res; cin >> res;
  return res == 1;
}

int scan(int r, int c) {
  cout << "SCAN " << r + 1 << ' ' << c + 1 << endl;
  int d; cin >> d;
  return d;
}

void solve() {
  int n, m; cin >> n >> m;
  const int a = scan(0, 0), b = scan(0, m - 1);
  const int sum_y = (a + b - (m - 1) * 2) / 2, sum_x = a - sum_y;
  const int tmp1 = scan(sum_y / 2, 0) - sum_x, tmp2 = scan(0, sum_x / 2) - sum_y;
  int y1 = 0, y2 = sum_y, x1 = 0, x2 = sum_x;
  while (abs(sum_y / 2 - y1) + abs(y2 - sum_y / 2) != tmp1) ++y1, --y2;
  while (abs(sum_x / 2 - x1) + abs(x2 - sum_x / 2) != tmp2) ++x1, --x2;
  if (dig(y1, x1)) {
    assert(dig(y2, x2));
  } else {
    assert(dig(y1, x2) && dig(y2, x1));
  }
}

// https://twitter.com/heno_code/status/1514230942445223936
int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;

  // constexpr int N = 16;
  // FOR(n, 2, N + 1) FOR(m, n, N + 1) {
  //   const vector<pair<int, int>> p{{0, m / 2}, {n / 2, 0}, {n / 2, m - 1}, {n - 1, m / 2}};
  //   map<vector<int>, vector<tuple<int, int, int, int>>> mp;
  //   REP(y1, n) REP(x1, m) FOR(y2, y1, n) REP(x2, m) {
  //     if (y1 == y2 && x2 <= x1) continue;
  //     vector<int> dists;
  //     for (const auto [r, c] : p) {
  //       dists.emplace_back(abs(r - y1) + abs(c - x1) + abs(r - y2) + abs(c - x2));
  //     }
  //     mp[dists].emplace_back(y1, x1, y2, x2);
  //   }
  //   for (const auto [_, treasures] : mp) {
  //     if (treasures.size() == 1) continue;
  //     bool is_valid = false;
  //     REP(r, n) REP(c, m) {
  //       vector<int> ds;
  //       for (const auto [y1, x1, y2, x2] : treasures) {
  //         ds.emplace_back(abs(r - y1) + abs(c - x1) + abs(r - y2) + abs(c - x2));
  //       }
  //       sort(ALL(ds));
  //       bool is_unique = true;
  //       FOR(i, 1, ds.size()) is_unique &= ds[i - 1] != ds[i];
  //       is_valid |= is_unique;
  //     }
  //     if (!is_valid) {
  //       cout << n << ' ' << m << ": ";
  //       for (const auto [y1, x1, y2, x2] : treasures) {
  //         cout << '(' << y1 << ',' << x1 << ',' << y2 << ',' << x2 << ')';
  //       }
  //       cout << '\n';
  //     }
  //   }
  // }
}