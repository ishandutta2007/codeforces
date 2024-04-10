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

template <typename Semigroup, typename Fn>
struct DisjointSparseTable {
  DisjointSparseTable(const std::vector<Semigroup> &a, Fn fn) : fn(fn) {
    int n = a.size(), table_h = 1;
    while ((1 << table_h) < n) ++table_h;
    lg.assign(1 << table_h, 0);
    for (int i = 2; i < (1 << table_h); ++i) lg[i] = lg[i >> 1] + 1;
    dat.assign(table_h, std::vector<Semigroup>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) {
      int shift = 1 << i;
      for (int left = 0; left < n; left += shift << 1) {
        int mid = std::min(left + shift, n);
        dat[i][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= left; --j) dat[i][j] = fn(a[j], dat[i][j + 1]);
        if (n <= mid) break;
        int right = std::min(mid + shift, n);
        dat[i][mid] = a[mid];
        for (int j = mid + 1; j < right; ++j) dat[i][j] = fn(dat[i][j - 1], a[j]);
      }
    }
  }

  Semigroup query(int left, int right) const {
    assert(left < right);
    if (left == --right) return dat[0][left];
    int h = lg[left ^ right];
    return fn(dat[h][left], dat[h][right]);
  }

private:
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Semigroup>> dat;
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> x(n);
  REP(i, n) {
    char op; cin >> op;
    x[i] = (i > 0 ? x[i - 1] : 0) + (op == '-' ? -1 : 1);
  }
  DisjointSparseTable mn(x, [](int a, int b) { return min(a, b); });
  DisjointSparseTable mx(x, [](int a, int b) { return max(a, b); });
  while (m--) {
    int l, r; cin >> l >> r; --l; --r;
    int lb = 0, ub = 0, cur = 0;
    if (l > 0) {
      chmin(lb, cur + mn.query(0, l));
      chmax(ub, cur + mx.query(0, l));
      cur = x[l - 1];
    }
    if (r + 1 < n) {
      chmin(lb, cur + mn.query(r + 1, n) - x[r]);
      chmax(ub, cur + mx.query(r + 1, n) - x[r]);
    }
    cout << ub - lb + 1 << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}