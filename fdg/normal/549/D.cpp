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
  int n, m;
  scanf("%d%d\n", &n, &m);
  char f[102][102] = {0};
  int mat[102][102] = {0};
  for (int i = 0; i < n; ++i) {
    gets(f[i]);
    for (int j = 0; j < m; ++j) {
      mat[i][j] = (f[i][j] == 'W');
    }
  }
  int ans = 0, need = !mat[n - 1][m - 1];
  int sum[102][102] = {0};
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      int cur = mat[i][j] == need ? 1 : -1;
      if (sum[i][j] != cur) {
        // cout << sum[i][j] << endl;
        ++ans;
        for (int ii = 0; ii <=i; ++ii)
          for (int jj = 0; jj <= j; ++jj)
            sum[ii][jj] += (cur - sum[i][j]);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}