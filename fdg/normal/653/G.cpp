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

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int inv(int x) {
  return mPow(x, mod - 2);
}

int arr[300002], coefs[300002], dv[300002], cnt[22][300002];

int get(int l, int r) {
  return (coefs[r] - (l > 0 ? coefs[l - 1] : 0) + mod) % mod;
}

int solve(int n, int d) {
  int zero = n;
  for (int j = 1; j <= 20; ++j)
    zero -= cnt[j][d];
  cnt[0][d] = zero;

  int ret = 0, sum = 0;
  for (int j = 0; j <= 20; ++j) {
    ret = (ret + 1LL * get(sum, sum + cnt[j][d] - 1) * j) % mod;
    sum += cnt[j][d];
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  coefs[0] = (1 - mPow(2, n - 1) + mod) % mod;
  int Cnk = 1;
  for (int i = 1; i < n; ++i) {
    Cnk = 1LL * Cnk * (n + 1 - i) % mod * inv(i) % mod;
    coefs[i] = (coefs[i - 1] + Cnk) % mod;
  }

  for (int i = 1; i < n; ++i)
    coefs[i] = (coefs[i - 1] + coefs[i]) % mod;

  for (int i = 2; i <= 300000; ++i) {
    if (dv[i] == 0)
      for (int j = i; j <= 300000; j += i) {
        if (dv[j] == 0) dv[j] = i;
      }
  }

  for (int i = 0; i < n; ++i) {
    int x = arr[i];
    while (x > 1) {
      int d = dv[x], c = 0;
      while (x % d == 0) {
        ++c;
        x /= d;
      }
      cnt[c][d]++;
    }
  }

  int ans = 0;
  for (int i = 2; i <= 300000; ++i) {
    ans = (ans + solve(n, i)) % mod;
  }
  cout << ans << endl;

  return 0;
}