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
  vector<int> b(n / 3);
  int block[2]{-1, -1};
  REP(i, n / 3) {
    b[i] = query(i * 3, i * 3 + 1, i * 3 + 2);
    block[b[i]] = i;
  }
  vector<int> ord;
  REP(i, 3) ord.emplace_back(block[0] * 3 + i);
  REP(i, 3) ord.emplace_back(block[1] * 3 + i);
  bool prv = query(ord[0], ord[1], ord[2]);
  int imp = -1, cre = -1;
  FOR(i, 3, ord.size()) {
    bool nxt = query(ord[i - 2], ord[i - 1], ord[i]);
    if (nxt != prv) {
      if (nxt) {
        imp = ord[i - 3];
        cre = ord[i];
      } else {
        imp = ord[i];
        cre = ord[i - 3];
      }
      break;
    }
    prv = nxt;
  }
  vector<int> is_imp(n, -1);
  is_imp[imp] = true;
  is_imp[cre] = false;
  for (int i : ord) {
    if (i != imp && i != cre) is_imp[i] = !query(imp, cre, i);
  }
  REP(i, n / 3) {
    if (is_imp[i * 3] != -1) continue;
    if (b[i]) {
      bool tmp = query(imp, i * 3, i * 3 + 1);
      if (tmp) {
        is_imp[i * 3] = is_imp[i * 3 + 1] = false;
        is_imp[i * 3 + 2] = !query(imp, cre, i * 3 + 2);
      } else {
        is_imp[i * 3 + 2] = false;
        if (query(imp, cre, i * 3)) {
          is_imp[i * 3] = false;
          is_imp[i * 3 + 1] = true;
        } else {
          is_imp[i * 3] = true;
          is_imp[i * 3 + 1] = false;
        }
      }
    } else {
      bool tmp = query(cre, i * 3, i * 3 + 1);
      if (tmp) {
        is_imp[i * 3 + 2] = true;
        if (query(imp, cre, i * 3)) {
          is_imp[i * 3] = false;
          is_imp[i * 3 + 1] = true;
        } else {
          is_imp[i * 3] = true;
          is_imp[i * 3 + 1] = false;
        }
      } else {
        is_imp[i * 3] = is_imp[i * 3 + 1] = true;
        is_imp[i * 3 + 2] = !query(imp, cre, i * 3 + 2);
      }
    }
  }
  vector<int> imps;
  REP(i, n) {
    if (is_imp[i]) imps.emplace_back(i);
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