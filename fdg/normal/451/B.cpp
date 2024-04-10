#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005], a[100002];
map<int, int> f;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    a[i] = arr[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; ++i)
    f[a[i]] = i;
  for (int i = 0; i < n; ++i)
    arr[i] = f[arr[i]];
  int mn = n + 1, mx = -1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] != i) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }
  if (mx == - 1) mn = mx = 0;
  int l = mn, r = mx;
  while (l < r) {
    swap(arr[l], arr[r]);
    ++l; --r;
  }
  for (int i = 0; i < n; ++i)
    if (arr[i] != i) {
      puts("no");
      return 0;
    }
  puts("yes");
  printf("%d %d\n", mn + 1, mx + 1);
  return 0;
}