#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n;
char s[N + 1];

int main() {
  scanf("%d%s", &n, s);
  int l = 1;
  while (s[l] == s[0]) {
    l++;
  }
  int r = 1;
  while (s[n - r - 1] == s[n - 1]) {
    r++;
  }
  printf("%d\n",
         static_cast<int>((1 + l + r + (s[0] == s[n - 1] ? 1LL * l * r : 0)) %
                          998'244'353));
}