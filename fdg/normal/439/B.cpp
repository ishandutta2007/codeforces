#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[100005];

int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += 1LL * x * arr[i];
    x = max(x - 1, 1);
  }
  cout << ans << endl;
  return 0;
}