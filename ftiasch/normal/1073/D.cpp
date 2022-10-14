#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 1 << 18;

int n, a[N];
Long m, fenwick[N];

int main() {
  scanf("%d%lld", &n, &m);
  Long result = 0, sum = 0;
  int nn = 1;
  while (nn < n) {
    nn <<= 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    sum += a[i];
    for (int k = i; k < nn; k += ~k & k + 1) {
      fenwick[k] += a[i];
    }
  }
  int count = n;
  while (count > 0) {
    long long rounds = m / sum;
    result += count * rounds;
    m -= rounds * sum;
    // now, m < sum
    int offset = -1;
    Long target = m;
    for (int step = nn; (step >>= 1);) {
      if (fenwick[offset + step] <= target) {
        target -= fenwick[offset += step];
      }
    }
    offset++;
    count--;
    sum -= a[offset];
    for (int k = offset; k < nn; k += ~k & k + 1) {
      fenwick[k] -= a[offset];
    }
  }
  printf("%lld\n", result);
}