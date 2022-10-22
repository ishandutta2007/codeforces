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

int main() {
  int n, k; cin >> n >> k;
  const int x = (n + k - 2) / (k - 1);
  vector<int> c(n * k); REP(i, n * k) cin >> c[i], --c[i];
  vector<int> a(n, -1), b(n, -1);
  map<int, int> left;
  int cnt = 0;
  REP(i, n * k) {
    if (left.count(c[i]) == 1) {
      a[c[i]] = left[c[i]];
      b[c[i]] = i;
      left.erase(c[i]);
      ++cnt;
    } else if (a[c[i]] == -1 && left.count(c[i]) == 0) {
      left[c[i]] = i;
    }
    if (cnt == x) {
      left.clear();
      cnt = 0;
    }
  }
  REP(i, n) cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
  return 0;
}