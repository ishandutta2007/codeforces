#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
long long f[22];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod; x >>= 1;
  }
  return ret;
}

int rev[23];

int C(long long n, int k) {
  int ret = 1;
  for (int i = 0; i < k; ++i) {
    ret = 1LL * ret * ((n - i) % mod) % mod;
    ret = 1LL * ret * rev[i + 1] % mod;
  }
  return ret;
}

int main() {
  for (int i = 0; i <= 20; ++i)
    rev[i] = mPow(i, mod - 2);
  int n;
  long long s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i)
    cin >> f[i];
  long long ans = 0;
  for (int mask = 0; mask < (1<<n); ++mask) {
    int sgn = 1, left = n;
    long long cur = s;
    for (int i = 0; i < n; ++i)
      if (mask & (1<<i)) {
        sgn *= -1;
        cur -= f[i] + 1;
        --left;
      }
    if (cur >= 0) {
      ans += sgn * C(cur + n - 1, n - 1);
    }
  }
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}