#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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

const int mod = 998244353;

int main() {


  int N;
  cin >> N;
  Combination< mod > uku1(N + 5);
  int64 add1 = 0;
  for(int i = 0; i < N; i++) {
    int64 L = N - i;
    int64 R = i;
    (add1 += uku1.fact(L) * uku1.fact(R) % mod * uku1.C(N, L) % mod) %= mod;
  }
  int64 sub = 0;
  for(int i = 1; i < N; i++) {
    (sub += uku1.rfact[i]) %= mod;
  }
  (sub *= uku1.fact(N)) %= mod;
  cout << (add1 + mod - sub) % mod << endl;
}