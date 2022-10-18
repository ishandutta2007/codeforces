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

int n, m, k;
int x[2002], y[2002];

int fact[200002], rfact[200002];

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }

  return ret;
}

int C(int n, int k) {
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

map<pair<int, int>, int> f;

int solve(int i, int j) {
  if (f.count({i, j}))
    return f[{i, j}];

  int all = C(i + j - 2, j - 1);

  for (int t = 0; t < k; ++t) {
    if (x[t] <= i && y[t] <= j && (x[t] != i || y[t] != j)) {
      all -= 1LL * solve(x[t], y[t]) * C(i - x[t] + j - y[t], i - x[t]) % mod;
      if (all < 0) all += mod;
    }
  }

  return f[{i, j}] = all;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x[i] >> y[i];
  }

  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= 200000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }

  cout << solve(n, m) << endl;
  return 0;
}