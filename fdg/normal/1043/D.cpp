#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int arr[10][100005];
int where[10][100005];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &arr[i][j]);
      where[i][arr[i][j]] = j;
    }
  }

  int l[11] = {0}, r[11] = {0};
  for (int i = 1; i < m; ++i)
    l[i] = r[i] = where[i][arr[0][0]];

  long long ans = 0, lasp = -1;
  for (int j = 0; j < n; ++j) {
    while (true) {
      bool ok = r[0] < n - 1;
      for (int i = 1; i < m; ++i) {
        if (arr[0][r[0] + 1] != arr[i][r[i] + 1]) {
          ok = false;
          break;
        }
      }

      if(!ok) break;

      for (int i = 0; i < m; ++i)
        ++r[i];
    }

    long long len = r[0] - l[0] + 1, bad = lasp - l[0] + 1;
    ans += len * (len + 1) / 2 - bad * (bad + 1) / 2;
    // cout << j << "  " << len << " " << bad << endl;
    lasp = r[0];

    l[0]++;
    if (r[0] < l[0]) r[0] = l[0];
    for (int i = 1; i < m; ++i) {
      ++l[i];
      if (r[i] < l[i])
        l[i] = r[i] = where[i][arr[0][l[0]]];
    }
  }

  cout << ans << endl;

  return 0;
}