#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool get(long long n, long long d1, long long d2) {
  if (d1 + d2 + d2 <= n && (n - d1 - d2 - d2) % 3 == 0) return true;
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k, d1, d2;
    scanf("%lld%lld%lld%lld", &n, &k, &d1, &d2);
    // scanf("%I64%I64d%I64d%I64d", &n, &k, &d1, &d2);
    bool ok = false;
    for (int s1 = -1; !ok && s1 <= 1; ++s1)
      for (int s2 = -1; !ok && s2 <= 1; ++s2) {
        if (s1 == 0 || s2 == 0) continue;
        long long arr[3] = { s1 * d1, 0, s2 * d2};
        sort(arr, arr + 3);
        if (n % 3 == 0 && get(k, arr[2] - arr[1], arr[1] - arr[0]) && get(n - k, arr[1] - arr[0], arr[2] - arr[1])) {
          puts("yes");
          ok = true;
        }
      }
    if (!ok) puts("no");
  }
  return 0;
}