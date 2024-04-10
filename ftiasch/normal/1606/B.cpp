#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long steps = 0, alives = 1;
    while (alives < k) {
      steps++;
      alives = std::min(alives * 2, n);
    }
    printf("%lld\n", steps + (n - alives + k - 1) / k);
  }
}