#include <bits/stdc++.h>
using namespace std;
const int N = 100100;

template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  using ll = long long;

  int v;

  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
  }

public:

  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }

  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }

  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }

  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

template <typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<998244353>;

int n, l[55], r[55];
num fact[N], invFact[N];

num c(int n, int k)
{
  return fact[n] * invFact[k] * invFact[n - k];
}

num calc(int g, int m)
{
  int a[55];
  for (int i = 0; i < n; i++)
  {
    int from = (l[i] + g - 1) / g, to = r[i] / g;
    if (from > to)
      return 0;
    m -= from;
    a[i] = to - from + 1;
  }

  if (m < 0)
    return 0;

  vector<vector<num>> f(m + 1, vector<num>(2));
  f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = m; j >= a[i]; j--)
      for (int k = 0; k < 2; k++)
        f[j][k] += f[j - a[i]][k ^ 1];

  num res = 0;
  for (int i = 0; i <= m; i++)
    res += (f[i][0] - f[i][1]) * c(m - i + n, n);
  return res;
}

int main()
{
  for (int i = 0; i < N; i++)
  {
    fact[i] = i ? fact[i - 1] * i : 1;
    invFact[i] = inv(fact[i]);
  }

  int m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> l[i] >> r[i];

  vector<int> sieve(N), mobius(N, 1);
  for (int i = 2; i < N; i++)
    if (!sieve[i])
      for (int j = i; j < N; j += i)
      {
        sieve[j] = i;
        mobius[j] *= -1;
      }
  for (int i = 2; i * i < N; i++)
    if (sieve[i] == i)
      for (int j = i * i; j < N; j += i * i)
        mobius[j] = 0;

  num ans = 0;
  for (int i = 1; i < N; i++)
    if (mobius[i])
      ans += calc(i, m / i) * mobius[i];

  cout << ans << endl;
}