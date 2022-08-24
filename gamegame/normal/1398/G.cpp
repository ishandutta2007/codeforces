#ifdef Rahul
#include "RAHUL.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define error(...) 42;
#endif
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
typedef long long i64;
template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
#define Luv(...) [&] (auto &&u, auto &&v) { return __VA_ARGS__; }
const int MOD = (int) 1e9 + 7;
const i64 INF = (i64) 1e18 + 42;

namespace FFT {
  typedef int res_t;
  typedef float num_t;
  struct Complex {
    num_t real, imag;
    Complex() = default;
    Complex(const num_t x, const num_t y = 0): real(x), imag(y) {}
    
    Complex& operator *= (const Complex &rhs) {
      const num_t temp = real * rhs.real - imag * rhs.imag;
      imag = real * rhs.imag + imag * rhs.real; real = temp;
      return *this;
    }
    friend Complex operator * (Complex lhs, const Complex &rhs) {
      lhs *= rhs; return lhs;
    }
    Complex& operator += (const Complex &rhs) {
      real += rhs.real, imag += rhs.imag; return *this;
    }
    friend Complex operator + (Complex lhs, const Complex &rhs) {
      lhs += rhs; return lhs;
    }
    Complex& operator -= (const Complex &rhs) {
      real -= rhs.real, imag -= rhs.imag; return *this;
    }
    friend Complex operator - (Complex lhs, const Complex &rhs) {
      lhs -= rhs; return lhs;
    }
    Complex& operator /= (const num_t &rhs) {
      real /= rhs, imag /= rhs; return *this;
    }
  };
  
  const num_t PI = acos((num_t) -1);
  const int MAX = 1 << 19;
  static int bits[MAX];
  static Complex root[MAX], iroot[MAX];
  
  inline void prepare_roots() {
    root[1] = iroot[1] = 1;
    for (int len = 2; len < MAX; len *= 2) {
      const Complex w(cos(PI / len), sin(PI / len)), iw(w.real, -w.imag);
      for (int i = len >> 1; i < len; ++i) {
        root[i + i] = root[i]; root[i + i + 1] = root[i] * w;
        iroot[i + i] = iroot[i]; iroot[i + i + 1] = iroot[i] * iw;
      }
    }
  }
  inline void prepare_cache(int n) {
    static int last = -1;
    if (last == n) return; last = n;
    int lg = 0;
    while (1 << (lg + 1) < n) ++lg;
    for (int i = 1; i < n; ++i) 
      bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << lg);
  }
  
  void fft(vector<Complex> &a, bool invert) {
    int n = (int) a.size();
    if (n == 1) return;
    for (int i = 1; i < n; i++) if (i > bits[i]) swap(a[i], a[bits[i]]);
    const auto ws = (invert ? iroot : root); 
    for (int len = 1; len < n; len *= 2) {
      for (int i = 0; i < n; i += len << 1) {
        for (int j = 0; j < len; j++) {
          const Complex u = a[i + j], v = a[i + j + len] * ws[len + j];
          a[i + j] = u + v; a[i + j + len] = u - v;
        }
      }
    }
    if (invert) for (Complex &x: a) x /= n;
  }
  vector<res_t> multiply(vector<res_t> const &a, vector<res_t> const &b) {
    vector<Complex> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < (int) (a.size() + b.size())) n <<= 1;
    fa.resize(n); fb.resize(n);
    
    prepare_cache(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);

    vector<res_t> result(n);
    for (int i = 0; i < n; i++) result[i] = (res_t) rint(fa[i].real);
    while (result.size() >= a.size() + b.size()) result.pop_back();
    return result;
  }
} // namespace FFT

const int N = 1e6 + 42;
void read(int& x){
    char c=getchar();
    while(c<48 || c>57) c=getchar();
    x=0;
    while(c>=48 && c<=57){
        x=x*10+c-48;
        c=getchar();
    }
}
int main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  
  int n, x, y;read(n);read(x);read(y);
  vector<int> a(x + 1), b(x + 1);
  for (int i = 0; i <= n; ++i) {
    int t; read(t);
    a[t] = 1;
    b[x - t] = 1;
  }
  FFT::prepare_roots();
  a = FFT::multiply(a, b);
  a.erase(a.begin(), a.begin() + x);
  vector<int> c(N, -1);
  for (int i = 1; i <= x; ++i) if (a[i]) {
    int p = (i + y) << 1;
    for (int j = p; j < N; j += p) c[j] = p;
  }
  int q; read(q);
  while (q--) {
    int l; read(l);
    cout << c[l] << ' ';
  }
}