#include <bits/stdc++.h>

const int N = 100000;

char s[N + 1];
int sum[N + 1];

int64_t solve(int n, int x) {
  int64_t result = 0;
  for (int i = 0; i < n; ++ i) {
    if (!sum[n]) {
      if (sum[i] == x) {
        return -1;
      }
    } else if (sum[n] > 0) {
      result += sum[i] <= x && (x - sum[i]) % sum[n] == 0;
    } else {
      result += sum[i] >= x && (sum[i] - x) % -sum[n] == 0;
    }
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T --) {
    int n, x;
    scanf("%d%d%s", &n, &x, s);
    sum[0] = 0;
    for (int i = 0; i < n; ++ i) {
      sum[i + 1] = sum[i] + (s[i] == '0' ? 1 : -1);
    }
    printf("%lld\n", solve(n, x));
  }
}