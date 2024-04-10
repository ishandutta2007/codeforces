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
  int n; string s; cin >> n >> s;
  vector<int> deg(n);
  REP(i, n) deg[i] = (s[i] == '0' ? 2 : 1);
  if (const int edge = accumulate(ALL(deg), 0); edge % 2 == 1 || edge / 2 > n - 1) {
    cout << "NO\n";
    return;
  }
  vector<pair<int, int>> ans;
  if (count(ALL(s), 1) == n) {
    FOR(i, 1, n) ans.emplace_back(0, i);
  } else {
    const int root = ((find(ALL(s), '1') - s.begin()) + 1) % n;
    for (int i = (root + 1) % n; i != root; i = (i + 1) % n) {
      if (s[(i - 1 + n) % n] == '0') {
        ans.emplace_back((i - 1 + n) % n, i);
      } else {
        ans.emplace_back(root, i);
      }
    }
  }
  cout << "YES\n";
  for (const auto [u, v] : ans) cout << u + 1 << ' ' << v + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}