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

using num = modnum<998244353>;

const int N = 200020;

vector<pair<int, int>> d[N];
vector<tuple<int, int, int>> a[N];
num val[N];
int sumP[N], minSumP[N];

void update(int x, int sign)
{
  for (auto [prime, deg] : d[x])
  {
    sumP[prime] += deg * sign;
    minSumP[prime] = min(minSumP[prime], sumP[prime]);
  }
}

void dfs(int x, int par = -1)
{
  for (auto [y, u, v] : a[x])
    if (y != par)
    {
      update(u, 1);
      update(v, -1);

      val[y] = val[x] * u / v;
      dfs(y, x);

      update(u, -1);
      update(v, 1);
    }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i < N; i++)
  {
    int x = i;
    for (int j = 2; j * j <= x; j++)
      if (x % j == 0)
      {
        int p = 0;
        while (x % j == 0)
        {
          x /= j;
          p++;
        }
        d[i].push_back({j, p});
      }

    if (x > 1)
      d[i].push_back({x, 1});
  }

  int test;
  cin >> test;
  while (test--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      a[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
      int x, y, u, v;
      cin >> x >> y >> u >> v;
      int g = gcd(u, v);
      u /= g;
      v /= g;
      a[--x].push_back({--y, v, u});
      a[y].push_back({x, u, v});
    }

    val[0] = 1;
    for (int i = 2; i <= n; i++)
      sumP[i] = minSumP[i] = 0;

    dfs(0);
    num toMul = 1;
    for (int i = 2; i <= n; i++)
      if (minSumP[i] < 0)
        toMul *= pow(num(i), -minSumP[i]);

    num sumVal = 0;
    for (int i = 0; i < n; i++)
      sumVal += val[i];

    cout << sumVal * toMul << '\n';
  }
}