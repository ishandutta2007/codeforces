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

int arr[1000005];
int fen[1000005];

void update(int pos, int val) {
  for(;pos <= 1000000; pos |= (pos + 1))
    fen[pos] += val;
}

int find(int pos) {
  int ret = 0;
  for (;pos >= 0; pos = (pos & (pos + 1)) - 1)
    ret += fen[pos];
  return ret;
}

int d[1000006], valid[1000006];
int fact[1000006];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    x >>= 1;
    a = 1LL * a * a % mod;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);

  fact[0] = 1;
  for (int i = 1; i <= 1000000; ++i)
    fact[i] = 1LL * fact[i - 1] * i % mod;

  valid[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    d[i] = find(arr[i]);
    update(arr[i], 1);
    valid[i] = (1LL * fact[n - 1 - i] * d[i] + valid[i + 1]) % mod;
    // cout << valid[i] << " " << d[i] << endl;
  }

  int inv4 = mPow(4, mod - 2);

  int ans = 0;
  for (int i = 0; i + 1 < n; ++i) {
    int m = (n - 1 - i);
    // cout << 1LL * d[i] * fact[m] % mod * m % mod * (m - 1) % mod * inv4 % mod
    //      << " " << 1LL * d[i] * valid[i + 1] % mod << " " 
    //      <<  (1LL * d[i] * (d[i] - 1) / 2) % mod * fact[m] % mod << endl;
    int cur = (1LL * d[i] * fact[m] % mod * m % mod * (m - 1) % mod * inv4 + 
      1LL * d[i] * valid[i + 1] % mod + (1LL * d[i] * (d[i] - 1) / 2) % mod * fact[m] % mod) % mod;
    // cout << cur << endl;
    ans += cur;
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}