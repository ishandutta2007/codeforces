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

int a[100000];

int query(int i) {
  if (a[i] != -1) return a[i];
  cout << "? " << i + 1 << endl;
  int ai; cin >> ai;
  return ai - 1;
}

int main() {
  memset(a, -1, sizeof(a));
  int n; cin >> n;
  if (n == 1) {
    cout << "! " << 1 << endl;
    return 0;
  }
  int l = 0, r = n;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    (query(m - 1) < query(m) ? r : l) = m;
  }
  cout << "! " << l + 1 << endl;
  return 0;
}