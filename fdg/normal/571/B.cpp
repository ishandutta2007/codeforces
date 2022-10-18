#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int n, k, st1, st2;
int arr[300005];

long long calc(int n, int k) {
  long long ret = 0;
  for (int i = k; i < n; ++i) {
    ret += abs(arr[i] - arr[i - k]);
  }
  return ret;
}

long long f[5005][5005];

long long solve(int k1, int k2, int pos) {
  // cout << pos << "  " << left << endl;
  if (k1 + k2 == 0) {
    return 0;
  }
  if (f[k1][k2] != -1)
    return f[k1][k2];
  long long ret = -1e+13;
  if (k1 > 0) {
    ret = max(ret, solve(k1 - 1, k2, pos + st1) + abs(arr[pos + st1] - arr[pos + st1 - 1]));
  }
  if (k2 > 0) {
    ret = max(ret, solve(k1, k2 - 1, pos + st2) + abs(arr[pos + st2] - arr[pos + st2 - 1]));
  }
  return f[k1][k2] = ret;
//  return f[{pos, left}] = max(abs(arr[pos + st1] - arr[pos + st1 - 1]) + solve(pos + st1, left - 1),
//                              abs(arr[pos + st2] - arr[pos + st2 - 1]) + solve(pos + st2, left - 1));
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  sort(arr, arr + n);
  long long ans = arr[n - 1] - arr[0];
  arr[n] = arr[n - 1];
  st1 = n / k, st2 = (n + k - 1) / k;
  memset(f, -1, sizeof(f));
  // cout << st1 << "  " << st2 << " " << solve(0, k) << endl;
  ans -= solve(k - n % k, n % k, 0);
  cout << ans << endl;
  return 0;
}