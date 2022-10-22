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

template <typename T = long long>
struct Rational {
  T num, den;
  Rational(): num(0), den(1) {}
  Rational(T num, T den = 1) : num(num), den(den) { assert(den != 0); reduce(); }
  template <typename Real = long double> Real to_real() const { return static_cast<Real>(num) / den; }
  Rational &operator+=(const Rational &x) {
    T g = std::__gcd(den, x.den);
    num = num * (x.den / g) + x.num * (den / g); den *= x.den / g;
    reduce();
    return *this;
  }
  Rational &operator-=(const Rational &x) { return *this += -x; }
  Rational &operator*=(const Rational &x) {
    T g1 = std::__gcd(num, x.den), g2 = std::__gcd(den, x.num);
    num = (num / g1) * (x.num / g2); den = (den / g2) * (x.den / g1);
    reduce();
    return *this;
  }
  Rational &operator/=(const Rational &x) { return *this *= Rational(x.den, x.num); }
  bool operator==(const Rational &x) const { return num == x.num && den == x.den; }
  bool operator!=(const Rational &x) const { return !(*this == x); }
  bool operator<(const Rational &x) const { return (x - *this).num > 0; }
  bool operator<=(const Rational &x) const { return !(x < *this); }
  bool operator>(const Rational &x) const { return x < *this; }
  bool operator>=(const Rational &x) const { return !(*this < x); }
  Rational &operator++() { if ((num += den) == 0) den = 1; return *this; }
  Rational operator++(int) { Rational res = *this; ++*this; return res; }
  Rational &operator--() { if ((num -= den) == 0) den = 1; return *this; }
  Rational operator--(int) { Rational res = *this; --*this; return res; }
  Rational operator+() const { return *this; }
  Rational operator-() const { return Rational(-num, den); }
  Rational operator+(const Rational &x) const { return Rational(*this) += x; }
  Rational operator-(const Rational &x) const { return Rational(*this) -= x; }
  Rational operator*(const Rational &x) const { return Rational(*this) *= x; }
  Rational operator/(const Rational &x) const { return Rational(*this) /= x; }
  friend std::ostream &operator<<(std::ostream &os, const Rational &x) {
    if (x.den == 1) return os << x.num;
    return os << x.num << '/' << x.den;
  }
private:
  void reduce() { T g = std::__gcd(num, den); num /= g; den /= g; if (den < 0) { num = -num; den = -den; } }
};
namespace std {
template <typename T> Rational<T> abs(const Rational<T> &x) {Rational<T> res = x; if (res.num < 0) res.num = -res.num; return res; }
template <typename T> Rational<T> max(const Rational<T> &a, const Rational<T> &b) { return a < b ? b : a; }
template <typename T> Rational<T> min(const Rational<T> &a, const Rational<T> &b) { return a < b ? a : b; }
template <typename T> struct numeric_limits<Rational<T>> {
  static constexpr Rational<T> max() { return std::numeric_limits<T>::max(); }
  static constexpr Rational<T> lowest() { return std::numeric_limits<T>::lowest(); }
};
}  // std

using rational = Rational<>;
constexpr int X = 21;

rational stor(string &s) {
  assert(s[0] == '0' && s[1] == '.');
  s = s.substr(2);
  int den = 1;
  REP(_, s.length()) den *= 10;
  return rational(stoi(s), den);
}

void solve() {
  string cs, ms, ps, vs; cin >> cs >> ms >> ps >> vs;
  double cd = stod(cs), md = stod(cs), pd = stod(ps), vd = stod(vs);
  rational c = stor(cs), m = stor(ms), p = stor(ps), v = stor(vs);
  double ans = 0, dp[X + 1][X + 1]{};
  dp[0][0] = 1;
  for (int k = 0; k <= X * 2; ++k) for (int i = 0; i <= k && i <= X; ++i) {
    int j = k - i;
    if (j > X || dp[i][j] < EPS) continue;
    rational cash = c - v * i + v * j / 2, marker = m - v * j + v * i / 2;
    ans += (i + j + 1) * dp[i][j] * (1 - cash.to_real() - marker.to_real());
    if (cash > v) {
      dp[i + 1][j] += dp[i][j] * cash.to_real();
    } else {
      int add = 1;
      rational nm = marker + cash / 2;
      double prop = dp[i][j] * cash.to_real();
      while (nm > 0) {
        ans += (i + j + 1 + add) * prop * (1 - nm.to_real());
        ++add;
        prop *= nm.to_real();
        nm -= v;
      }
      ans += (i + j + 1 + add) * prop;
    }
    if (marker > v) {
      dp[i][j + 1] += dp[i][j] * marker.to_real();
    } else {
      int add = 1;
      rational nc = cash + marker / 2;
      double prop = dp[i][j] * marker.to_real();
      while (nc > 0) {
        ans += (i + j + 1 + add) * prop * (1 - nc.to_real());
        ++add;
        prop *= nc.to_real();
        nc -= v;
      }
      ans += (i + j + 1 + add) * prop;
    }
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}