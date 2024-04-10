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

template <int M>
struct MInt {
  unsigned int val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % M : x % M + M) {}
  static constexpr int get_mod() { return M; }
  static void set_mod(int divisor) { assert(divisor == M); }
  static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }
  static MInt inv(int x, bool init = false) {
    // assert(0 <= x && x < M && std::__gcd(x, M) == 1);
    static std::vector<MInt> inverse{0, 1};
    int prev = inverse.size();
    if (init && x >= prev) {
      // "x!" and "M" must be disjoint.
      inverse.resize(x + 1);
      for (int i = prev; i <= x; ++i) inverse[i] = -inverse[M % i] * (M / i);
    }
    if (x < inverse.size()) return inverse[x];
    unsigned int a = x, b = M; int u = 1, v = 0;
    while (b) {
      unsigned int q = a / b;
      std::swap(a -= q * b, b);
      std::swap(u -= q * v, v);
    }
    return u;
  }
  static MInt fact(int x) {
    static std::vector<MInt> f{1};
    int prev = f.size();
    if (x >= prev) {
      f.resize(x + 1);
      for (int i = prev; i <= x; ++i) f[i] = f[i - 1] * i;
    }
    return f[x];
  }
  static MInt fact_inv(int x) {
    static std::vector<MInt> finv{1};
    int prev = finv.size();
    if (x >= prev) {
      finv.resize(x + 1);
      finv[x] = inv(fact(x).val);
      for (int i = x; i > prev; --i) finv[i - 1] = finv[i] * i;
    }
    return finv[x];
  }
  static MInt nCk(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    if (n - k > k) k = n - k;
    return fact(n) * fact_inv(k) * fact_inv(n - k);
  }
  static MInt nPk(int n, int k) { return n < 0 || n < k || k < 0 ? 0 : fact(n) * fact_inv(n - k); }
  static MInt nHk(int n, int k) { return n < 0 || k < 0 ? 0 : (k == 0 ? 1 : nCk(n + k - 1, k)); }
  static MInt large_nCk(long long n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    inv(k, true);
    MInt res = 1;
    for (int i = 1; i <= k; ++i) res *= inv(i) * n--;
    return res;
  }
  MInt pow(long long exponent) const {
    MInt tmp = *this, res = 1;
    while (exponent > 0) {
      if (exponent & 1) res *= tmp;
      tmp *= tmp;
      exponent >>= 1;
    }
    return res;
  }
  MInt &operator+=(const MInt &x) { if((val += x.val) >= M) val -= M; return *this; }
  MInt &operator-=(const MInt &x) { if((val += M - x.val) >= M) val -= M; return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % M; return *this; }
  MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == M) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? M : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? M - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
};
namespace std { template <int M> MInt<M> abs(const MInt<M> &x) { return x; } }
using ModInt = MInt<MOD>;

int main() {
  int k, a, h; cin >> k >> a >> h;
  const int middle = (1 << k) / 2;
  vector<int> p(k - 1, 3);
  vector<ModInt> w(k - 1);
  REP(i, k - 1) {
    if (i > 0) p[i] = p[i - 1] + (1 << i);
    w[i] = ModInt(a).pow(p[i]);
  }
  map<pair<ModInt, bool>, vector<int>> dp;
  vector<int> place(middle);
  auto f = [&](auto &&f, int i, vector<int> team, ModInt hash) -> void {
    if (i < 0) {
      assert(team.size() == 1);
      const int id = team.front();
      place[id - 1] = 1;
      dp[{hash + 1LL * a * id, true}] = place;
      place[id - 1] = 2;
      dp[{hash + 1LL * a * a * id, false}] = place;
      return;
    }
    const int game = team.size() / 2;
    REP(b, 1 << game) {
      vector<int> next_team(game);
      ModInt next_hash = hash;
      REP(j, game) {
        const int win = team[j * 2 + (b >> j & 1)], lose = team[j * 2 + ((b >> j & 1) ^ 1)];
        next_team[j] = win;
        place[lose - 1] = p[i];
        next_hash += w[i] * lose;
      }
      f(f, i - 1, next_team, next_hash);
    }
  };
  vector<int> team(middle);
  iota(ALL(team), 1);
  f(f, k - 2, team, 0);
  auto g = [&](auto &&g, int i, vector<int> team, ModInt hash) -> void {
    if (i < 0) {
      assert(team.size() == 1);
      const int id = team.front();
      {
        place[id - middle - 1] = 1;
        ModInt x = -(hash + 1LL * a * id) + h;
        if (dp.count({x, false}) == 1) {
          REP(i, middle) cout << dp[{x, false}][i] << ' ';
          REP(i, middle) cout << place[i] << " \n"[i + 1 == middle];
          exit(0);
        }
      }
      {
        place[id - middle - 1] = 2;
        ModInt x = -(hash + 1LL * a * a * id) + h;
        if (dp.count({x, true}) == 1) {
          REP(i, middle) cout << dp[{x, true}][i] << ' ';
          REP(i, middle) cout << place[i] << " \n"[i + 1 == middle];
          exit(0);
        }
      }
      return;
    }
    const int game = team.size() / 2;
    REP(b, 1 << game) {
      vector<int> next_team(game);
      ModInt next_hash = hash;
      REP(j, game) {
        const int win = team[j * 2 + (b >> j & 1)], lose = team[j * 2 + ((b >> j & 1) ^ 1)];
        next_team[j] = win;
        place[lose - middle - 1] = p[i];
        next_hash += w[i] * lose;
      }
      g(g, i - 1, next_team, next_hash);
    }
  };
  iota(ALL(team), middle + 1);
  g(g, k - 2, team, 0);
  cout << "-1\n";
  return 0;
}