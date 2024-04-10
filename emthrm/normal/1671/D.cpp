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

void solve() {
  int n, x; cin >> n >> x;
  vector<int> a;
  a.reserve(n);
  while (n--) {
    int a_i; cin >> a_i;
    if (a.empty()) {
      a.emplace_back(a_i);
    } else if (a.back() == a_i) {
      //
    } else if (a.size() == 1) {
      a.emplace_back(a_i);
    } else {
      if ((a.end()[-2] < a.back()) == (a.back() < a_i)) a.pop_back();
      a.emplace_back(a_i);
    }
  }
  n = a.size();
  auto f = [&](int v) -> vector<pair<int, int>> {
    vector<pair<int, int>> p(n + 1);
    p.front() = {abs(a.front() - v), 0};
    FOR(i, 1, n) p[i] = {abs(a[i - 1] - v) + abs(a[i] - v) - abs(a[i - 1] - a[i]), i};
    p.back() = {abs(a.back() - v), n};
    sort(ALL(p));
    return p;
  };
  bool has_1 = a.front() == 1, has_x = a.front() == x;
  FOR(i, 1, n) {
    has_1 |= min(a[i - 1], a[i]) == 1;
    has_x |= min(a[i - 1], a[i]) <= x && x <= max(a[i - 1], a[i]);
  }
  ll ans = LINF;
  if (!has_1 && !has_x) {
    chmin(ans, abs(a.front() - 1));
    chmin(ans, abs(a.front() - x));
    FOR(i, 1, n) {
      chmin(ans, abs(a[i - 1] - 1) + abs(a[i] - x) - abs(a[i - 1] - a[i]));
      chmin(ans, abs(a[i - 1] - x) + abs(a[i] - 1) - abs(a[i - 1] - a[i]));
    }
    chmin(ans, abs(a.back() - 1));
    chmin(ans, abs(a.back() - x));
    ans += x - 1;
    const auto p = f(1), q = f(x);
    REP(i, 2) REP(j, 2) {
      if (p[i].second != q[j].second) chmin(ans, p[i].first + q[i].first);
    }
  } else if (!has_1) {
    ans = f(1).front().first;
  } else if (!has_x) {
    ans = f(x).front().first;
  } else {
    ans = 0;
  }
  FOR(i, 1, n) ans += abs(a[i] - a[i - 1]);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}