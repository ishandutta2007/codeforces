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
  int n, arr[55][55], p[55] = {0};
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (p[j] != 0) continue;

      int mn = 2 * n, mx = -mn;
      for (int t = 0; t < n; ++t) {
        if (t == j || p[t] != 0) continue;
        mn = min(mn, arr[j][t]);
        mx = max(mx, arr[j][t]);
      }
      if (mn == mx) {
        p[j] = mn;
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] == 0) p[i] = n;
    cout << p[i] << " ";
  }
  cout << endl;
  return 0;
}