#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int cnt[1002], was[1002];

int main() {
  int m, t, r;
  scanf("%d%d%d", &m, &t, &r);
  int arr[302] = {0};
  for (int i = 0; i < m; ++i) {
    scanf("%d", &arr[i]); arr[i] += 500;
  }
  sort(arr, arr + m);
  int ans = 0;
  for (int i = 0; i < m; ++i) {
    while (cnt[arr[i]] < r) {
      bool ok = false;
      for (int j = arr[i] - 1; j >= arr[i] - t; --j) {
        if (!was[j]) {
          // cout << j << endl;
          ok = true;
          ++ans;
          was[j] = true;
          for (int e = 1; e <= t; ++e)
            cnt[j + e]++;
          break;
        }
      }
      if (!ok) {
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}