#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[300005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  long long ans = 1LL * n * arr[n - 1], cnt = n;
  for (int i = n - 2; i >= 0; --i) {
    ans += cnt * arr[i];
    --cnt;
  }
  cout << ans << endl;
  return 0;
}