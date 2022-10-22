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

void solve() {
  int n, q; string s; cin >> n >> q >> s;
  vector<int> sl[2]{vector<int>(n), vector<int>(n)}, sr[2]{vector<int>(n), vector<int>(n)};
  REP(i, n) {
    const int a = (s[i] == '+' ? 1 : -1);
    REP(j, 2) {
      sl[j][i] = a * ((i & 1) == j ? 1 : -1);
      if (i > 0) sl[j][i] += sl[j][i - 1];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    const int a = (s[i] == '+' ? 1 : -1);
    REP(j, 2) {
      sr[j][i] = a * ((i & 1) == j ? 1 : -1);
      if (i + 1 < n) sr[j][i] += sr[j][i + 1];
    }
  }
  map<int, vector<int>> m[2]{};
  REP(p, 2) FOR(i, 1, n - 1) m[p][sl[p][i - 1] + sr[p ^ 1][i + 1]].emplace_back(i);
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    if ((r - l + 1) % 2 == 0) {
      if (sl[l & 1][r] - (l == 0 ? 0 : sl[l & 1][l - 1]) == 0) {
        cout << 0 << '\n';
        continue;
      }
      cout << 2 << '\n' << r + 1 << ' ';
      --r;
    } else {
      cout << 1 << '\n';
    }
    if (l == r || sr[(l + 1) & 1][l + 1] - (r + 1 == n ? 0 : sr[(l + 1) & 1][r + 1]) == 0) {
      cout << l + 1 << '\n';
    } else if (sl[l & 1][r - 1] - (l == 0 ? 0 : sl[l & 1][l - 1]) == 0) {
      cout << r + 1 << '\n';
    } else if (l > 0 && sl[(l + 1) & 1][r] - sl[(l + 1) & 1][l] == 0) {
      cout << 1 << '\n';
    } else {
      const int w = (l == 0 ? 0 : sl[l & 1][l - 1]) + (r + 1 == n ? 0 : sr[(l + 1) & 1][r + 1]);
      cout << *lower_bound(ALL(m[l & 1][w]), l + 1) + 1 << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}