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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int query(const vector<int>& a) {
  cout << '?';
  for (int ai : a) cout << ' ' << ai;
  cout << endl;
  int k; cin >> k; --k;
  return k;
}

int main() {
  int n; cin >> n;
  vector<int> a(n, 1), to(n, -1);
  int root = -1;
  REP(i, n) {
    ++a[i];
    int k = query(a);
    --a[i];
    if (k == -1) {
      root = i;
    } else if (k != i) {
      to[k] = i;
    }
  }
  fill(ALL(a), 2);
  REP(i, n) {
    --a[i];
    int k = query(a);
    ++a[i];
    if (k != -1 && k != i) {
      assert(to[i] == -1);
      to[i] = k;
    }
  }
  vector<int> ans(n, -1);
  for (int i = n; i >= 1; --i) {
    ans[root] = i;
    root = to[root];
  }
  cout << '!';
  REP(i, n) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}