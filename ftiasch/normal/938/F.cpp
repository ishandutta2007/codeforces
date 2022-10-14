#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = s.size();
  int l = 0;
  while ((1 << (l + 1)) - 1 < n) {
    l++;
  }
  std::vector<bool> valid(1 << l);
  valid[0] = true;
  for (int i = 0; i + ((1 << l) - 1) < n; ++i) {
    char c = 'z';
    for (int mask = 0; mask < 1 << l; ++mask) {
      if (valid[mask]) {
        c = std::min(c, s[i + mask]);
        for (int k = 0; k < l; ++k) {
          valid[mask | 1 << k] = true;
        }
      }
    }
    for (int mask = 0; mask < 1 << l; ++ mask) {
        if (s[i + mask] != c) {
            valid[mask] = false;
        }
    }
    putchar(c);
  }
  puts("");
}