#include<bits/stdc++.h>

using namespace std;

namespace BitWiseConvolution {

  int mod_pow(int64_t x, int n, int mod) {
    int64_t ret = 1;
    while(n > 0) {
      if(n & 1) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (int) ret;
  }

  inline int add(int a, int b, int mod) {
    a += b;
    if(a >= mod) a -= mod;
    return a;
  }

  inline int mul(int a, int b, int mod) {
    unsigned long long x = (long long) a * b;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
    return (m);
  }

  void FastWalshHadamardTransform(vector< int > &F, int mod) {
    const int N = (int) F.size();
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          int s = F[j + k], t = F[j + k + i];
          F[j + k] = add(s, t, mod);
          F[j + k + i] = add(s, mod - t, mod);
        }
      }
    }
  }

  void FastAndTransform(vector< int > &F, int mod, bool inv) {
    const int N = (int) F.size();
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          int s = F[j + k], t = F[j + k + i];
          if(inv) F[j + k] = add(s, mod - t, mod);
          else F[j + k] = add(s, t, mod);
        }
      }
    }
  }


  void FastOrTransform(vector< int > &F, int mod, bool inv) {
    const int N = (int) F.size();
    for(int i = 1; i < N; i <<= 1) {
      for(int j = 0; j < N; j += i * 2) {
        for(int k = 0; k < i; k++) {
          int s = F[j + k], t = F[j + k + i];
          if(inv) F[j + k + i] = add(mod - s, t, mod);
          else F[j + k + i] = add(s, t, mod);
        }
      }
    }
  }

  vector< int > xor_convolution(vector< int > a, vector< int > b, int mod) {
    FastWalshHadamardTransform(a, mod);
    FastWalshHadamardTransform(b, mod);
    for(int i = 0; i < a.size(); i++) a[i] = mul(a[i], b[i], mod);
    FastWalshHadamardTransform(a, mod);
    auto rev = mod_pow((int) a.size(), mod - 2, mod);
    for(auto &x : a) x = (int) (1LL * x * rev % mod);
    return a;
  }

  vector< int > and_convolution(vector< int > a, vector< int > b, int mod) {
    FastAndTransform(a, mod, false);
    FastAndTransform(b, mod, false);
    for(int i = 0; i < a.size(); i++) a[i] = mul(a[i], b[i], mod);
    FastAndTransform(a, mod, true);
    return a;
  }



  void FastZetaTransform(vector< int > &F, int mod) {
    for(int i = 0; (1 << i) < F.size(); i++) {
      for(int j = 0; j < F.size(); j++) {
        if(j & (1 << i)) F[j] = add(F[j], F[j ^ (1 << i)], mod);
      }
    }
  }

  void FastMoebiusTransform(vector< int > &F, int mod) {
    for(int i = 0; (1 << i) < F.size(); i++) {
      for(int j = 0; j < F.size(); j++) {
        if(j & (1 << i)) F[j] = add(F[j], mod - F[j ^ (1 << i)], mod);
      }
    }
  }
  vector< int > or_convolution(vector< int > a, int mod) {
    vector< int > ret(a.size()), bit(a.size());
    vector< vector< int > > cnt(18, vector< int >(a.size()));

    for(int i = 1; i < 1 << 17; i++) {
      bit[i] = bit[i & (i - 1)] + 1;
    }
    for(int i = 0; i < a.size(); i++) {
      cnt[bit[i]][i] = add(cnt[bit[i]][i], a[i], mod);
    }
    for(int i = 0; i < 18; i++) {
      FastZetaTransform(cnt[i], mod);
    }
    for(int i = 0; i <= 17; i++) {
      vector< int > tmp(a.size());
      for(int j = 0; j <= i; j++) {
        for(int l = 0; l < a.size(); l++) {
          tmp[l] = add(tmp[l], mul(cnt[j][l], cnt[i - j][l], mod), mod);
        }
      }
      FastMoebiusTransform(tmp, mod);
      for(int j = 0; j < a.size(); j++) {
        if(bit[j] == i) ret[j] = add(ret[j], tmp[j], mod);
      }
    }
    return ret;
  }

};


const int mod = 1e9 + 7;

int main() {
  int N;
  scanf("%d", &N);


  vector< int > f(1 << 17);
  for(int i = 0; i < N; i++) {
    int s;
    scanf("%d", &s);
    f[s] += 1;
  }

  vector< int > fib(1 << 17);
  fib[0] = 0;
  fib[1] = 1;
  for(int i = 2; i < 1 << 17; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
    if(fib[i] >= mod) fib[i] -= mod;
  }

  auto a = BitWiseConvolution::or_convolution(f, mod);
  auto b = BitWiseConvolution::xor_convolution(f, f, mod);
  for(int i = 0; i < a.size(); i++) {
    a[i] = BitWiseConvolution::mul(fib[i], a[i], mod);
    b[i] = BitWiseConvolution::mul(fib[i], b[i], mod);
    f[i] = BitWiseConvolution::mul(fib[i], f[i], mod);
  }
  a = BitWiseConvolution::and_convolution(a, b, mod);
  a = BitWiseConvolution::and_convolution(a, f, mod);
  int ans = 0;
  for(int i = 0; i < 17; i++) {
    ans += a[1 << i];
    if(ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
}