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
  int n, m, q; cin >> n >> m >> q;
  vector<string> s(n); REP(i, n) cin >> s[i];
  int icon = 0;
  FenwickTree2D<int> bit(n, m);
  REP(i, n) REP(j, m) {
    if (s[i][j] == '*') {
      ++icon;
      bit.add(i, j, 1);
    }
  }
  while (q--) {
    int y, x; cin >> y >> x; --y; --x;
    if (s[y][x] == '*') {
      --icon;
      bit.add(y, x, -1);
      s[y][x] = '.';
    } else {
      ++icon;
      bit.add(y, x, 1);
      s[y][x] = '*';
    }
    int ans = icon;
    if (icon >= n) ans -= bit.sum(n - 1, icon / n - 1);
    if (icon % n > 0) ans -= bit.sum(0, icon / n, icon % n - 1, icon / n);
    cout << ans << '\n';
  }
  return 0;
}