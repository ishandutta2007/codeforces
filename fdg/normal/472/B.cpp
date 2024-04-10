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
  int n, k;
  cin >> n >> k;
  int arr[2002];
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  sort(arr, arr + n);
  reverse(arr, arr + n);
  int ans = 0;
  for (int i = 0; i < n; i += k) {
    ans += 2 * (arr[i] - 1);
  }
  cout << ans << endl;
  return 0;
}