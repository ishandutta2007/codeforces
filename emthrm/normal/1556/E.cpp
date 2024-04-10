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

template <typename Band>
struct SparseTable {
  using Fn = std::function<Band(Band, Band)>;

  SparseTable() {}

  SparseTable(const std::vector<Band> &a, Fn fn) { init(a, fn); }

  void init(const std::vector<Band> &a, Fn fn_) {
    is_built = true;
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    while ((1 << table_h) <= n) ++table_h;
    dat.assign(table_h, std::vector<Band>(n));
    for (int j = 0; j < n; ++j) dat[0][j] = a[j];
    for (int i = 1; i < table_h; ++i) for (int j = 0; j + (1 << i) <= n; ++j) {
      dat[i][j] = fn(dat[i - 1][j], dat[i - 1][j + (1 << (i - 1))]);
    }
  }

  Band query(int left, int right) const {
    assert(is_built && left < right);
    int h = lg[right - left];
    return fn(dat[h][left], dat[h][right - (1 << h)]);
  }

private:
  bool is_built = false;
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Band>> dat;
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<ll> c(n);
  REP(i, n) c[i] = b[i] - a[i];
  FOR(i, 1, n) c[i] += c[i - 1];
  SparseTable<ll> mn(c, [](ll a, ll b) -> ll { return min(a, b); });
  SparseTable<ll> mx(c, [](ll a, ll b) -> ll { return max(a, b); });
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    if (c[r] - (l == 0 ? 0 : c[l - 1]) == 0 && mn.query(l, r + 1) - (l == 0 ? 0 : c[l - 1]) >= 0) {
      cout << mx.query(l, r + 1) - (l == 0 ? 0 : c[l - 1]) << '\n';
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}