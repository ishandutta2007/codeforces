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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

bool query(int a, int b, int c) {
  cout << "? " << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;
  int r; cin >> r;
  assert(r != -1);
  return r;
}

void solve() {
  int n; cin >> n;
  bool prv = query(0, 1, 2);
  int imp = -1, cre = -1;
  for (int i = 3; i < n; ++i) {
    bool nxt = query(i - 2, i - 1, i);
    if (nxt != prv) {
      if (nxt) {
        imp = i - 3;
        cre = i;
      } else {
        imp = i;
        cre = i - 3;
      }
      break;
    }
    prv = nxt;
  }
  vector<int> imps{imp};
  REP(i, n) {
    if (i != imp && i != cre && !query(imp, cre, i)) imps.emplace_back(i);
  }
  const int k = imps.size();
  cout << "! " << k;
  REP(i, k) cout << ' ' << imps[i] + 1;
  cout << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}