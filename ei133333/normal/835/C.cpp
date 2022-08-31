#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, Q, C;
int star[100][100][11];
int64 sum[11][102][102];

int main()
{
  scanf("%d %d %d", &N, &Q, &C);
  for(int i = 0; i < N; i++) {
    int x, y, s;
    scanf("%d %d %d", &x, &y, &s);
    --x, --y;
    ++star[x][y][s];
  }
  for(int now = 0; now <= C; now++) {
    for(int i = 0; i < 100; i++) {
      for(int j = 0; j < 100; j++) {
        for(int k = 0; k <= C; k++) {
          int val = (k + now) % (C + 1);
          sum[now][i][j + 1] += 1LL * star[i][j][k] * val;
        }
      }
      for(int j = 1; j <= 100; j++) {
        sum[now][i][j] += sum[now][i][j - 1];
      }
    }
  }

  for(int i = 0; i < Q; i++) {
    int t, x1, y1, x2, y2;
    scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
    int64 ret = 0;
    t %= C + 1;
    --x1, --x2;
    for(int j = x1; j <= x2; j++) {
      ret += sum[t][j][y2];
      ret -= sum[t][j][y1 - 1];
    }
    printf("%lld\n", ret);
  }
}