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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

template <typename T>
struct CumulativeSum2D {
  explicit CumulativeSum2D(const int h, const int w)
      : CumulativeSum2D(std::vector<std::vector<T>>(h, std::vector<T>(w, 0))) {}

  template <typename U>
  explicit CumulativeSum2D(const std::vector<std::vector<U>>& a)
      : is_built(false), h(a.size()), w(a.front().size()),
        data(h + 1, std::vector<T>(w + 1, 0)) {
    for (int i = 0; i < h; ++i) {
      std::copy(a[i].begin(), a[i].end(), std::next(data[i + 1].begin()));
    }
  }

  void add(const int y, const int x, const T val) {
    assert(!is_built);
    data[y + 1][x + 1] += val;
  }

  void build() {
    assert(!is_built);
    is_built = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        data[i + 1][j + 1] += data[i + 1][j];
      }
    }
    for (int j = 1; j <= w; ++j) {
      for (int i = 1; i < h; ++i) {
        data[i + 1][j] += data[i][j];
      }
    }
  }

  T query(const int y1, const int x1, const int y2, const int x2) const {
    assert(is_built);
    return y1 > y2 || x1 > x2 ? 0 : data[y2 + 1][x2 + 1] - data[y2 + 1][x1]
                                    - data[y1][x2 + 1] + data[y1][x1];
  }

 private:
  bool is_built;
  const int h, w;
  std::vector<std::vector<T>> data;
};

constexpr int L = 1000;

void solve() {
  int n, q; cin >> n >> q;
  CumulativeSum2D<ll> sum(L + 1, L + 1);
  while (n--) {
    int h, w; cin >> h >> w;
    sum.add(h, w, h * w);
  }
  sum.build();
  while (q--) {
    int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb;
    cout << sum.query(hs + 1, ws + 1, hb - 1, wb - 1) << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}