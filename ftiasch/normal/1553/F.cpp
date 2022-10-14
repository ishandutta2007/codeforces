#include <bits/stdc++.h>

const int N = 200000;
const int M = 300001;

int n, m, a[N];
long long p_fenwick[M];
int q_fenwick[M];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    m = std::max(m, a[i]);
  }
  long long result = 0;
  long long q_sum = 0;
  // p % q
  for (int i = 0; i < n; ++i) {
    // a[i] % a[j]
    result += static_cast<long long>(i) * a[i];
    for (int k = a[i]; k; k -= -k & k) {
      result -= p_fenwick[k];
    }
    for (int begin = a[i]; begin <= m; begin += a[i]) {
      for (int k = begin; k <= m; k += -k & k) {
        p_fenwick[k] += a[i];
      }
    }
    // a[j] % a[i]
    result += q_sum;
    long long count = 0;
    for (int begin = a[i]; begin <= m; begin += a[i]) {
      for (int k = begin; k <= m; k += -k & k) {
        count += q_fenwick[k];
      }
    }
    result -= count * a[i];
    q_sum += a[i];
    for (int k = a[i]; k; k -= -k & k) {
      q_fenwick[k]++;
    }
    printf("%lld%c", result, " \n"[i + 1 == n]);
  }
}