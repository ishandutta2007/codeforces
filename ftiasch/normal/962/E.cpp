#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int last_r = INT_MIN, last_b = INT_MIN, last_p = INT_MIN, max_gap_r = 0,
      max_gap_b = 0;
  long long result = 0;
  for (int i = 0, x; i < n; ++i) {
    char kind[2];
    scanf("%d%s", &x, kind);
    if (*kind == 'P' || *kind == 'R') {
      if (last_r != INT_MIN) {
        result += x - last_r;
        max_gap_r = std::max(max_gap_r, x - last_r);
      }
      last_r = x;
    }
    if (*kind == 'P' || *kind == 'B') {
      if (last_b != INT_MIN) {
        result += x - last_b;
        max_gap_b = std::max(max_gap_b, x - last_b);
      }
      last_b = x;
    }
    if (*kind == 'P') {
      if (last_p != INT_MIN) {
        result += std::min(0LL, static_cast<long long>(x) - last_p - max_gap_b -
                                    max_gap_r);
      }
      last_p = x;
      max_gap_r = max_gap_b = 0;
    }
  }
  printf("%lld\n", result);
}