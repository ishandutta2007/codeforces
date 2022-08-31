#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int P = 998244353;

int norm(int x) { return x >= P ? (x - P) : x; }

void add(int& x, int y) { if ((x += y) >= P) x -= P; }

void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

void exGcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1;
    y = 0;
    return;
  }
  exGcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exGcd(a, P, x, y);
  return norm(x + P);
}

int mpow(int x, int k) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % P;
    x = x * (ll)x % P;
    k >>= 1;
  }
  return ret;
}


const int L = 18, R = 3;

namespace Zhao {

  using uint = unsigned int;
  using uint64 = unsigned long long;


  constexpr uint Max_size = 1 << 18 | 5;
  constexpr uint g = 3, Mod = 998244353;

  inline uint norm_2(const uint x)
  {
    return x < Mod * 2 ? x : x - Mod * 2;
  }

  inline uint norm(const uint x)
  {
    return x < Mod ? x : x - Mod;
  }

  struct Z
  {
    uint v;
    Z() { }
    Z(const uint _v) : v(_v) { }
  };

  inline Z operator+(const Z x1, const Z x2) { return norm(x1.v + x2.v); }
  inline Z operator-(const Z x1, const Z x2) { return norm(x1.v + Mod - x2.v); }
  inline Z operator-(const Z x) { return x.v ? Mod - x.v : 0; }
  inline Z operator*(const Z x1, const Z x2) { return static_cast<uint64>(x1.v) * x2.v % Mod; }
  inline Z &operator+=(Z &x1, const Z x2) { return x1 = x1 + x2; }
  inline Z &operator-=(Z &x1, const Z x2) { return x1 = x1 - x2; }
  inline Z &operator*=(Z &x1, const Z x2) { return x1 = x1 * x2; }

  inline Z Power(Z Base, int Exp)
  {
    Z res = 1;
    for (; Exp; Base *= Base, Exp >>= 1)
      if (Exp & 1)
        res *= Base;
    return res;
  }

  inline Z Rec(const Z x)
  {
    return Power(x, Mod - 2);
  }

  int size;
  uint w[Max_size], w_q[Max_size];

  inline uint mult_Shoup_2(const uint x, const uint y, const uint y_q)
  {
    uint q = static_cast<uint64>(x) * y_q >> 32;
    return x * y - q * Mod;
  }

  inline uint mult_Shoup(const uint x, const uint y, const uint y_q)
  {
    return norm(mult_Shoup_2(x, y, y_q));
  }

  inline uint mult_Shoup_q(const uint x, const uint y, const uint y_q)
  {
    uint q = static_cast<uint64>(x) * y_q >> 32;
    return q + (x * y - q * Mod >= Mod);
  }

  void init_w(const int n)
  {
    for (size = 2; size < n; size <<= 1)
      ;
    uint pr = Power(g, (Mod - 1) / size).v;
    uint pr_q = (static_cast<uint64>(pr) << 32) / Mod;
    uint pr_r = (static_cast<uint64>(pr) << 32) % Mod;
    size >>= 1;
    w[size] = 1, w_q[size] = (static_cast<uint64>(w[size]) << 32) / Mod;
//	for (int i = 1; i != size; ++i)
//		w[size + i] = mult_Shoup(w[size + i - 1], pr, pr_q), w_q[size + i] = (static_cast<uint64>(w[size + i]) << 32) / Mod;
#define compute(r, r_q, b, b_q)\
	do\
	{\
		uint x = b;\
		uint64 p = static_cast<uint64>(x) * pr_q;\
		uint q = p >> 32;\
		r = norm(x * pr - q * Mod);\
		r_q = static_cast<uint>(p) + mult_Shoup_q(pr_r, b, b_q);\
	} while (0)
    if (size <= 4)
    {
      for (int i = 1; i != size; ++i)
        compute(w[size + i], w_q[size + i], w[size + i - 1], w_q[size + i - 1]);
    }
    else
    {
      for (int i = 1; i != 8; ++i)
        compute(w[size + i], w_q[size + i], w[size + i - 1], w_q[size + i - 1]);
      pr = w[size + 4], pr_q = w_q[size + 4], pr_r = -pr_q * Mod;
      for (int i = 8; i != size; i += 4)
      {
        compute(w[size + i + 0], w_q[size + i + 0], w[size + i - 4], w_q[size + i - 4]);
        compute(w[size + i + 1], w_q[size + i + 1], w[size + i - 3], w_q[size + i - 3]);
        compute(w[size + i + 2], w_q[size + i + 2], w[size + i - 2], w_q[size + i - 2]);
        compute(w[size + i + 3], w_q[size + i + 3], w[size + i - 1], w_q[size + i - 1]);
      }
    }
    for (int i = size - 1; i; --i)
      w[i] = w[i *2], w_q[i] = w_q[i * 2];
    size <<= 1;
  }

//void DFT_fr_2(Z _A[], const int L)
//{
//	uint *A = reinterpret_cast<uint *>(_A);
//	for (int d = L >> 1; d; d >>= 1)
//		for (int i = 0; i != L; i += d << 1)
//			for (int j = 0; j != d; ++j)
//			{
//				uint x = norm_2(A[i + j] + A[i + d + j]);
//				uint y = mult_Shoup_2(A[i + j] + Mod * 2 - A[i + d + j], w[d + j], w_q[d + j]);
//				A[i + j] = x, A[i + d + j] = y;
//			}
//}
  void DFT_fr_2(Z _A[], const int L)
  {
    if (L == 1)
      return;
    uint *A = reinterpret_cast<uint *>(_A);
//	auto butterfly1 = [](uint &a, uint &b)
//	{
//		uint x = norm_2(a + b), y = norm_2(a + Mod * 2 - b);
//		a = x, b = y;
//	};
#define butterfly1(a, b)\
	do\
	{\
		uint _a = a, _b = b;\
		uint x = norm_2(_a + _b), y = norm_2(_a + Mod * 2 - _b);\
		a = x, b = y;\
	} while (0)
    if (L == 2)
    {
      butterfly1(A[0], A[1]);
      return;
    }
//	auto butterfly = [](uint &a, uint &b, const uint _w, const uint _w_q)
//	{
//		uint x = norm_2(a + b), y = mult_Shoup_2(a + Mod * 2 - b, _w, _w_q);
//		a = x, b = y;
//	};
#define butterfly(a, b, _w, _w_q)\
	do\
	{\
		uint _a = a, _b = b;\
		uint x = norm_2(_a + _b), y = mult_Shoup_2(_a + Mod * 2 - _b, _w, _w_q);\
		a = x, b = y;\
	} while (0)
    if (L == 4)
    {
      butterfly1(A[0], A[2]);
      butterfly(A[1], A[3], w[3], w_q[3]);
      butterfly1(A[0], A[1]);
      butterfly1(A[2], A[3]);
      return;
    }
    for (int d = L >> 1; d != 4; d >>= 1)
      for (int i = 0; i != L; i += d << 1)
        for (int j = 0; j != d; j += 4)
        {
          butterfly(A[i + j + 0], A[i + d + j + 0], w[d + j + 0], w_q[d + j + 0]);
          butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_q[d + j + 1]);
          butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_q[d + j + 2]);
          butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_q[d + j + 3]);
        }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 4]);
      butterfly(A[i + 1], A[i + 5], w[5], w_q[5]);
      butterfly(A[i + 2], A[i + 6], w[6], w_q[6]);
      butterfly(A[i + 3], A[i + 7], w[7], w_q[7]);
    }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 2]);
      butterfly(A[i + 1], A[i + 3], w[3], w_q[3]);
      butterfly1(A[i + 4], A[i + 6]);
      butterfly(A[i + 5], A[i + 7], w[3], w_q[3]);
    }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 1]);
      butterfly1(A[i + 2], A[i + 3]);
      butterfly1(A[i + 4], A[i + 5]);
      butterfly1(A[i + 6], A[i + 7]);
    }
#undef butterfly1
#undef butterfly
  }

  void DFT_fr(Z _A[], const int L)
  {
    DFT_fr_2(_A, L);
    for (int i = 0; i != L; ++i)
      _A[i] = norm(_A[i].v);
  }

//void IDFT_fr(Z _A[], const int L)
//{
//	uint *A = reinterpret_cast<uint *>(_A);
//	for (int d = 1; d != L; d <<= 1)
//		for (int i = 0; i != L; i += d << 1)
//			for (int j = 0; j != d; ++j)
//			{
//				uint x = norm_2(A[i + j]);
//				uint t = mult_Shoup_2(A[i + d + j], w[d + j], w_q[d + j]);
//				A[i + j] = x + t, A[i + d + j] = x + Mod * 2 - t;
//			}
//	std::reverse(A + 1, A + L);
//	if (L == 2)
//		A[0] = norm_2(A[0]), A[1] = norm_2(A[1]);
//	int k = __builtin_ctz(L);
//	for (int i = 0; i != L; ++i)
//	{
//		uint64 m = -A[i] & (L - 1);
//		A[i] = norm((A[i] + m * Mod) >> k);
//	}
//}
  void IDFT_fr(Z _A[], const int L)
  {
    if (L == 1)
      return;
    uint *A = reinterpret_cast<uint *>(_A);
//	auto butterfly1 = [](uint &a, uint &b)
//	{
//		uint x = norm_2(a), t = norm_2(b);
//		a = x + t, b = x + Mod * 2 - t;
//	};
#define butterfly1(a, b)\
	do\
	{\
		uint _a = a, _b = b;\
		uint x = norm_2(_a), t = norm_2(_b);\
		a = x + t, b = x + Mod * 2 - t;\
	} while (0)
    if (L == 2)
    {
      butterfly1(A[0], A[1]);
      A[0] = norm(norm_2(A[0])), A[0] = A[0] & 1 ? A[0] + Mod : A[0], A[0] /= 2;
      A[1] = norm(norm_2(A[1])), A[1] = A[1] & 1 ? A[1] + Mod : A[1], A[1] /= 2;
      return;
    }
//	auto butterfly = [](uint &a, uint &b, const uint _w, const uint _w_q)
//	{
//		uint x = norm_2(a), t = mult_Shoup_2(b, _w, _w_q);
//		a = x + t, b = x + Mod * 2 - t;
//	};
#define butterfly(a, b, _w, _w_q)\
	do\
	{\
		uint _a = a, _b = b;\
		uint x = norm_2(_a), t = mult_Shoup_2(_b, _w, _w_q);\
		a = x + t, b = x + Mod * 2 - t;\
	} while (0)
    if (L == 4)
    {
      butterfly1(A[0], A[1]);
      butterfly1(A[2], A[3]);
      butterfly1(A[0], A[2]);
      butterfly(A[1], A[3], w[3], w_q[3]);
      std::swap(A[1], A[3]);
      for (int i = 0; i != L; ++i)
      {
        uint64 m = -A[i] & 3;
        A[i] = norm((A[i] + m * Mod) >> 2);
      }
      return;
    }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 1]);
      butterfly1(A[i + 2], A[i + 3]);
      butterfly1(A[i + 4], A[i + 5]);
      butterfly1(A[i + 6], A[i + 7]);
    }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 2]);
      butterfly(A[i + 1], A[i + 3], w[3], w_q[3]);
      butterfly1(A[i + 4], A[i + 6]);
      butterfly(A[i + 5], A[i + 7], w[3], w_q[3]);
    }
    for (int i = 0; i != L; i += 8)
    {
      butterfly1(A[i + 0], A[i + 4]);
      butterfly(A[i + 1], A[i + 5], w[5], w_q[5]);
      butterfly(A[i + 2], A[i + 6], w[6], w_q[6]);
      butterfly(A[i + 3], A[i + 7], w[7], w_q[7]);
    }
    for (int d = 8; d != L; d <<= 1)
      for (int i = 0; i != L; i += d << 1)
        for (int j = 0; j != d; j += 4)
        {
          butterfly(A[i + j + 0], A[i + d + j + 0], w[d + j + 0], w_q[d + j + 0]);
          butterfly(A[i + j + 1], A[i + d + j + 1], w[d + j + 1], w_q[d + j + 1]);
          butterfly(A[i + j + 2], A[i + d + j + 2], w[d + j + 2], w_q[d + j + 2]);
          butterfly(A[i + j + 3], A[i + d + j + 3], w[d + j + 3], w_q[d + j + 3]);
        }
#undef butterfly1
#undef butterfly
    std::reverse(A + 1, A + L);
    int k = __builtin_ctz(L);
    for (int i = 0; i != L; ++i)
    {
      uint64 m = -A[i] & (L - 1);
      A[i] = norm((A[i] + m * Mod) >> k);
    }
  }

}

int p[26];
Zhao::Z res[1 << L];
Zhao::Z vs[26][1 << L], vt[26][1 << L];
char s[1 << L], t[1 << L];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 26; ++i) {
    cin >> p[i];
    --p[i];
  }
  cin >> s >> t;
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i < n; ++i) {
    vs[s[i] - 'a'][i] += 1;
  }
  for (int i = 0; i < m; ++i) {
    vt[t[i] - 'a'][i] += 1;
  }
  Zhao::init_w(1 << L);
  for (int i = 0; i < 26; ++i) {
    reverse(vs[i] + 1, vs[i] + (1 << L));
    Zhao::DFT_fr_2(vs[i], 1 << L);
    Zhao::DFT_fr_2(vt[i], 1 << L);
  }
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < (1 << L); ++j)
      res[j] += vs[i][j] * vt[i][j];
    if (p[i] != i) {
      for (int j = 0; j < (1 << L); ++j)
        res[j] += vs[i][j] * vt[p[i]][j];
    }
  }
  Zhao::IDFT_fr(res, 1 << L);
  for (int i = 0; i <= m - n; ++i)
    cout << (res[i].v == n);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}