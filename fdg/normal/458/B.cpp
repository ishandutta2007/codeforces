#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr1[100005], arr2[100005];

long long solve(int n, int a[], int m, int b[]) {
  long long ret = 0, s = 0;
  for (int i = 0; i < m; ++i)
    s += b[i];
  ret = s;
  for (int i = n - 2; i >= 0; --i) {
    ret += min(s, (long long) a[i]);
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr1[i]);
  sort(arr1, arr1 + n);
  for (int i = 0; i < m; ++i)
    scanf("%d", &arr2[i]);
  sort(arr2, arr2 + m);
  cout << min(solve(n, arr1, m, arr2), solve(m, arr2, n, arr1)) << endl;
  return 0;
}