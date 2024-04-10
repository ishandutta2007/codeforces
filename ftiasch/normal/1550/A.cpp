#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int s;
    scanf("%d", &s);
    int r = std::sqrt(s);
    if (r * r < s) {
      r++;
    }
    printf("%d\n", r);
  }
}