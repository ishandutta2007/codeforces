#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
typedef unsigned int uint;

lint mult(lint a, lint b, lint mod) {
  lint result = 0, b2p = b % mod;
  while (a > 0) {
    if (a % 2 == 1) {
      result += b2p;
      if (result >= mod) result -= mod;
    }
    a /= 2;

    b2p *= 2;
    if (b2p >= mod) b2p -= mod;
  }
  return result;
}

template<typename T, typename U, typename B> struct ModularFFT {
  //>> Only FFT.
  inline T ifmod(U v, T mod) { return v >= (U)mod ? v - mod : v; }
  T pow(T x, U y, T p) {
    T ret = 1, x2p = x;
    while (y) {
      if (y % 2) ret = (B)ret * x2p % p;
      y /= 2; x2p = (B)x2p * x2p % p;
    }
    return ret;
  }
  vector<T> fft(vector<T> y, T mod, T gen, bool invert = false) {
    int N = y.size(); assert(N == (N&-N));
    if (N == 0) return move(y);
    vector<int> rev(N);
    for (int i = 1; i < N; ++i) {
      rev[i] = (rev[i>>1]>>1) | (i&1 ? N>>1 : 0);
      if (rev[i] < i) swap(y[i], y[rev[i]]);
    }
    assert((mod-1)%N == 0);
    T rootN = pow(gen, (mod-1)/N, mod);
    if (invert) rootN = pow(rootN, mod-2, mod);
    vector<T> rootni(N/2);
    for (int n = 2; n <= N; n *= 2) {
      T rootn = pow(rootN, N/n, mod);
      rootni[0] = 1;
      for (int i = 1; i < n/2; ++i) rootni[i] = (B)rootni[i-1] * rootn % mod;
      for (int left = 0; left != N; left += n) {
	int mid = left + n/2;
	for (int i = 0; i < n/2; ++i) {
	  T temp = (B)rootni[i] * y[mid+i] % mod;
	  y[mid+i] = ifmod((U)y[left+i] + mod - temp, mod);
	  y[left+i] = ifmod((U)y[left+i] + temp, mod);
	}
      }
    }
    if (invert) {
      T invN = pow(N, mod-2, mod);
      for (T &v : y) v = (B)v * invN % mod;
    }
    return move(y);
  }
  //<<
  vector<T> convolution(vector<T> a, vector<T> b, T mod, T gen) {
    int N = a.size()+b.size()-1, N2 = nextpow2(N);
    a.resize(N2); b.resize(N2);
    vector<T> fa = fft(move(a), mod, gen), fb = fft(move(b), mod, gen), &fc = fa;
    for (int i = 0; i < N2; ++i) fc[i] = (B)fc[i] * fb[i] % mod;
    vector<T> c = fft(move(fc), mod, gen, true);
    c.resize(N); return move(c);
  }
  vector<T> circular_convolution(vector<T> a, vector<T> b, T mod, T gen) {
    assert(a.size() == b.size()); int N = a.size();
    vector<T> ret = convolution(move(a), move(b), mod, gen);
    for (int i = ret.size()-1; i >= N; --i) ret[i-N] = ifmod((U)ret[i-N] + ret[i], mod);
    ret.resize(N); return move(ret);
  }
  uint nextpow2(uint v) { return v ? 1 << __lg(2*v-1) : 1; }
};

vector<int> solve(int n, vector<int> acc_count, int p1, int g1) {
  vector<int> acc_count2 = acc_count;
  reverse(acc_count2.begin(), acc_count2.end());

  ModularFFT<int, uint, lint> mfft;
  vector<int> conv = mfft.convolution(acc_count, acc_count2, p1, g1);

  vector<int> result(n + 1, 0);
  lint cur_result_sum = 0;
  for (int diff = 1; diff <= n; ++diff) {
    result[diff] = conv[diff + n] % p1;
    cur_result_sum += result[diff];
  }
  lint target_sum = (lint)n * (n + 1) / 2LL;
  result[0] = (target_sum - cur_result_sum) % p1;

  return result;
}

int main() {
  int p1 = 469762049;
  int g1 = 303754541;
  lint m1 = 127677049144030003LL;

  int p2 = 1811939329;
  int g2 = 738223485;
  lint m2 = 723503282710695119LL;

  lint p1p2 = (lint)p1 * p2;

  assert(m1 % p1 == 1);
  assert(m1 % p2 == 0);

  assert(m2 % p1 == 0);
  assert(m2 % p2 == 1);

  int n, x;
  scanf("%d %d", &n, &x);
  vector<int> values(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &values[i]);

  vector<int> acc_count(n + 1, 0);
  int acc = 0;
  ++acc_count[acc];
  for (int i = 0; i < n; ++i) {
    if (values[i] < x) {
      ++acc;
    }
    ++acc_count[acc];
  }

  vector<int> result1 = solve(n, acc_count, p1, g1);
  vector<int> result2 = solve(n, acc_count, p2, g2);

  vector<lint> result(result1.size());

  for (int i = 0; i < (int)result.size(); ++i) {
    result[i] = mult(m1, result1[i], p1p2) + mult(m2, result2[i], p1p2);
    if (result[i] >= p1p2) result[i] -= p1p2;
  }

  for (int diff = 0; diff <= n; ++diff) {
    if (diff > 0) printf(" ");
    printf("%lld", result[diff]);
  }
  printf("\n");

  return 0;
}