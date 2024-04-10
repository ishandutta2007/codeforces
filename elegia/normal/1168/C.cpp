#include <cstdio>

#include <algorithm>

using namespace std;

const int N = 300010, L = 20;

int n, q;
int a[N], cur[L];
int reach[N][L];

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < L; ++j)
      if (a[i] >> j & 1) {
        reach[i][j] = i;
        for (int k = 0; k < L; ++k)
          reach[i][k] = max(reach[i][k], reach[cur[j]][k]);
        cur[j] = i;
      }
  }
  while (q--) {
    bool flag = false;
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 0; i < L; ++i)
      if (a[x] >> i & 1)
        flag |= reach[y][i] >= x;
    puts(flag ? "Shi" : "Fou");
  }
  return 0;
}