#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n;
char s[N + 1], plan[N + 1];

bool check(int maxd) {
  int r = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      if (r + 1 <= maxd) {
        r++;
        plan[i] = '0';
      } else if (b + 1 <= maxd) {
        b++;
        plan[i] = '1';
      } else {
        return false;
      }
    } else if (r) {
      r--;
      plan[i] = '0';
    } else {
      b--;
      plan[i] = '1';
    }
  }
  return true;
}

int main() {
  scanf("%d%s", &n, s);
  int low = 1;
  int high = n / 2;
  while (low < high) {
    int middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  check(high);
  plan[n] = '\0';
  puts(plan);
}