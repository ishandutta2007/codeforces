#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

char s[N + 1], suf[N + 1];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  suf[n] = 'z';
  for (int i = n; i--;) {
    suf[i] = std::min(s[i], suf[i + 1]);
  }
  std::vector<char> stk;
  for (int i = 0; i < n; ++i) {
    stk.push_back(s[i]);
    while (!stk.empty() && stk.back() <= suf[i + 1]) {
      putchar(stk.back());
      stk.pop_back();
    }
  }
  while (!stk.empty()) {
    putchar(stk.back());
    stk.pop_back();
  }
  puts("");
}