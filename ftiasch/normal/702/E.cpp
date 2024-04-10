#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int D = 33;

struct Sum {
  long long sum;
  int min;
};

Sum operator+(const Sum &a, const Sum &b) {
  return {a.sum + b.sum, std::min(a.min, b.min)};
}

int jump[2][N], cur[N];
Sum sum[2][N], result[N];

int main() {
  int n;
  long long m;
  scanf("%d%lld", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", jump[0] + i);
  }
  for (int i = 0, w; i < n; ++i) {
    scanf("%d", &w);
    sum[0][i] = {w, w};
  }
  for (int i = 0; i < n; ++i) {
    cur[i] = i;
    result[i] = Sum{0, INT_MAX};
  }
  for (int k = 0; k < 34; ++k) {
    if (m >> k & 1) {
      for (int i = 0; i < n; ++i) {
        result[i] = result[i] + sum[k & 1][cur[i]];
        cur[i] = jump[k & 1][cur[i]];
      }
    }
    for (int i = 0; i < n; ++i) {
      int j = jump[k & 1][i];
      jump[(k + 1) & 1][i] = jump[k & 1][j];
      sum[(k + 1) & 1][i] = sum[k & 1][i] + sum[k & 1][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%lld %d\n", result[i].sum, result[i].min);
  }
}