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

vector<int> a;

int query(int t, int i, int j, int x) {
  cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
  int res; cin >> res;
  // int res = (t == 1 ? max(min(x, a[i]), min(x + 1, a[j])) : min(max(x, a[i]), max(x + 1, a[j])));
  assert(res != -1);
  return res;
}

void solve() {
  int n; cin >> n;
  int lb = 0, ub = n;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (query(1, 1, 0, mid) < mid + 1 ? ub : lb) = mid;
  }
  vector<int> p(n, 0);
  p[0] = lb + 1;
  int low = lb, high = n - (lb + 1);
  FOR(i, 1, n) {
    for (bool expect_low = low > high; ; expect_low = !expect_low) {
      if (expect_low) {
        p[i] = query(2, i, 0, 1);
        if (p[i] < p[0]) {
          --low;
          break;
        }
      } else {
        p[i] = query(1, 0, i, n - 1);
        if (p[i] > p[0]) {
          --high;
          break;
        }
      }
    }
  }
  cout << "! ";
  REP(i, n) {
    cout << p[i];
    if (i + 1 == n) {
      cout << endl;
    } else {
      cout << ' ';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}