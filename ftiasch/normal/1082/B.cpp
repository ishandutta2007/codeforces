#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

char s[N + 1];
int right[N + 1];

int main() {
  int n;
  scanf("%d%s", &n, s);
  int g = std::count(s, s + n, 'G');
  right[n] = 0;
  for (int i = n; i--;) {
    right[i] = s[i] == 'G' ? 1 + right[i + 1] : 0;
  }
  int result = *std::max_element(right, right + n);
  int left = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'S') {
      result = std::max(result, std::min(left + 1 + right[i + 1], g));
      left = 0;
    } else {
      left++;
    }
  }
  printf("%d\n", result);
}