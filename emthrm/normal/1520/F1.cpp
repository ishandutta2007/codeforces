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

int query(int l, int r) {
  cout << "? " << l + 1 << ' ' << r + 1 << endl;
  int sum; cin >> sum;
  assert(sum != -1);
  return sum;
}

int main() {
  int n, t, k; cin >> n >> t >> k;
  assert(t == 1);
  int lb = k - 2, ub = n - 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    (mid + 1 - query(0, mid) < k ? lb : ub) = mid;
  }
  cout << "! " << ub + 1 << endl;
  return 0;
}