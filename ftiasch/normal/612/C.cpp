#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1'000'000;

int code(char ch) { return std::string("<{[(>}])").find(ch); }

int main() {
  static char s[N + 1];
  scanf("%s", s);
  int result = [&]() -> int {
    int result = 0;
    std::vector<int> stack;
    for (int i = 0; s[i]; ++i) {
      int c = code(s[i]);
      if (c < 4) {
        stack.push_back(c);
      } else {
        c -= 4;
        if (stack.empty()) {
          return -1;
        }
        result += stack.back() != c;
        stack.pop_back();
      }
    }
    if (!stack.empty()) {
      return -1;
    }
    return result;
  }();
  if (~result) {
    printf("%d\n", result);
  } else {
    puts("Impossible");
  }
}