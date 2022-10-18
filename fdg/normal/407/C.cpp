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
int arr[100005];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int fact[100405], rfact[100405];

int C(int n, int k) {
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

int ans[102][100005];

int main() {
  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= 100400; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  for (int i = 0; i < m; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l; --r;
    ans[k][l] = (ans[k][l] + 1) % mod;
    for (int j = 0; j <= k; ++j) {
      ans[j][r + 1] = (ans[j][r + 1] - C(k - j + r - l, k - j) + mod) % mod;
    }
  }
  for (int i = 100; i >= 0; --i) {
    for (int j = 1; j < n; ++j) {
      ans[i][j] = (ans[i][j - 1] + ans[i][j]) % mod;
    }
    if (i)
      for (int j = 0; j < n; ++j) {
        ans[i - 1][j] = (ans[i - 1][j] + ans[i][j]) % mod;
      }
  }
  for (int i = 0; i < n; ++i) {
    if (i) printf(" ");
    printf("%d", (ans[0][i] + arr[i]) % mod);
  }
  printf("\n");
  return 0;
}