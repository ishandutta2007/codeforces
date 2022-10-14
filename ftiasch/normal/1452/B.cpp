#include <bits/stdc++.h>

const int N = 100'000;

int n, a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int max = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      max = std::max(max, a[i]);
      sum += a[i];
    }
    int rest = sum % (n - 1);
    printf("%lld\n",
           std::max(max * (n - 1LL) - sum,
                    static_cast<long long>(rest ? (n - 1) - rest : 0)));
  }
}