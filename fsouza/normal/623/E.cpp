#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <complex>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long lint;
typedef complex<long double> doublex;

vector<doublex> fft(vector<doublex> y, bool invert = false) {
  const int N = y.size();
  assert(N == (N&-N));

  vector<int> rev(N);
  for (int i = 1; i < N; ++i) {
    rev[i] = (rev[i>>1]>>1) | (i&1 ? N>>1 : 0);
    if (rev[i] < i) swap(y[i], y[rev[i]]);
  }

  vector<doublex> rootni(N/2);
  for (int n = 2; n <= N; n *= 2) {
    const doublex::value_type ang = (invert ? +1.0 : -1.0) * 4.0*acos(0.0l)/n;
    const doublex rootn(cos(ang), sin(ang));

    rootni[0] = 1.0;
    for (int i = 1; i < n/2; ++i) rootni[i] = rootni[i-1] * rootn;

    for (int left = 0; left != N; left += n) {
      const int mid = left + n/2;
      for (int i = 0; i < n/2; ++i) {
	const doublex temp = rootni[i] * y[mid + i];
	y[mid + i] = y[left + i] - temp;
	y[left + i] += temp;
      }
    }
  }

  if (invert) for (auto &v : y) v /= (doublex)N;

  return move(y);
}

vector<doublex> convolution(vector<doublex> a, vector<doublex> b) {
  int n = a.size();
  a.resize(2*n); b.resize(2*n);
  vector<doublex> fa = fft(move(a)), fb = fft(move(b)), &fc = fa;
  for (int i = 0; i < 2*n; ++i) fc[i] = fc[i] * fb[i];
  vector<doublex> c = fft(move(fc), true);
  return move(c);
}

vector<lint> convolution(const vector<int> &a, const vector<int> &b) {
  vector<doublex> a2(a.size()), b2(b.size());
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  vector<doublex> res2 = convolution(a2, b2);
  vector<lint> res(res2.size());
  for (int i = 0; i < (int)res.size(); ++i)
    res[i] = round(res2[i].real());
  return res;
}

vector<int> polymult(const vector<int> &a, const vector<int> &b, int mod, int npart = 2) {
  if (a.empty() || b.empty()) return {};
  const int div = pow(mod+1, 1.0/npart) + 1, n = 2*a.size();
  vector<vector<doublex>> splita(npart, vector<doublex>(n)), splitb(npart, vector<doublex>(n));
  for (int i = 0; i < (int)a.size(); ++i) {
    int v = a[i];
    for (int j = 0; j < npart; ++j) splita[j][i] = v % div, v /= div;
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    int v = b[i]; // <     ^             v
    for (int j = 0; j < npart; ++j) splitb[j][i] = v % div, v /= div;
  }
  for (int i = 0; i < npart; ++i)
    splita[i] = fft(move(splita[i])), splitb[i] = fft(move(splitb[i]));
  vector<int> result(a.size()+b.size()-1);
  vector<doublex> res(n);
  for (int i = 0; i < npart; ++i)
    for (int j = 0; j < npart; ++j) {
      int multby = 1;
      for (int k = 0; k < i+j; ++k) multby = (lint)multby * div % mod;
      for (int k = 0; k < n; ++k) res[k] = splita[i][k] * splitb[j][k];
      res = fft(move(res), true);
      for (int k = 0; k < (int)result.size(); ++k)
	result[k] = (result[k] + (lint)round(res[k].real()) % mod * multby) % mod;
    }
  return move(result);
}

const int maxk = (1<<15)-1;
const int mod = 1e9+7;

int fact[maxk+1], invfact[maxk+1];

int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y) {
    if (y%2) ret = (lint)ret * x2p % mod;
    y /= 2;
    x2p = (lint)x2p * x2p % mod;
  }
  return ret;
}

int inv(int a) { return modpow(a, mod-2, mod); }

int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (lint)fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

struct dp_t {
  int n, value[maxk+1];
};

dp_t combine(dp_t &left, dp_t &right) {
  vector<int> leftpoly(maxk+1), rightpoly(maxk+1);

  for (int i = 0; i <= maxk; ++i)
    leftpoly[i] = (lint)invfact[i] * left.value[i] % mod * modpow(2, i * right.n, mod) % mod;
  for (int i = 0; i <= maxk; ++i)
    rightpoly[i] = (lint)invfact[i] * right.value[i] % mod;

  vector<int> pmult = polymult(leftpoly, rightpoly, mod);

  dp_t result;
  result.n = left.n + right.n;
  for (int i = 0; i <= maxk; ++i) result.value[i] = (lint)pmult[i] * fact[i] % mod;
  return result;
}

int main() {
  fact[0] = 1;
  for (int k = 1; k <= maxk; ++k) fact[k] = (lint)fact[k-1] * k % mod;
  invfact[maxk] = inv(fact[maxk]);
  for (int k = maxk-1; k >= 0; --k) invfact[k] = (lint)invfact[k+1] * (k+1) % mod;

  lint N;
  int K;
  cin >> N >> K;

  int result;
  if (N > K) result = 0;
  else {
    dp_t dp;
    dp.n = 0;
    dp.value[0] = 1;
    fill(dp.value+1, dp.value+maxk+1, 0);

    dp_t x2p;
    x2p.n = 1;
    x2p.value[0] = 0;
    fill(x2p.value+1, x2p.value+maxk+1, 1);

    for (int p = 0; dp.n != N; ++p) {
      if (N & (1<<p))
	dp = combine(dp, x2p);
      if (dp.n != N)
	x2p = combine(x2p, x2p);
    }

    result = 0;
    for (int k = 0; k <= K; ++k)
      result = (result + (lint)binom(K, k) * dp.value[k]) % mod;
  }

  printf("%d\n", result);

  return 0;
}