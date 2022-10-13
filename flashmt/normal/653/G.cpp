#include <bits/stdc++.h>
using namespace std;
const int A = 300300;

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

using num = modnum<int(1e9) + 7>;

vector<num> fact, invFact;

void initFact(int n)
{
  fact.resize(n + 2);
  invFact.resize(n + 2);
  fact[0] = 1;
  for (int i = 1; i <= n + 1; i++)
    fact[i] = fact[i - 1] * i;
  invFact[n + 1] = inv(fact[n + 1]);
  for (int i = n; i >= 0; i--)
    invFact[i] = invFact[i + 1] * (i + 1);
}

num c(int n, int k)
{
  return 0 <= k && k <= n ? fact[n] * invFact[k] * invFact[n - k] : 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  initFact(A);
  vector<int> sieve(A);
  for (int i = 2; i * i < A; i++)
    if (!sieve[i])
      for (int j = i * i; j < A; j += i)
        sieve[j] = i;

  int n;
  cin >> n;
  vector<vector<int>> a(A);
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    while (sieve[x])
    {
      int p = sieve[x], deg = 0;
      while (x % p == 0)
      {
        x /= p;
        deg++;
      }
      a[p].push_back(deg);
    }
    if (x > 1)
      a[x].push_back(1);
  }

  vector<num> sumC(n);
  sumC[0] = 1;
  for (int i = 1; i < n; i++)
    sumC[i] = sumC[i - 1] + c(n - 1, i);

  num ans = 0;
  for (auto curA : a)
    if (!empty(curA))
    {
      sort(rbegin(curA), rend(curA));
      for (int j = 0; j < size(curA); j++)
        ans += (sumC[n - 1 - j] - sumC[j]) * curA[j];
    }

  cout << ans << endl;
}