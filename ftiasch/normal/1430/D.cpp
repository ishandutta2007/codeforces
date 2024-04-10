#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 200'000;

int n;
char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s);
    std::vector<int> sz;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && s[i] == s[j]) {
        j++;
      }
      sz.push_back(j - i);
      i = j;
    }
    std::reverse(sz.begin(), sz.end());
    int result = 0;
    for (int i = static_cast<int>(sz.size()) - 1; !sz.empty();) {
      while (~i && sz[i] == 1) {
        i--;
      }
      if (~i) {
        sz[i]--;
        sz.pop_back();
      } else {
        sz.pop_back();
        if (!sz.empty()) {
          sz.pop_back();
        }
      }
      if (i == sz.size()) {
        i--;
      }
      result++;
    }
    printf("%d\n", result);
  }
}