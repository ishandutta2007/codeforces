#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool is_vowel(char c) {
  return std::string("aeiouy").find(c) != std::string::npos;
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<char> s(n + 1);
  scanf("%s", s.data());
  int top = 0;
  for (int i = 0; i < n; ++i) {
    if (is_vowel(s[i])) {
      if (!top || !is_vowel(s[top - 1])) {
        s[top++] = s[i];
      }
    } else {
      s[top++] = s[i];
    }
  }
  s[top] = '\0';
  puts(s.data());
}