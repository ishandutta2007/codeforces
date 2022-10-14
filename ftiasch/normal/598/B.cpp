#line 1 "sol.cpp"
#include <bits/stdc++.h>

char s[10'001];

int main() {
  scanf("%s", s);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    l--;
    int length = r - l;
    std::rotate(s + l, s + l + (length + (-k) % length) % length, s + r);
  }
  puts(s);
}