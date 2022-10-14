#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int last = 1;
  std::vector<int> result;
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    if (std::__gcd(last, a) > 1) {
      result.push_back(last = 1);
    }
    result.push_back(last = a);
  }
  printf("%d\n", static_cast<int>(result.size() - n));
  for (int x: result) {
      printf("%d ", x);
  }
}