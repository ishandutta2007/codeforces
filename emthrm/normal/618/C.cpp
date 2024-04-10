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

void argument_sort(std::vector<std::pair<int, int>> &ps) {
  using Point = std::pair<int, int>;
  std::vector<Point> orthant[4];
  for (const Point &p : ps) {
    if (p.second >= 0) {
      orthant[p.first >= 0 ? 2 : 3].emplace_back(p);
    } else {
      orthant[p.first >= 0].emplace_back(p);
    }
  }
  ps.clear();
  for (int i = 0; i < 4; ++i) {
    if (i == 2) {
      std::sort(orthant[i].begin(), orthant[i].end(), [](const Point &a, const Point &b) -> bool {
        if (a.first == 0 && a.second == 0) return !(b.first == 0 && b.second == 0);
        if (b.first == 0 && b.second == 0) return false;
        return static_cast<long long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;
      });
    } else {
      std::sort(orthant[i].begin(), orthant[i].end(), [](const Point &a, const Point &b) -> bool {
        return static_cast<long long>(a.first) * b.second - static_cast<long long>(a.second) * b.first > 0;
      });
    }
    for (const Point &p : orthant[i]) ps.emplace_back(p);
  }
}

int main() {
  int n; cin >> n;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  vector<pair<int, int>> angle;
  FOR(i, 1, n) {
    x[i] -= x[0];
    y[i] -= y[0];
    int g = gcd(x[i], y[i]);
    angle.emplace_back(x[i] / g, y[i] / g);
  }
  sort(ALL(angle));
  angle.erase(unique(ALL(angle)), angle.end());
  assert(angle.size() >= 2);
  argument_sort(angle);
  pair<int, int> a0, a1;
  {
    auto [a0x, a0y] = angle[0];
    auto [a1x, a1y] = angle[1];
    if (1LL * a0x * a1y - 1LL * a0y * a1x > 0) {
      a0 = angle[0];
      a1 = angle[1];
    }
  }
  {
    auto [a0x, a0y] = angle.back();
    auto [a1x, a1y] = angle.front();
    if (1LL * a0x * a1y - 1LL * a0y * a1x > 0) {
      a0 = angle.back();
      a1 = angle.front();
    }
  }
  vector<int> a, b;
  FOR(i, 1, n) {
    int g = gcd(x[i], y[i]), xi = x[i] / g, yi = y[i] / g;
    if (a0.first == xi && a0.second == yi) a.emplace_back(i);
    if (a1.first == xi && a1.second == yi) b.emplace_back(i);
  }
  sort(ALL(a), [&](int l, int r) {
    return 1LL * x[l] * x[l] + 1LL * y[l] * y[l] < 1LL * x[r] * x[r] + 1LL * y[r] * y[r];
  });
  sort(ALL(b), [&](int l, int r) {
    return 1LL * x[l] * x[l] + 1LL * y[l] * y[l] < 1LL * x[r] * x[r] + 1LL * y[r] * y[r];
  });
  cout << 1 << ' ' << a[0] + 1 << ' ' << b[0] + 1 << '\n';
  return 0;
}