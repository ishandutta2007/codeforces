#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Combination {
  int mod;
  vector< int64_t > mfact, rfact;

  Combination(int sz, int mod) : mfact(sz + 1), rfact(sz + 1), mod(mod) {
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

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 7;

int main() {
  const int lim = 300000;
  int N;

  cin >> N;
  vector< int64 > uku(lim + 1), x(lim + 1);
  int gcd = 0;
  for(int i = 0; i < N; i++) {
    int v;
    cin >> v;
    gcd = __gcd(v, gcd);
    uku[v]++;
    if(v == 1) {
      cout << 1 << endl;
      return 0;
    }
  }
  if(gcd != 1) {
    cout << -1 << endl;
    return 0;
  }


  for(int i = 1; i <= lim; i++) {
    int64 sum = 0;
    for(int j = i; j <= lim; j += i) {
      sum += uku[j];
    }
    x[i] = sum;
  }

  int ok = N, ng = 1;
  Combination latte(N + 5, mod1);
  Combination malta(N + 5, mod2);

  auto check = [&](int mid) {
    vector< int64 > y1(lim + 1), y2(lim+1);
    for(int i = 1; i <= lim; i++) {
      if(x[i] > 0) {
        y1[i] = latte.C(x[i], mid);
        y2[i] = malta.C(x[i], mid);
      }
    }
    for(int i = lim; i >= 1; i--) {
      for(int j = i + i; j <= lim; j += i) {
        y1[i] += mod1 - y1[j];
        if(y1[i] >= mod1) y1[i] -= mod1;
        y2[i] += mod2 - y2[j];
        if(y2[i] >= mod2) y2[i] -= mod2;
      }
    }
    return y1[1] != 0 || y2[1] != 0;
  };

  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}