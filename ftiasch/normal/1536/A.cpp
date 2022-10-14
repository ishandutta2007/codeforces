#include <bits/stdc++.h>

#define SIZE(v) static_cast<int>((v).size())

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::set<int> s;
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
      s.insert(b[i]);
    }
    for (int j = 0; j < SIZE(b) && SIZE(b) <= 300; ++j) {
      for (int i = 0; i < j && SIZE(b) <= 300; ++i) {
        int d = std::abs(b[i] - b[j]);
        if (!s.count(d)) {
          b.push_back(d);
          s.insert(d);
        }
      }
    }
    if (SIZE(b) <= 300) {
      printf("YES\n%d\n", SIZE(b));
      for (int i = 0; i < SIZE(b); ++i) {
        printf("%d%c", b[i], " \n"[i + 1 == SIZE(b)]);
      }
    } else {
      puts("NO");
    }
  }
}