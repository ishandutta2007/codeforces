#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

long long arr[102][102];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  long long mx = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%lld", &arr[i][j]);
      mx = max(mx, arr[i][j]);
    }
  }
  long long a[102] = {0}, w = -1;
  for (int i = 1; i < n; ++i) {
    long long add = -1, neg = 0;
    for (int j = 0; j < m; ++j) {
      if (arr[i - 1][j] <= arr[i][j]) {
        add = a[i] = arr[i][j] - arr[i - 1][j];
      } else {
        neg = arr[i][j] - arr[i - 1][j];
      }
    }
    if (add == -1) a[i] = neg;
    if (add != -1 && neg != 0) w = add - neg;
  }
  if (w == -1) w = mx + 1;
  for (int i = 1; i < n; ++i) {
    if (a[i] < 0) a[i] += w;
    a[i] = (a[i] + a[i - 1]) % w;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (arr[i][j] != (a[i] + arr[0][j]) % w) ok = false;
  if (ok) {
    puts("YES");
    cout << w << endl;
    for (int i = 0; i < n; ++i)
      cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < m; ++i)
      cout << arr[0][i] << " ";
    cout << endl;
  } else {
    puts("NO");
  }
  return 0;
}