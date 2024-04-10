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

template <typename Semigroup, typename Fn>
struct DisjointSparseTable {
  explicit DisjointSparseTable(const std::vector<Semigroup>& a, const Fn fn)
      : fn(fn) {
    const int n = a.size();
    int table_h = 1;
    while ((1 << table_h) < n) ++table_h;
    lg.assign(1 << table_h, 0);
    for (int i = 2; i < (1 << table_h); ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    data.assign(table_h, std::vector<Semigroup>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      const int shift = 1 << i;
      for (int left = 0; left < n; left += shift << 1) {
        const int mid = std::min(left + shift, n);
        data[i][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= left; --j) {
          data[i][j] = fn(a[j], data[i][j + 1]);
        }
        if (n <= mid) break;
        const int right = std::min(mid + shift, n);
        data[i][mid] = a[mid];
        for (int j = mid + 1; j < right; ++j) {
          data[i][j] = fn(data[i][j - 1], a[j]);
        }
      }
    }
  }

  Semigroup query(const int left, int right) const {
    assert(left < right);
    if (left == --right) return data[0][left];
    const int h = lg[left ^ right];
    return fn(data[h][left], data[h][right]);
  }

 private:
  const Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Semigroup>> data;
};

constexpr int B = 30;

void solve() {
  int n; cin >> n;
  vector a(n, vector<int>(1)); REP(i, n) cin >> a[i].front();
  DisjointSparseTable sparse_table(a, [](const vector<int>& a, const vector<int>& b) -> vector<int> {
    vector<int> res;
    merge(ALL(a), ALL(b), back_inserter(res));
    if (res.size() > B + 1) res.resize(B + 1);
    return res;
  });
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    const vector<int> v = sparse_table.query(l, r + 1);
    const int s = v.size();
    int ans = 1 << B;
    REP(i, s) REP(j, i) chmin(ans, v[i] | v[j]);
    cout << ans << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}