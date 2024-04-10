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
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

ll nCk(int n, int k) {
  if (k == 0) return 1;
  if (k == 1) return n;
  if (k == 2) return 1LL * n * (n - 1) / 2;
  if (k == 3) return 1LL * n * (n - 1) * (n - 2) / 6;
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
    vector<int> pos(n);
    iota(ALL(pos), 0);
    sort(ALL(pos), [&](int l, int r) { return a[l] < a[r]; });
    ll ans = 0;
    int j = 0;
    for (int i = 0; i < n;) {
      while (j < n && a[pos[j]] - a[pos[i]] <= 2) ++j;
      int k = i + 1;
      while (k < j && a[pos[k]] == a[pos[i]]) ++k;
      if (j - i >= 3) {
        for (int x = 1; x <= k - i && x <= 3; ++x) {
          ans += nCk(k - i, x) * nCk((j - i) - (k - i), 3 - x);
        }
      }
      i = k;
    }
    cout << ans << '\n';
  }
  return 0;
}