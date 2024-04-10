#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[5005];

int solve(int l, int r, int h) {
  if (l > r) return 0;
  if (l == r) return arr[l] > h;
  int mn = arr[l];
  for (int i = l; i <= r; ++i)
    mn = min(mn, arr[i]);
  int ret = mn - h;
  int pl = l;
  for (int i = l; i <= r + 1; ++i) {
    if (arr[i] <= mn || i == r + 1) {
      ret += solve(pl, i - 1, mn);
      pl = i + 1;
    }
  }
  return min(ret, r - l + 1);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  cout << solve(0, n - 1, 0) << endl;
  return 0;
}