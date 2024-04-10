#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<int> ways(n + 1);
  ways[1] = 1;
  for (int i = 1; i < n; ++i) {
    ways[i + 1] = 1LL * ways[i] * i % MOD;
  }
  int fact = 1;
  for (int i = n; i >= 1; --i) {
    ways[i] = 1LL * ways[i] * fact % MOD;
    fact = 1LL * i * fact % MOD;
  }
  std::sort(a.begin(), a.end());
  int result = 0;
  for (int i = n, j = n; i--;) {
    while (j && a[i] <= a[j - 1]) {
      j--;
    }
    if (a[i] != a[n - 1]) {
      result = (result + 1LL * a[i] * ways[n - j]) % MOD;
    }
  }
  printf("%d\n", result);
}