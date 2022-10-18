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
int fact[100007], rfact[100007];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int C(int n, int k) {
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

int main() {
  int n, a;
  map<int, int> f;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    for (int j = 2; j * j <= a; ++j)
      if (a % j == 0) {
        while (a % j == 0) {
          a /= j;
          f[j]++;
        }
      }
    if (a > 1) f[a]++;
  }
  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }
  int ans = 1;
  for (map<int, int>::iterator it = f.begin(); it != f.end(); ++it)
    ans = 1LL * ans * C(it->second + n - 1, n - 1) % mod;
  cout << ans << endl;
  return 0;
}