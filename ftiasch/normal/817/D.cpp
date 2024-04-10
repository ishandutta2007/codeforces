#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  long long result = 0;
  for (int _ = 0; _ < 2; ++_) {
    std::vector<std::pair<int, int>> stack;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      int pop = 1;
      while (!stack.empty() && stack.back().first <= a[i]) {
        pop += stack.back().second;
        sum -= 1LL * stack.back().first * stack.back().second;
        stack.pop_back();
      }
      sum += 1LL * a[i] * pop;
      stack.emplace_back(a[i], pop);
      result += sum;
    }
    for (int i = 0; i < n; ++i) {
      a[i] *= -1;
    }
  }
  printf("%lld\n", result);
}