/* Written by Filip Hlasek 2014 */
#include <stdio.h>
#include <stdlib.h>

#define FOR(i,a,b) for(i=(a);i<=(b);i++)
#define REP(i,b) for(i=0;i<b;i++)

#define MAXN 111111

int a[MAXN], N;

int main(int argc, char **argv) {
  int cnt, i;
  scanf("%d", &N);
  REP(i, N) scanf("%d", a + i);
  int best = a[1] * a[1] + 1;
  FOR(cnt, 1, N - 1) {
    if (cnt * cnt >= best) break;
    int sum = 0, tmp = cnt * cnt;
    REP(i, cnt) sum += a[i + 1];
    if (sum < 10000 && sum > -10000 && best > tmp + sum * sum) {
      best = tmp + sum * sum;
    }
    REP(i, N - 1 - cnt) {
      sum = sum - a[i + 1] + a[i + cnt + 1];
      if (sum < 10000 && sum > -10000 && best > tmp + sum * sum) {
        best = tmp + sum * sum;
      }
    }
  }
  printf("%d\n", best);
  return (0);
}