#include <bits/stdc++.h>

const int N = 5000;

int n, a[N], b[N];
long long pre[N + 1], suf[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  pre[0] = 0;
  for (int i = 0; i < n; ++i) {
    pre[i + 1] = pre[i] + 1LL * a[i] * b[i];
  }
  suf[n - 1] = 0;
  for (int i = n - 1; i >= 1; --i) {
    suf[i - 1] = suf[i] + 1LL * a[i] * b[i];
  }
  long long result = pre[n];
  for (int s = 1; s < n; ++s) {
    {
      long long sum = 1LL * a[s] * b[s];
      for (int i = s - 1, j = s + 1; i >= 0 && j < n; --i, ++j) {
        sum += 1LL * a[i] * b[j] + 1LL * a[j] * b[i];
        result = std::max(result, sum + pre[i] + suf[j]);
      }
    }
    {
      long long sum = 0;
      for (int i = s - 1, j = s; i >= 0 && j < n; --i, ++j) {
        sum += 1LL * a[i] * b[j] + 1LL * a[j] * b[i];
        result = std::max(result, sum + pre[i] + suf[j]);
      }
    }
  }
  printf("%lld\n", result);
}