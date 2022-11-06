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
typedef unsigned int uint;
typedef long double ldouble;

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
  vector<T> self_convolution(vector<T> a, T mod, T gen) {
    int N = 2*a.size()-1, N2 = nextpow2(N);
    a.resize(N2);
    vector<T> fc = fft(move(a), mod, gen);
    for (int i = 0; i < N2; ++i) fc[i] = (B)fc[i] * fc[i] % mod;
    vector<T> c = fft(move(fc), mod, gen, true);
    c.resize(N); return move(c);
  }
  uint nextpow2(uint v) { return v ? 1 << __lg(2*v-1) : 1; }
};
ModularFFT<int, uint, lint> mfft;
const int p1 = 469762049, g1 = 303754541;

void normalize(vector<int> &a) {
  int carry = 0;
  for (int i = 0; i < (int)a.size() || carry > 0; ++i) {
    if (i >= (int)a.size()) a.push_back(0);
    int value = carry + a[i];
    a[i] = value % 10;
    carry = value / 10;
  }
}

vector<int> divide_and_round_up(vector<int> a, int div) {
  int carry = 0;
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    int value = 10 * carry + a[i];
    a[i] = value / div;
    carry = value % div;
  }
  if (carry > 0) {
    a[0] += 1;
    normalize(a);
  }
  return a;
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
  vector<int> result = mfft.convolution(a, b, p1, g1);
  normalize(result);
  return result;
}

vector<int> exp2(const vector<int> &a) {
  vector<int> result = mfft.self_convolution(a, p1, g1);
  normalize(result);
  return result;
}

bool smaller_equal(const vector<int> &a, const vector<int> &b) {
  for (int i = (int)max(a.size(), b.size()) - 1; i >= 0; --i) {
    int va = i < (int)a.size() ? a[i] : 0;
    int vb = i < (int)b.size() ? b[i] : 0;
    if (va != vb)
      return va < vb;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string num_seq;
  cin >> num_seq;
  vector<int> num(num_seq.size());
  for (int i = 0; i < (int)num.size(); ++i)
    num[i] = num_seq[(int)num.size() - 1 - i] - '0';

  ldouble value = 0.0;
  for (int i = 0; i < (int)num.size(); ++i) {
    value += num[i];
    value /= 10.0;
  }

  vector<vector<int>> pow3_2i = {{3}};
  while ((int)pow3_2i.back().size() * 2 - 1 <= (int)num.size()) {
    pow3_2i.push_back(exp2(pow3_2i.back()));

  }

  int result = INT_MAX;
  for (int n2 = 2; n2 >= 0; --n2) {
    vector<int> num_div = divide_and_round_up(num, 1<<n2);
    int guess = max((int)round((log(value / pow((ldouble)2, (ldouble)n2)) +
                                (int)num.size() * log((ldouble)10)) /
                               log((ldouble)3)),
                    0);
    bool enough;
    if (guess >= (1<<(int)pow3_2i.size())) {
      enough = true;
    } else {
      static map<int, vector<int>> pow3_cache;
      vector<int> pow3;
      if (pow3_cache.find(guess) != pow3_cache.end()) {
        pow3 = pow3_cache[guess];
      } else if (pow3_cache.find(guess - 1) != pow3_cache.end()) {
        pow3 = pow3_cache[guess - 1];
        for (int &v : pow3) v *= 3;
        normalize(pow3);
        pow3_cache[guess] = pow3;
      } else if (pow3_cache.find(guess - 2) != pow3_cache.end()) {
        pow3 = pow3_cache[guess - 2];
        for (int &v : pow3) v *= 9;
        normalize(pow3);
        pow3_cache[guess] = pow3;
      } else {
        pow3 = {1};
        for (int l = 0; l < (int)pow3_2i.size(); ++l)
          if (guess & (1<<l))
            pow3 = multiply(pow3, pow3_2i[l]);
        pow3_cache[guess] = pow3;
      }
      enough = smaller_equal(num_div, pow3);
    }

    int need_3 = enough ? guess : guess + 1;
    int cand = max(3 * need_3 + 2 * n2, 1);
    result = min(result, cand);
  }
  cout << result << '\n';

  return 0;
}