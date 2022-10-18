#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[102][102];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &arr[i][j]);
    }
  }
  int ans = 500;
  if (n <= k) {
    for (int mask = 0; mask < (1<<n); ++mask) {
      int need = 0;
      for (int j = 0; j < m; ++j) {
        int dif = 0;
        for (int i = 0; i < n; ++i) {
          if (((mask & (1<<i)) > 0) != arr[i][j]) ++dif;
        }
        dif = min(dif, n - dif);
        need += dif;
      }
      ans = min(ans, need);
    }
  } else {
    for (int t = 0; t < n; ++t) {
      int need = 0;
      for (int i = 0; i < n; ++i) {
        int dif = 0;
        for (int j = 0; j < m; ++j) {
          if (arr[i][j] != arr[t][j]) ++dif;
        }
        need += min(dif, m - dif);
      }
      ans = min(ans, need);
    }
  }
  if (ans > k) ans = -1;
  printf("%d\n", ans);
  return 0;
}