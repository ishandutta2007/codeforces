#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'001;

int n, a[N], fenwick[N];
std::vector<int> queries[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int j = 2; j <= n; ++j) {
    queries[std::min(a[j], j - 1)].push_back(j);
  }
  long long result = 0;
  for (int i = 1; i <= n; ++i) {
    for (int k = std::min(a[i], n); k; k -= -k & k) {
      fenwick[k]++;
    }
    for (auto j : queries[i]) {
        for (int k = j; k <= n; k += -k & k) {
            result += fenwick[k];
        }
    }
  }
  printf("%lld\n", result);
}