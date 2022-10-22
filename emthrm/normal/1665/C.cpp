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
  vector<int> deg(n, 0);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    ++deg[p];
  }
  vector<int> children{1};
  REP(i, n) {
    if (deg[i] > 0) children.emplace_back(deg[i]);
  }
  sort(ALL(children), greater<int>());
  const int m = children.size();
  vector<int> rem;
  REP(i, m) {
    if (m - i < children[i]) rem.emplace_back(children[i] - (m - i));
  }
  sort(ALL(rem));
  int lb = -1, ub = (rem.empty() ? 0 : rem.back());
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    int need = 0;
    for (int e : rem) need += max(e - mid, 0);
    (need <= mid ? ub : lb) = mid;
  }
  cout << m + ub << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}