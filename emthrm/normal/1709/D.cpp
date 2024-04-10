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

template <typename Band>
struct SparseTable {
  using Fn = std::function<Band(Band, Band)>;

  SparseTable() = default;

  explicit SparseTable(const std::vector<Band>& a, const Fn fn) { init(a, fn); }

  void init(const std::vector<Band>& a, const Fn fn_) {
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    while ((1 << table_h) <= n) ++table_h;
    data.assign(table_h, std::vector<Band>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        data[i][j] = fn(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  Band query(const int left, const int right) const {
    assert(left < right);
    const int h = lg[right - left];
    return fn(data[h][left], data[h][right - (1 << h)]);
  }

 private:
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Band>> data;
};

int main() {
  int n, m; cin >> n >> m;
  vector<int> a(m); REP(i, m) cin >> a[i], --a[i];
  SparseTable<int> sparse_table(a, [](const int l, const int r) -> int { return max(l, r); });
  int q; cin >> q;
  while (q--) {
    int ys, xs, yf, xf, k; cin >> ys >> xs >> yf >> xf >> k; --ys; --xs; --yf; --xf;
    if (xs > xf) {
      swap(ys, yf);
      swap(xs, xf);
    }
    if (ys % k != yf % k || xs % k != xf % k) {
      cout << "NO\n";
      continue;
    }
    if (xs == xf) {
      cout << "YES\n";
      continue;
    }
    cout << (ys + (n - 1 - ys) / k * k > sparse_table.query(xs, xf + 1) ? "YES\n" : "NO\n");
  }
  return 0;
}