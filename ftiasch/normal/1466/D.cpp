#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> weight(n), degree(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &weight[i]);
    }
    for (int i = 0, a, b; i < n - 1; ++i) {
      scanf("%d%d", &a, &b);
      degree[a - 1]++;
      degree[b - 1]++;
    }
    std::vector<int> delta;
    for (int i = 0; i < n; ++i) {
      while (degree[i] > 1) {
        degree[i]--;
        delta.push_back(weight[i]);
      }
    }
    std::sort(delta.begin(), delta.end(), std::greater<int>());
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += weight[i];
    }
    printf("%lld", sum);
    for (int &d : delta) {
      sum += d;
      printf(" %lld", sum);
    }
    puts("");
  }
}