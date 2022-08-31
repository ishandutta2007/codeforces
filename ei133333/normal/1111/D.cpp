#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
constexpr int mod = 1e9 + 7;

template< int mod >
struct Combination {
  vector< int64_t > mfact, rfact;

  Combination(int sz) : mfact(sz + 1), rfact(sz + 1) {
    mfact[0] = 1;
    for(int i = 1; i < mfact.size(); i++) {
      mfact[i] = mfact[i - 1] * i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for(int i = sz - 1; i >= 0; i--) {
      rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
  }

  int64_t fact(int k) const {
    return (mfact[k]);
  }

  int64_t pow(int64_t x, int64_t n) const {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }

  int64_t inv(int64_t x) const {
    return (pow(x, mod - 2));
  }

  int64_t P(int n, int r) const {
    if(r < 0 || n < r) return (0);
    return (mfact[n] * rfact[n - r] % mod);
  }

  int64_t C(int p, int q) const {
    if(q < 0 || p < q) return (0);
    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
  }

  int64_t H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return (r == 0 ? 1 : C(n + r - 1, r));
  }
};

template< int mod >
struct ModInt
{
  int x;

  ModInt() : x(0) {}

  ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p)
  {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p)
  {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p)
  {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p)
  {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const
  {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    return ModInt(u);
  }

  friend ostream &operator<<(ostream &os, const ModInt< mod > &p)
  {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt< mod > &a)
  {
    long long x;
    is >> x;
    a = ModInt< mod >(x);
    return (is);
  }

};

using modint = ModInt< mod >;

int main() {
  string S;
  int Q;

  cin >> S;
  cin >> Q;

  int N = (int) S.size();


  vector< int > cs(52);
  for(auto &c : S) {
    if(islower(c)) c = c - 'a';
    else c = c - 'A' + 26;
    cs[c]++;
  }

  Combination< mod > tap(N);

  int64 mul = tap.pow(tap.fact(N / 2), 2);
  for(int i : cs) (mul *= tap.inv(tap.fact(i))) %= mod;

  vector< modint > dp(N / 2 + 1);
  dp[0] = 1;
  for(int idx = 0; idx < 52; idx++) {
    vector< modint > dp2(dp);
    if(cs[idx]) {
      for(int j = cs[idx]; j < dp.size(); j++) {
        dp2[j] += dp[j - cs[idx]];
      }
    }
    dp.swap(dp2);
  }

  int64 ans[52][52] = {{}};
  for(int i = 0; i < 52; i++) {
    if(cs[i]) {
      ans[i][i] = dp.back().x;
      vector< modint > dp2(dp);
      for(int j = cs[i]; j < dp2.size(); j++) {
        (dp2[j] -= dp2[j - cs[i]]);
      }
      for(int j = 0; j < i; j++) {
        if(cs[j]) {
          vector< modint > dp3(dp2);
          for(int k = cs[j]; k < dp3.size(); k++) {
            (dp3[k] -= dp3[k - cs[j]]);
          }
          ans[i][j] = ans[j][i] = (dp3.back() * 2).x;
        }
      }
    }
  }

  while(Q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    cout << ans[S[x]][S[y]] * mul % mod << endl;
  }
}