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

int main() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> a(n), b(m);
  REP(i, n) cin >> a[i];
  sort(ALL(a));
  REP(i, m) cin >> b[i];
  sort(ALL(b));
  vector<int> x(n + m);
  iota(ALL(x), 0);
  sort(ALL(x), [&](int l, int r) -> bool {
    int u = (l < n ? a[l] : b[l - n]), v = (r < n ? a[r] : b[r - n]);
    return u < v;
  });
  vector<ll> price(n + m);
  REP(i, n + m) price[i] = (x[i] < n ? a[x[i]] : b[x[i] - n]);
  DisjointSparseTable dst(price, [](ll l, ll r) -> ll { return l + r; });
  vector<int> d(n + m - 1);
  REP(i, n + m - 1) d[i] = price[i + 1] - price[i];
  vector<int> ord(n + m - 1);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](int l, int r) -> bool { return d[l] < d[r]; });
  vector<int> k(q); REP(i, q) cin >> k[i];
  vector<int> query(q);
  iota(ALL(query), 0);
  sort(ALL(query), [&](int l, int r) -> bool { return k[l] < k[r]; });
  vector<int> r(n + m), token(n + m, 0);
  iota(ALL(r), 0);
  ll prices = 0;
  auto root = [&](auto&& root, int x) -> int {
    return r[x] == x ? x : (r[x] = root(root, r[x]));
  };
  auto unite = [&](int x, int y) -> void {
    x = root(root, x);
    y = root(root, y);
    if (x > y) swap(x, y);
    r[x] = y;
    if (token[x] > 0) prices -= dst.query(x - token[x] + 1, x + 1);
    if (token[y] > 0) prices -= dst.query(y - token[y] + 1, y + 1);
    token[y] += token[x];
    token[x] = 0;
    if (token[y] > 0) prices += dst.query(y - token[y] + 1, y + 1);
  };
  REP(i, n + m) {
    if (x[i] < n) {
      prices += price[i];
      token[i] = 1;
    }
  }
  vector<ll> ans(q, 0);
  int idx = 0;
  for (int i : query) {
    for (; idx < n + m - 1 && d[ord[idx]] <= k[i]; ++idx) {
      unite(ord[idx], ord[idx] + 1);
    }
    ans[i] = prices;
  }
  REP(i, q) cout << ans[i] << '\n';
  return 0;
}