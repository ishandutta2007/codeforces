#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  std::vector<int> last(n + n + 1, -1);
  last[n + 0] = 0;
  int result = 0;
  for (int i = 1, sum = 0; i <= n; ++i) {
    sum += s[i - 1] == '1' ? 1 : -1;
    if (~last[n + sum]) {
        result = std::max(result, i - last[n + sum]);
    } else {
        last[n + sum] = i;
    }
  }
  printf("%d\n", result);
}