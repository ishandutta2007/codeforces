#include <bits/stdc++.h>

static const int MOD = 1e9 + 7;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<char> buffer(m + 1);
    int has_zero = false;
    int power_of_two = 1;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buffer.data());
      for (int j = 0; j < m; ++j) {
        if (buffer[j] == '0') {
          has_zero = true;
        } else {
          power_of_two += power_of_two;
          if (power_of_two >= MOD) {
            power_of_two -= MOD;
          }
        }
      }
    }
    printf("%d\n", has_zero ? power_of_two : (power_of_two + MOD - 1) % MOD);
  }
}