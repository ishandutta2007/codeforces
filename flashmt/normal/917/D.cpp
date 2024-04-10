#include <bits/stdc++.h>
#ifdef LOCAL
#include "Debug.h"
#else
#define debug(...) 42
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

int n, sz[111];
vector<int> a[111];
// f(x, i, j) = at node x, has i components and component of x has size j
vector<vector<num>> f[111];

void dfs(int x, int par = -1)
{
  sz[x] = 1;
  f[x] = vector<vector<num>>(sz[x] + 1, vector<num>(sz[x] + 1));
  f[x][1][1] = 1;
  for (int y : a[x])
    if (y != par)
    {
      dfs(y, x);
      vector<vector<num>> newF(sz[x] + sz[y] + 1, vector<num>(sz[x] + sz[y] + 1));
      for (int i = 1; i <= sz[x]; i++)
        for (int ii = 1; ii <= sz[x]; ii++)
          for (int j = 1; j <= sz[y]; j++)
            for (int jj = 1; jj <= sz[y]; jj++)
            {
              // pick edge
              newF[i + j - 1][ii + jj] += f[x][i][ii] * f[y][j][jj];
              // don't pick edge
              newF[i + j][ii] += f[x][i][ii] * f[y][j][jj] * jj;
            }

      sz[x] += sz[y];
      swap(f[x], newF);
    }
}

int main()
{
  cin >> n;
  initFact(n);
  for (int i = 0; i < n - 1; i++)
  {
    int x, y;
    cin >> x >> y;
    a[--x].push_back(--y);
    a[y].push_back(x);
  }
  dfs(0);
  vector<num> ans(n);
  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 1; j <= n; j++)
      ans[i] += f[0][n - i][j] * j;
    ans[i] *= pow(num(n), n - i);
    ans[i] /= pow(num(n), 2);
    for (int ii = i + 1; ii < n; ii++)
      ans[i] -= ans[ii] * c(ii, i);
  }
  for (auto x : ans)
    cout << x << ' ';
}