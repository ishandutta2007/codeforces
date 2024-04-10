#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> c = a;
  sort(ALL(c));
  vector<pair<int, int>> ans;
  REP(i, n) {
    FOR(j, i, n) {
      if (a[j] == c[i]) {
        if (i != j) {
          ans.emplace_back(i, j);
          swap(a[i], a[j]);
        }
        break;
      }
    }
  }
  vector<int> b(n); REP(i, n) cin >> b[i];
  for (const auto [i, j] : ans) swap(b[i], b[j]);
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && a[j] == a[i]) ++j;
    vector<int> d(j - i);
    copy(b.begin() + i, b.begin() + j, d.begin());
    sort(ALL(d));
    FOR(x, i, j) {
      FOR(y, x, j) {
        if (b[y] == d[x - i]) {
          if (y != x) {
            ans.emplace_back(x, y);
            swap(b[x], b[y]);
          }
          break;
        }
      }
    }
    i = j;
  }
  if (is_sorted(ALL(b))) {
    cout << ans.size() << '\n';
    for (const auto [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
  } else {
    cout << "-1\n";
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}