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

template <int ID>
struct MInt {
  unsigned int val;
  MInt(): val(0) {}
  MInt(long long x) : val(x >= 0 ? x % mod() : x % mod() + mod()) {}
  static int get_mod() { return mod(); }
  static void set_mod(int divisor) { mod() = divisor; }
  static void init(int x = 10000000) { inv(x, true); fact(x); fact_inv(x); }
  static MInt inv(int x, bool init = false) {
    // assert(0 <= x && x < mod() && std::__gcd(x, mod()) == 1);
    static std::vector<MInt> inverse{0, 1};
    int prev = inverse.size();
    if (init && x >= prev) {
      // "x!" and "mod()" must be disjoint.
      inverse.resize(x + 1);
      for (int i = prev; i <= x; ++i) inverse[i] = -inverse[mod() % i] * (mod() / i);
    }
    if (x < inverse.size()) return inverse[x];
    unsigned int a = x, b = mod(); int u = 1, v = 0;
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
  MInt &operator+=(const MInt &x) { if((val += x.val) >= mod()) val -= mod(); return *this; }
  MInt &operator-=(const MInt &x) { if((val += mod() - x.val) >= mod()) val -= mod(); return *this; }
  MInt &operator*=(const MInt &x) { val = static_cast<unsigned long long>(val) * x.val % mod(); return *this; }
  MInt &operator/=(const MInt &x) { return *this *= inv(x.val); }
  bool operator==(const MInt &x) const { return val == x.val; }
  bool operator!=(const MInt &x) const { return val != x.val; }
  bool operator<(const MInt &x) const { return val < x.val; }
  bool operator<=(const MInt &x) const { return val <= x.val; }
  bool operator>(const MInt &x) const { return val > x.val; }
  bool operator>=(const MInt &x) const { return val >= x.val; }
  MInt &operator++() { if (++val == mod()) val = 0; return *this; }
  MInt operator++(int) { MInt res = *this; ++*this; return res; }
  MInt &operator--() { val = (val == 0 ? mod() : val) - 1; return *this; }
  MInt operator--(int) { MInt res = *this; --*this; return res; }
  MInt operator+() const { return *this; }
  MInt operator-() const { return MInt(val ? mod() - val : 0); }
  MInt operator+(const MInt &x) const { return MInt(*this) += x; }
  MInt operator-(const MInt &x) const { return MInt(*this) -= x; }
  MInt operator*(const MInt &x) const { return MInt(*this) *= x; }
  MInt operator/(const MInt &x) const { return MInt(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const MInt &x) { return os << x.val; }
  friend std::istream &operator>>(std::istream &is, MInt &x) { long long val; is >> val; x = MInt(val); return is; }
private:
  static int &mod() { static int divisor = 0; return divisor; }
};
namespace std { template <int ID> MInt<ID> abs(const MInt<ID> &x) { return x; } }

int main() {
  using ModInt = MInt<0>;
  int n, mod; cin >> n >> mod;
  ModInt::set_mod(mod);
  ModInt ans = 0;
  const int m = n * (n - 1) / 2;
  vector<ModInt> s(m * 2 + 1, 0);
  fill(s.begin() + m, s.end(), 1);
  FOR(i, 1, n) {
    vector<ModInt> nx(m * 2 + 1, 0);
    REP(j, m * 2 + 1) {
      if (j > 0) {
        nx[j] += nx[j - 1];
        nx[j] -= s[j - 1] - (j - 1 - i >= 0 ? s[j - 1 - i] : 0);
      }
      nx[j] += s[min(j - 1 + i, m * 2)] - (j - 1 >= 0 ? s[j - 1] : 0);
    }
    FOR(j, 1, m * 2 + 1) nx[j] += nx[j - 1];
    s.swap(nx);

    ModInt pat = 0;
    vector<int> diff(i + 1, 0);
    REP(x, i + 1) REP(y, x) ++diff[x - y];
    REP(x, i + 1) pat += (s[m * 2] - s[m + x]) * diff[x];
    REP(x, n - 1 - i) pat *= n - x;
    ans += pat;
  }
  cout << ans << '\n';
  return 0;
}