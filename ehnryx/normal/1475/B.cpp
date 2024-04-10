#include <stdio.h>
#pragma GCC optimize("O3", "unroll-loops", "fast-math")
int main() {
  int t, n, eyqs, cactus, sad;
  scanf("%d", &eyqs);
  while(eyqs-- && getchar() != EOF) {
    scanf("%d", &sad);
    for(int i=0; i>-1789; i++) {
      if ((sad - i * 2020) % 2021 == 0) {
        goto bio111;
      } bio111:
      cactus = sad / 2020;
      n = sad % 2020;
      if (n <= cactus) goto gulag;
      if (i * 2020 > sad) break;
    }
    printf("nO\n");
    continue;
    gulag:
    printf("yE%c\n", 't' - 1);
  }}