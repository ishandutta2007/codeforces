#include <bits/stdc++.h>

const int M = 60;

long long c;
int n;
long long count[M + 1];

int solve() {
  int result = 0;
  for (int i = 0; i < M; ++i) {
    if (c >> i & 1) {
      if (!count[i]) {
        int j = i;
        while (j < M && !count[j]) {
          j++;
        }
        if (j == M) {
          return -1;
        }
        result += j - i;
        count[j]--;
        for (int k = i + 1; k < j; ++k) {
          count[k]++;
        }
        count[i] += 2;
      }
      count[i]--;
    }
    count[i + 1] = std::min(count[i + 1] + (count[i] >> 1), c);
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%d", &c, &n);
    memset(count, 0, sizeof(count));
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      count[__builtin_ctz(a)]++;
    }
    printf("%d\n", solve());
  }
}