// Lagrange interpolation

#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

template<int MOD_> struct modnum {
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

template<typename T> T pow(T a, long long b) {
  assert(b >= 0);
  T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template<int M> string to_string(modnum<M> x) {
  return to_string(int(x));
}

using num = modnum<int(1e9 + 7)>;

vector<int> a[3030];
vector<num> f[3030];

void visit(int x, int d)
{
  f[x].assign(d + 1, 1);
  f[x][0] = 0;
  for (int y : a[x])
  {
    visit(y, d);
    for (int i = 1; i <= d; i++)
      f[x][i] *= f[y][i];
  }
  for (int i = 1; i <= d; i++)
    f[x][i] += f[x][i - 1];
}

// given p(a), p(a + d), ..., p(a + n * d), find p(x)
num lagrange(vector<num> p, num x, num a = 0, num d = 1)
{
  int n = size(p) - 1;

  vector<num> prefix(n + 1, 1), suffix(n + 1, 1);
  for (int i = 0; i < n; i++)
    prefix[i + 1] = prefix[i] * (x - (a + d * i));
  for (int i = n; i > 0; i--)
    suffix[i - 1] = suffix[i] * (x - (a + d * i));

  vector<num> fact(n + 1, 1), invFact(n + 1, 1);
  for (int i = 1; i <= n; i++)
    fact[i] = fact[i - 1] * d * i;
  invFact[n] /= fact[n];
  for (int i = n; i; i--)
    invFact[i - 1] = invFact[i] * d * i;

  num res = 0;
  for (int i = 0; i <= n; i++)
  {
    num tmp = p[i] * prefix[i] * suffix[i] * invFact[i] * invFact[n - i];
    if ((n - i) & 1) res -= tmp;
    else res += tmp;
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, D;
  cin >> n >> D;
  for (int i = 1; i < n; i++)
  {
    int p;
    cin >> p;
    a[--p].push_back(i);
  }
  visit(0, min(n, D));
  if (D <= n) cout << f[0][D] << endl;
  else cout << lagrange(f[0], D) << endl;
}