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
  int n; cin >> n;
  vector<int> a;
  REP(i, n) {
    int ai; cin >> ai;
    if (ai == 0) continue;
    a.emplace_back(abs(ai));
  }
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  if (a.size() < n) {
    cout << "YES\n";
    return;
  }
  set<int> sum;
  FOR(b, 1, 1 << n) {
    int s = 0;
    REP(i, n) {
      if (b >> i & 1) s += a[i];
    }
    if (!sum.emplace(s).second) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}