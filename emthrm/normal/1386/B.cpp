#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(5);
  }
} iosetup;

template <typename T = ll>
struct Rational {
  T num, den;
  Rational(): num(0), den(1) {}
  Rational(T num_, T den_ = 1) : num(num_), den(den_) { assert(den != 0); reduce(); }
  template <typename Real = long double> Real to_real() const { return (Real)num / den; }
  Rational &operator+=(const Rational &x) {
    T g = __gcd(den, x.den);
    num = num * (x.den / g) + x.num * (den / g); den *= x.den / g;
    reduce();
    return *this;
  }
  Rational &operator-=(const Rational &x) { return *this += -x; }
  Rational &operator*=(const Rational &x) {
    T g1 = __gcd(num, x.den), g2 = __gcd(den, x.num);
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
  friend ostream &operator<<(ostream &os, const Rational &x) {
    if (x.den == 1) return os << x.num;
    return os << x.num << '/' << x.den;
  }
private:
  void reduce() { T g = __gcd(num, den); num /= g; den /= g; if (den < 0) { num = -num; den = -den; } }
};
template <typename T> Rational<T> abs(const Rational<T> &x) {Rational<T> res = x; if (res.num < 0) res.num = -res.num; return res; }
template <typename T> Rational<T> max(const Rational<T> &a, const Rational<T> &b) { return a < b ? b : a; }
template <typename T> Rational<T> min(const Rational<T> &a, const Rational<T> &b) { return a < b ? a : b; }
using rational = Rational<>;

int main() {
  int sf, pf, gf; cin >> sf >> pf >> gf;
  rational xf = rational(sf, sf + pf + gf), yf = rational(pf, sf + pf + gf);
  vector<ll> x, y;
  map<pair<ll, ll>, int> mp;
  ll pat = 0;
  multiset<double> ang, diff;
  int n; cin >> n;
  while (n--) {
    char c; cin >> c;
    if (c == 'A') {
      int s, p, g; cin >> s >> p >> g;
      rational dx = rational(s, s + p + g) - xf, dy = rational(p, s + p + g) - yf;
      ll l = lcm(dx.den, dy.den), lx = dx.num * (l / dx.den), ly = dy.num * (l / dy.den);
      if (lx == 0 && ly == 0) {
        x.emplace_back(0);
        y.emplace_back(0);
      } else {
        ll g = gcd(lx, ly);
        lx /= g; ly /= g;
        x.emplace_back(lx);
        y.emplace_back(ly);
        if (mp.count({-lx, -ly}) == 1) pat += mp[{-lx, -ly}];
        double theta = atan2(ly, lx);
        if (!ang.empty()) {
          auto it = ang.lower_bound(theta);
          if (ang.size() >= 2) {
            auto it2 = it;
            if (it2 == ang.end()) it2 = ang.begin();
            if (it2 == ang.begin()) {
              double d = *it2 - *ang.rbegin() + M_PI * 2;
              diff.erase(diff.lower_bound(d));
            } else {
              double d = *it2 - *prev(it);
              diff.erase(diff.lower_bound(d));
            }
          }
          if (it == ang.end()) {
            diff.emplace(*ang.begin() - theta + M_PI * 2);
          } else {
            diff.emplace(*it - theta);
          }
          if (it == ang.begin()) {
            diff.emplace(theta - *ang.rbegin() + M_PI * 2);
          } else {
            diff.emplace(theta - *prev(it));
          }
        }
        ang.emplace(theta);
      }
      ++mp[{lx, ly}];
    } else if (c == 'R') {
      int r; cin >> r; --r;
      --mp[{x[r], y[r]}];
      if (mp[{x[r], y[r]}] == 0) mp.erase({x[r], y[r]});
      if (x[r] != 0 || y[r] != 0) {
        if (mp.count({-x[r], -y[r]}) == 1) pat -= mp[{-x[r], -y[r]}];
        double theta = atan2(y[r], x[r]);
        auto it = ang.lower_bound(theta);
        if (ang.size() >= 2) {
          if (next(it) == ang.end()) {
            double d = *ang.begin() - *it + M_PI * 2;
            diff.erase(diff.lower_bound(d));
          } else {
            double d = *next(it) - *it;
            diff.erase(diff.lower_bound(d));
          }
          if (it == ang.begin()) {
            double d = *it - *ang.rbegin() + M_PI * 2;
            diff.erase(diff.lower_bound(d));
          } else {
            double d = *it - *prev(it);
            diff.erase(diff.lower_bound(d));
          }
        }
        if (ang.size() >= 3) {
          if (next(it) == ang.end()) {
            diff.emplace(*ang.begin() - *prev(it) + M_PI * 2);
          } else if (it == ang.begin()) {
            diff.emplace(*next(it) - *ang.rbegin() + M_PI * 2);
          } else {
            diff.emplace(*next(it) - *prev(it));
          }
        }
        ang.erase(it);
      }
    }
    if (mp.count({0, 0}) == 1) {
      cout << 1 << '\n';
    } else if (pat > 0) {
      cout << 2 << '\n';
    } else if (!diff.empty() && *diff.rbegin() < M_PI) {
      cout << 3 << '\n';
    } else {
      cout << 0 << '\n';
    }
    // for (auto [k, v] : mp) cout << "{(" << k.first << ',' << k.second << "), " << v << "} ";
    // cout << "\npat: " << pat << '\n';
    // for (double e : ang) cout << e * 180 / M_PI << ' ';
    // cout << '\n';
    // for (double e : diff) cout << e * 180 / M_PI << ' ';
    // cout << '\n';
  }
  return 0;
}