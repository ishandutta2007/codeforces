#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;


int N;
int64 fact[1000001];
int64 factsum[1000001];

struct Combination
{
  int mod;
  vector< int64_t > mfact, rfact;

  Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod)
  {
    mfact[0] = 1;
    for(int i = 1; i < mfact.size(); i++) {
      mfact[i] = mfact[i - 1] * i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for(int i = sz - 1; i >= 0; i--) {
      rfact[i] = rfact[i + 1] * (i + 1) % mod;
    }
  }

  int64_t fact(int k) const
  {
    return (mfact[k]);
  }

  int64_t pow(int64_t x, int64_t n) const
  {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }

  int64_t inv(int64_t x) const
  {
    return (pow(x, mod - 2));
  }

  int64_t P(int n, int r) const
  {
    if(r < 0 || n < r) return (0);
    return (mfact[n] * rfact[n - r] % mod);
  }

  int64_t C(int p, int q) const
  {
    if(q < 0 || p < q) return (0);
    return (mfact[p] * rfact[q] % mod * rfact[p - q] % mod);
  }

  int64_t H(int n, int r) const
  {
    if(n < 0 || r < 0) return (0);
    return (r == 0 ? 1 : C(n + r - 1, r));
  }
};
int main()
{
  scanf("%d", &N);


  Combination comb(10000001, mod);
  map< int, int > mp;
  int maximum = 0;
  for(int i = 0; i < N; i++) {
    int X;
    scanf("%d", &X);
    maximum = max(maximum, X);
    mp[X]++;
  }

  int low_sum = 0;
  int64 ret = 0;

  for(auto &p : mp) {
    if(p.first == maximum) break;

    int64 curr = N;
    (curr *= comb.fact(N - 1)) %= mod;
    (curr *= comb.inv(N - low_sum)) %= mod;
    (curr *= p.first) %= mod;
    (curr *= p.second) %= mod;
    (ret += curr) %= mod;
    low_sum += p.second;
  }
  cout << ret << endl;
}