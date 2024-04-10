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

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> x(n), p(n); REP(i, n) cin >> x[i] >> p[i];
  vector<ll> points;
  points.reserve(n * 3);
  REP(i, n) {
    points.emplace_back(x[i] - p[i]);
    points.emplace_back(x[i]);
    points.emplace_back(x[i] + p[i]);
  }
  sort(ALL(points));
  points.erase(unique(ALL(points)), points.end());
  const int l = points.size();
  vector<int> diff(l, 0);
  REP(i, n) {
    ++diff[lower_bound(ALL(points), x[i] - p[i]) - points.begin()];
    diff[lower_bound(ALL(points), x[i]) - points.begin()] -= 2;
    ++diff[lower_bound(ALL(points), x[i] + p[i]) - points.begin()];
  }
  vector<ll> height(l, 0);
  ll slope = 0;
  REP(i, l - 1) {
    slope += diff[i];
    height[i + 1] = height[i] + slope * (points[i + 1] - points[i]);
  }
  // REP(i, l) cout << height[i] << " \n"[i + 1 == l];
  slope += diff[l - 1];
  assert(slope == 0);
  vector<int> ans(n, 0);
  REP(type, 3) {
    if (type == 0) {
      SparseTable<ll> st1(height, [](const ll a, const ll b) -> ll { return max(a, b); });
      REP(i, n) {
        const int le = lower_bound(ALL(points), x[i] - p[i]) - points.begin();
        const int mi = lower_bound(ALL(points), x[i]) - points.begin();
        const int ri = lower_bound(ALL(points), x[i] + p[i]) - points.begin();
        ll maxi = 0;
        if (le > 0) chmax(maxi, st1.query(0, le));
        if (ri + 1 < l) chmax(maxi, st1.query(ri + 1, l));
        if (maxi > m) {
          ans[i] = true;
        }
      }
    } else if (type == 1) {
      vector<ll> height2(l, 0);
      REP(i, l) height2[i] = height[i] - points[i];
      SparseTable<ll> st2(height2, [](const ll a, const ll b) -> ll { return max(a, b); });
      REP(i, n) {
        const int le = lower_bound(ALL(points), x[i] - p[i]) - points.begin();
        const int mi = lower_bound(ALL(points), x[i]) - points.begin();
        const int ri = lower_bound(ALL(points), x[i] + p[i]) - points.begin();
        if (
            st2.query(le, mi + 1) > m - (x[i] - p[i])) {
          ans[i] = true;
        }
      }
    } else if (type == 2) {
      vector<ll> height3(l, 0);
      REP(i, l) height3[i] = height[i] + points[i];
      SparseTable<ll> st3(height3, [](const ll a, const ll b) -> ll { return max(a, b); });
      REP(i, n) {
        const int le = lower_bound(ALL(points), x[i] - p[i]) - points.begin();
        const int mi = lower_bound(ALL(points), x[i]) - points.begin();
        const int ri = lower_bound(ALL(points), x[i] + p[i]) - points.begin();
        if (st3.query(mi, ri + 1) > m + (x[i] + p[i])) {
          ans[i] = true;
        }
      }
    }
  }
  REP(i, n) cout << (ans[i] ^ 1);
  cout << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}