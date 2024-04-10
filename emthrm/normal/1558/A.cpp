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
  int a, b; cin >> a >> b;
  const int game = a + b;
  vector<int> ans;
  {
    // Alice Bob...
    int low = abs(a - (game + 1) / 2), high = min((game + 1) / 2, b) + min(game / 2, a);
    assert(!((low & 1) ^ (high & 1)));
    for (int k = low; k <= high; k += 2) ans.emplace_back(k);
  }
  {
    // Bob Alice...
    int low = abs(b - (game + 1) / 2), high = min((game + 1) / 2, a) + min(game / 2, b);
    assert(!((low & 1) ^ (high & 1)));
    for (int k = low; k <= high; k += 2) ans.emplace_back(k);
  }
  sort(ALL(ans));
  ans.erase(unique(ALL(ans)), ans.end());
  const int m = ans.size();
  cout << m << '\n';
  REP(i, m) cout << ans[i] << " \n"[i + 1 == m];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}