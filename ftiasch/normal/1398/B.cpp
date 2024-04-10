#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    std::vector<int> parts;
    for (int i = 0; s[i];) {
      if (s[i] == '1') {
        int j = i;
        while (s[j] == '1') {
          j++;
        }
        parts.push_back(j - i);
        i = j;
      } else {
        i++;
      }
    }
    std::sort(parts.begin(), parts.end(), std::greater<int>());
    int result = 0;
    for (int i = 0; i < parts.size(); i += 2) {
      result += parts[i];
    }
    printf("%d\n", result);
  }
}