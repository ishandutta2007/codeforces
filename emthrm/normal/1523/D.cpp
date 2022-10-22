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

// https://ei1333.github.io/luzhiled/snippets/other/random-number-generator.html
struct RandomNumberGenerator {
  mt19937 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  int operator()(int a, int b) { // [a, b)
    uniform_int_distribution< int > dist(a, b - 1);
    return dist(mt);
  }

  int operator()(int b) { // [0, b)
    return (*this)(0, b);
  }
};

template <typename Ring>
std::vector<Ring> fast_zeta_transform(
  std::vector<Ring> a,
  bool is_superset,
  const Ring ID = 0
) {
  auto fn = [](const Ring &a, const Ring &b) -> Ring { return a + b; };
  int n = a.size(), p = 1;
  while ((1 << p) < n) ++p;
  n = 1 << p;
  a.resize(n, ID);
  if (is_superset) {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j] = fn(a[j], a[j | i]);
    }
  } else {
    for (int i = 1; i < n; i <<= 1) for (int j = 0; j < n; ++j) {
      if ((j & i) == 0) a[j | i] = fn(a[j | i], a[j]);
    }
  }
  return a;
}

int main() {
  int n, m, p; cin >> n >> m >> p;
  vector<string> s(n); REP(i, n) cin >> s[i];
  ll ans = 0;
  auto f = [&](int fri) -> void {
    vector<int> currency;
    REP(j, m) {
      if (s[fri][j] == '1') currency.emplace_back(j);
    }
    int x = currency.size();
    assert(x <= p);
    if (x == 0) return;
    vector<int> a(1 << x, 0);
    REP(i, n) {
      int like = 0;
      REP(j, x) {
        if (s[i][currency[j]] == '1') like |= 1 << j;
      }
      ++a[like];
    }
    vector<int> z = fast_zeta_transform(a, true);
    int tmp = 0;
    FOR(i, 1, 1 << x) {
      if (__builtin_popcount(i) > __builtin_popcount(tmp) && z[i] >= (n + 1) / 2) tmp = i;
    }
    if (__builtin_popcount(tmp) > __builtin_popcountll(ans)) {
      ans = 0;
      REP(j, x) {
        if (tmp >> j & 1) ans |= 1LL << currency[j];
      }
    }
  };
  RandomNumberGenerator rng;
  REP(_, 40) f(rng(n));
  REP(j, m) cout << (ans >> j & 1);
  cout << '\n';
  return 0;
}