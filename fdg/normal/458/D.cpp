#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

double C[302][302];
double mem[100002];

int n, m, k;


int main() {
  cin >> n >> m >> k;
  double ans = 0;
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1.0;
    for (int j = 1; j <= i; ++j)
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }

  mem[0] = 1.0;
  for (int i = 1; i <= m; ++i)
    mem[i] = mem[i - 1] * (k - i + 1) / (m - i + 1);

  for (int r = 0; r <= n; ++r) {
    for (int c = 0; c <= n; ++c) {
      if (n * n - (n - r) * (n - c) <= k) {
        int need = n * n - (n - r) * (n - c);
        ans += C[n][r] * C[n][c] * mem[need];
      }
    }
  }
  if (ans > 1e99) {
    puts("1e99");
    return 0;
  }
  printf("%.10lf\n", ans);
  return 0;
}