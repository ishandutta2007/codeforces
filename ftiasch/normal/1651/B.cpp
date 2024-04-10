#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int M = 19;

int power_of_three[M];

int main() {
  power_of_three[0] = 1;
  for (int i = 1; i < M; ++i) {
    power_of_three[i] = power_of_three[i - 1] * 3;
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    if (n <= M) {
      puts("YES");
      for (int i = 0; i < n; ++i) {
        printf("%d%c", power_of_three[i], " \n"[i + 1 == n]);
      }
    } else {
      puts("NO");
    }
  }
}