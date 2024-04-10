#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

int stupid(int n, int f, int g = 0) {
  if (f > n) return 0;
  if (f == 0) {
    return g == 1 && n == 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += stupid(n - i, f - 1, gcd(g, i));
  }
  return ans;
}

int mod = 1000000007;

int mPow(int a, int x) {
  int ret = 1;
  while (x > 0) {
    if (x & 1) ret = 1LL * ret * a % mod;
    a = 1LL * a * a % mod;
    x >>= 1;
  }
  return ret;
}

int fact[100005], rfact[100005];

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * fact[n] * rfact[k] % mod * rfact[n - k] % mod;
}

map<int, int> mem[100005];

int solve(int n, int f) {
  // cout << n << "  " << f << endl;
  // fflush(stdout);
  // if (f >= n) return (f == n);
  if (f == 1) return (n == 1);
  if (mem[n].count(f)) return mem[n][f];
  int ans = C(n - 1, f - 1);
  // cout << ans << endl;
  // int l = n + 1;
  // for (int val = 1; l > 1; ++val) {
  //   val = max(val, n / (l - 1));
  //   if (val == n) break;
  //   int r = n / (val + 1);
  //   // cout << val << "  " << l - r - 1 << endl;
  //   if (val >= f && n % val == 0) {
  //     ans -= 1LL * solve(val, f) % mod;
  //     if (ans < 0) ans += mod;
  //   }
  //   l = r + 1;
  // }
  for (int val = 2; val * val <= n; ++val) {
    if (n % val == 0) {
      if (val >= f) {
        ans -= solve(val, f);
        if (ans < 0) ans += mod;
      }
      if (n >= val * f && val * val != n) {
        ans -= solve(n / val, f);
        if (ans < 0) ans += mod;
      }
    }
  }
  return mem[n][f] = ans;
}

int main() {
  fact[0] = rfact[0] = 1;
  for (int i = 1; i <= 100000; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % mod;
    rfact[i] = mPow(fact[i], mod - 2);
  }

  // for (int n = 1; n <= 20; ++n)
  //   for (int f = 1; f <= n; ++f)
  //     if (solve(n, f) != stupid(n, f)) {
  //       cout << n << "  " << f << endl;
  //     }

  int T;
  scanf("%d", &T);
  while (T--) {
    int n, f;
    scanf("%d%d", &n, &f);
    printf("%d\n", solve(n, f));
    // printf("%d\n", stupid(n, f));
  }
  return 0;
}