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

template <typename T>
std::vector<std::vector<T>> rotate(const std::vector<std::vector<T>> &grid,
                                   const int angle, const T space = ' ') {
  const int h = grid.size(), w = grid.front().size();
  std::vector<std::vector<T>> rotated_grid;
  if (angle == 45) {
    rotated_grid.assign(h + w - 1, std::vector<T>(h + w - 1, space));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[i + j][i - j + w - 1] = grid[i][j];
      }
    }
  } else if (angle == 90) {
    rotated_grid.assign(w, std::vector<T>(h));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        rotated_grid[w - 1 - j][i] = grid[i][j];
      }
    }
  } else {
    assert(false);
  }
  return rotated_grid;
}

template <typename Abelian>
struct FenwickTree2D {
  explicit FenwickTree2D(
      const int height_, const int width_, const Abelian ID = 0)
      : height(height_ + 1), width(width_ + 1), ID(ID) {
    data.assign(height, std::vector<Abelian>(width, ID));
  }

  void add(int y, int x, const Abelian val) {
    ++y; ++x;
    for (int i = y; i < height; i += i & -i) {
      for (int j = x; j < width; j += j & -j) {
        data[i][j] += val;
      }
    }
  }

  Abelian sum(int y, int x) const {
    ++y; ++x;
    Abelian res = ID;
    for (int i = y; i > 0; i -= i & -i) {
      for (int j = x; j > 0; j -= j & -j) {
        res += data[i][j];
      }
    }
    return res;
  }

  Abelian sum(const int y1, const int x1, const int y2, const int x2) const {
    return y1 > y2 || x1 > x2 ? ID : sum(y2, x2) - sum(y2, x1 - 1)
                                     - sum(y1 - 1, x2) + sum(y1 - 1, x1 - 1);
  }

  Abelian get(const int y, const int x) const { return sum(y, x, y, x); }

 private:
  const int height, width;
  const Abelian ID;
  std::vector<std::vector<Abelian>> data;
};

int main() {
  int n, k; cin >> n >> k;
  vector v(n, vector(n, 0)); REP(i, n) REP(j, n) cin >> v[i][j];
  v = rotate(v, 45, 0);
  vector<pair<int, int>> p;
  REP(i, n * 2 - 1) REP(j, n * 2 - 1) {
    if (v[i][j] != 0) p.emplace_back(i, j);
  }
  sort(ALL(p), [&](const pair<int, int>& a, const pair<int, int>& b) -> bool {
    const auto [ia, ja] = a;
    const auto [ib, jb] = b;
    return v[ia][ja] > v[ib][jb];
  });
  FenwickTree2D<int> bit(n * 2 - 1, n * 2 - 1);
  int w = 0;
  vector ans(n, string(n, 'G'));
  for (const auto [i, j] : p) {
    if (bit.sum(max(i - k, 0), max(j - k, 0), min(i + k, n * 2 - 2), min(j + k, n * 2 - 2)) == w) {
      ans[(i + j - (n - 1)) / 2][(i - j + (n - 1)) / 2] = 'M';
      bit.add(i, j, 1);
      ++w;
    }
  }
  REP(i, n) cout << ans[i] << '\n';
  return 0;
}