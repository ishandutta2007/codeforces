#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#endif
using namespace std;

int MOD;

struct modnum {

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

template<int M> string to_string(modnum x) {
  return to_string(int(x));
}

using num = modnum;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q >> MOD;
  vector<num> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    a[i] = num(x) - a[i];
  }

  vector<num> d(n);
  int numZero = 0;
  for (int i = 0; i < n; i++)
  {
    d[i] = a[i];
    if (i)
      d[i] -= a[i - 1];
    if (i > 1)
      d[i] -= a[i - 2];
    if (!int(d[i]))
      numZero++;
  }

  vector<num> fib(n);
  fib[0] = fib[1] = 1;
  for (int i = 2; i < n; i++)
    fib[i] = fib[i - 1] + fib[i - 2];

  auto update = [&](int i, num v)
  {
    if (!int(d[i]))
      numZero--;
    d[i] += v;
    if (!int(d[i]))
      numZero++;
  };

  while (q--)
  {
    char c;
    int l, r;
    cin >> c >> l >> r;
    l--; r--;
    num sign = c == 'A' ? -1 : 1;
    update(l, sign);
    if (r + 1 < n)
    {
      update(r + 1, fib[r - l] * sign * num(-1));
      if (l < r)
        update(r + 1, fib[r - l - 1] * sign * num(-1));
    }
    if (r + 2 < n)
      update(r + 2, fib[r - l] * sign * num(-1));
    cout << (numZero == n ? "YES" : "NO") << '\n';
  }
}