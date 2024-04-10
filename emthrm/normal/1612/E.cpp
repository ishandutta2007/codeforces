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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
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

int main() {
  using rational = Rational<>;
  constexpr int M = 200000, K = 20;
  int n; cin >> n;
  vector<int> k[M]{};
  while (n--) {
    int m, ki; cin >> m >> ki; --m;
    k[m].emplace_back(ki);
  }
  int ans = 0;
  rational ex = 0;
  vector<int> pinned;
  FOR(t, 1, K) {
    int v[M]{};
    REP(i, M) for (int j : k[i]) {
      v[i] += min(j, t);
    }
    int ord[M]{};
    iota(ord, ord + M, 0);
    sort(ord, ord + M, [&](int a, int b) -> bool { return v[a] > v[b]; });
    int sum = 0;
    REP(i, t) sum += v[ord[i]];
    if (chmax(ex, rational(sum, t))) {
      ans = t;
      pinned.clear();
      copy(ord, ord + t, back_inserter(pinned));
    }
  }
  int v[M]{};
  REP(i, M) v[i] = accumulate(ALL(k[i]), 0);
  int ord[M]{};
  iota(ord, ord + M, 0);
  sort(ord, ord + M, [&](int a, int b) -> bool { return v[a] > v[b]; });
  int sum = 0;
  REP(i, K - 1) sum += v[ord[i]];
  FOR(t, K - 1, M) {
    sum += v[ord[t]];
    if (chmax(ex, rational(sum, t + 1))) {
      ans = t + 1;
      pinned.clear();
    }
  }
  if (ans >= K) copy(ord, ord + ans, back_inserter(pinned));
  cout << ans << '\n';
  REP(i, ans) cout << pinned[i] + 1 << " \n"[i + 1 == ans];
  return 0;
}