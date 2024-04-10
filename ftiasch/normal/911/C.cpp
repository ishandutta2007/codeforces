#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  std::array<int, 3> k;
  scanf("%d%d%d", &k[0], &k[1], &k[2]);
  std::sort(k.begin(), k.end());
  puts(k[0] == 1 || (k[0] == 2 && k[1] == 2) ||
               (k[0] == 2 && k[1] == 4 && k[2] == 4) ||
               (k[0] == 3 && k[1] == 3 && k[2] == 3)
           ? "YES"
           : "NO");
}