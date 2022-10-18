#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[2002][2002];

int cnt[2002][2002] = {0};

int main() {
  int n, m, k;
  scanf("%d%d%d\n", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    gets(f[i]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (f[i][j] == 'U') {
        if (i % 2 == 0) cnt[i / 2][j]++;
      }
      if (f[i][j] == 'L') {
        int t = j - i;
        if (t >= 0 && t <= m)
          cnt[i][t]++;
        // cout << i << "  " << t << endl;
      }
      if (f[i][j] == 'R') {
        int t = j + i;
        if (t >= 0 && t <= m)
          cnt[i][t]++;
        // cout << i << "  " << t << endl;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int ans = 0;
    for (int j = 0; j < n; ++j)
      ans += cnt[j][i];
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}