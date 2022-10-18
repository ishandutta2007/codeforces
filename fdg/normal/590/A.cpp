#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[500005];

void stupid(int n) {
  int tmp[102] = {0}, tmp2[102] = {0};
  for (int i = 1; i <= n; ++i)
    tmp[i] = arr[i];

  for (int it = 0; ; ++it) {
    tmp2[1] = tmp[1]; tmp2[n] = tmp[n];
    bool ok = true;
    for (int i = 2; i < n; ++i) {
      vector<int> v = {tmp[i - 1], tmp[i], tmp[i + 1]};
      sort(v.begin(), v.end());
      tmp2[i] = v[1];
      if (v[1] != tmp[i]) ok = false;
    }
    for (int i = 1; i <= n; ++i)
      tmp[i] = tmp2[i];
    if (ok) {
      cout << it << endl;
      for (int i = 1; i <= n; ++i)
        cout << tmp[i] << " ";
      cout << endl;
      break;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &arr[i]);
  arr[0] = arr[1]; arr[n + 1] = arr[n];

  // stupid(n);

  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    if (arr[i] != arr[i + 1]) {
      for (int j = i + 1; j <= n; ++j) {
        if (arr[j] == arr[j + 1]) {
          ans = max(ans, (j - i) / 2);
          // cout << i << "  " << j << endl;
          if (arr[i] == arr[j]) {
            for (int t = i; t <= j; ++t)
              arr[t] = arr[i];
          } else {
            int len = (j - i + 1) / 2;
            for (int t = 0; t < len; ++t) {
              arr[i + t] = arr[i];
              arr[j - t] = arr[j];
            }
          }
          i = j;
          break;
        }
      }
    }
  }

  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    if (i > 1) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
  return 0;
}