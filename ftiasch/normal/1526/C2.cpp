#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  std::priority_queue<int, std::vector<int>, std::greater<int>> drunks;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    if (sum + a >= 0) {
      sum += a;
      drunks.push(a);
    } else if (!drunks.empty() && drunks.top() < a) {
      sum -= drunks.top();
      drunks.pop();
      sum += a;
      drunks.push(a);
    }
  }
  printf("%d\n", static_cast<int>(drunks.size()));
}