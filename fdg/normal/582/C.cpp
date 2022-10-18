#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[200005], tmp[400005];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b);}

long long dp[200005];

long long solve(int n, int g) {
  for (int i = 0; i < g; ++i) {
    int mx = arr[i], pos = i;
    pos += g;
    if (pos >= n) pos -= n;
    while (pos >= g) {
      mx = max(mx, arr[pos]);
      pos += g;
      if (pos >= n) pos -= n;
    }
    tmp[i] = mx;
    // cout << mx << " ";
  }
  // cout << endl;
  for (int i = g; i < 2 * n; ++i)
    tmp[i] = tmp[i - g];
  for (int i = 0; i < 2 * n; ++i) {
    tmp[i] = tmp[i] <= arr[i % n];
    // cout << tmp[i] << " ";
  }
  // cout << endl;
  long long ret = 0;
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == 1) {
      int len = 1, pos = i;
      while (i + 1 < 2 * n && tmp[i + 1] == 1)
        ++i, ++len;

      // cout << g << "  " << pos << "  " << len << endl;
      for (int j = g; j < n && j <= len; j += g) {
        if (gcd(j, n) != g) continue;
        int last = min(n - 1, pos + len - j);
        if (last >= pos)
          ret += last - pos + 1;
      }
    }
  }
  // cout << g << "  " << ret << endl;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0)
      ans += solve(n, i);
  }

  cout << ans << endl;

  return 0;
}