#include <bits/stdc++.h>

const int N = 1000001;

int n, stack[N];
long long sum[N];

int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      sum[i + 1] = sum[i] + a;
    }
    int t = -1;
    for (int i = 1; i <= n; ++i) {
      int j = i - 1;
      while (~t && (sum[j] - sum[stack[t]]) * (i - j) >
                       (sum[i] - sum[j]) * (j - stack[t])) {
        j = stack[t--];
      }
      stack[++t] = j;
    }
    stack[t + 1] = n;
    for (int i = 0; i <= t; ++i) {
      int cnt = stack[i + 1] - stack[i];
      double avg = 1.0 * (sum[stack[i + 1]] - sum[stack[i]]) / cnt;
      for (int j = 0; j < cnt; ++j) {
        printf("%.9f\n", avg);
      }
    }
    return 0;
  }
}