#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

namespace Numeric {
  // const int mod = 7340033;
  // const int root = 5;
  // const int root_1 = 4404020;
  // const int root_pw = 1<<20;
  
  const int mod = 998244353;
  const int root = 31;
  const int root_1 = 128805723;
  const int root_pw = 1<<23;

  int mPow(int a, int x) {
    int ret = 1;
    while (x > 0) {
      if (x & 1) ret = 1LL * ret * a % mod;
      a = 1LL * a * a % mod;
      x >>= 1;
    }
    return ret;
  }

  void fft(vector<int>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i) {
      int bit = n >> 1;
      for ( ; j >= bit; bit >>= 1) {
        j -= bit;
      }
      j += bit;
      if (i < j)
        swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
      int wlen = invert ? root_1 : root;
      for (int i = len; i < root_pw; i <<= 1) {
        wlen = 1LL * wlen * wlen % mod;
      }
      for (int i = 0; i < n; i += len) {
        int w = 1;
        for (int j = 0; j < len / 2; ++j) {
          int u = a[i + j], v = 1LL * a[i + j + len / 2] * w % mod;
          a[i + j] = u + v;
          if (a[i + j] >= mod)
            a[i + j] -= mod;
          a[i + j + len / 2] = u - v;
          if (a[i + j + len / 2] < 0)
            a[i + j + len / 2] += mod;
          w = 1LL * w * wlen % mod;
        }
      }
    }
    if (invert) {
      int rev = mPow(n, mod - 2);
      for (int i = 0; i < n; ++i)
        a[i] = 1LL * a[i] * rev % mod;
    }
  }

  vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int n = max(a.size(), b.size());
    vector<int> na = a, nb = b;
    na.resize(2 * n); nb.resize(2 * n);
    fft(na, false); fft(nb, false);
    for (int i = 0; i < 2 * n; ++i)
      na[i] = 1LL * na[i] * nb[i] % mod;
    fft(na, true);
    // na.resize(n);
    return na;
  }

  vector<int> findInverse(const vector<int>& f) {
    int n = f.size();
    vector<int> r(1, mPow(f[0], mod - 2));
    for (int it = 2; it <= n; it <<= 1) {
      vector<int> nr = multiply(multiply(r, r), vector<int> (f.begin(), f.begin() + it));
      nr.resize(it);
      for (int i = 0; i < nr.size(); ++i) {
        nr[i] = mod - nr[i];
      }
      for (int i = 0; i < it / 2; ++i) {
        nr[i] = (2LL * r[i] + nr[i]) % mod;
      }
      r = nr;
    }
    return r;
  }

  bool checkInverse(const vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); ++i) {
      int val = 0;
      for (int j = 0; j <= i; ++j) {
        val = (val + 1LL * a[i - j] * b[j]) % mod;
      }
      if (val != (i == 0))
        return false;
    }
    return true;
  }

  vector<int> squareRoot(const vector<int>& f) {
    int n = f.size();
    vector<int> r(1, 1);
    int inv2 = mPow(2, mod - 2);
    for (int it = 2; it <= n; it <<= 1) {
      r.resize(it);
      vector<int> res = multiply(findInverse(r), vector<int> (f.begin(), f.begin() + it));
      res.resize(it);
      for (int i = 0; i < r.size(); ++i) {
        res[i] += r[i];
        if (res[i] >= mod) res[i] -= mod;
      }
      for (int i = 0; i < res.size(); ++i)
        res[i] = 1LL * res[i] * inv2 % mod;
      r = res;
    }
    return r;
  }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int sz = 1;
  while (sz <= m) sz <<= 1;
  vector<int> v(sz, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (a <= m)
      v[a] = Numeric::mod - 4;
  }
  v[0] += 1;
  if (v[0] >= Numeric::mod) v[0] -= Numeric::mod;
  v = Numeric::squareRoot(v);
  v[0] += 1;
  if (v[0] >= Numeric::mod) v[0] -= Numeric::mod;
  v = Numeric::findInverse(v);

  for (int i = 1; i <= m; ++i)
    printf("%d\n", 2 * v[i] % Numeric::mod);
  return 0;
}