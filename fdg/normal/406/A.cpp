#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[1001];

int main() {
  int n, a, ans = 0;
  scanf("%d\n", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a);
      if (i == j) {
        arr[i] = a;
        ans ^= arr[i];
      }
    }
    scanf("\n");
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 3) printf("%d", ans);
    else {
      scanf("%d", &a);
      ans ^= 1;
    }
  }
  puts("");
  return 0;
}