#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int main() {
  int n, k, cnt[2] = {0}, a;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    cnt[a & 1]++;
  }
  int st = (n - k + 1) / 2, dn = (n - k) / 2;
//  if ((k % 2 == 1) && cnt[0] <= st) puts("Stannis");
//  else

  if (n == k) {
    if (cnt[1] & 1) puts("Stannis");
    else puts("Daenerys");
  } else if (n == k + 1) {
    if (cnt[0] && cnt[1] % 2 == 1 || cnt[1] && cnt[1] % 2 == 0) puts("Stannis");
    else puts("Daenerys");
  } else {
    if (st == dn) {
      if (cnt[0] <= st && (k % 2 == 1)) puts("Stannis");
      else puts("Daenerys");
    } else {
      if (cnt[1] <= dn || cnt[0] <= dn && (k % 2 == 0)) puts("Daenerys");
      else puts("Stannis");
    }
  }
  return 0;
}