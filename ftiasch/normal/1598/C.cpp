#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    std::map<int, int> cnt;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
      cnt[a[i]]++;
    }
    long long result = 0;
    for (auto [k, c] : cnt) {
      if (1LL * k * n == sum) {
        result += 1LL * c * (c - 1) / 2;
      } else if (1LL * k * n > sum && 2 * sum % n == 0) {
        auto iterator = cnt.find(2 * sum / n - k);
        if (iterator != cnt.end()) {
          result += 1LL * c * iterator->second;
        }
      }
    }
    printf("%lld\n", result);
  }
}