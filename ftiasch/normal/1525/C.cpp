#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> x(n), d(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x[i]);
    }
    {
      char buffer[2];
      for (int i = 0; i < n; ++i) {
        scanf("%s", buffer);
        d[i] = *buffer == 'R';
      }
    }
    std::vector<int> a[2];
    for (int i = 0; i < n; ++i) {
      a[x[i] & 1].emplace_back(i);
    }
    std::vector<int> result(n, -1);
    for (int t = 0; t < 2; ++t) {
      std::sort(a[t].begin(), a[t].end(),
                [&](int i, int j) { return x[i] < x[j]; });
      std::vector<int> stack;
      for (int i : a[t]) {
        // if (t == 1) {
        //   printf("%d %c\n", x[i], "LR"[d[i]]);
        // }
        if (d[i]) {
          // R
          stack.push_back(i);
        } else {
          // L
          if (stack.empty()) {
            x[i] = -x[i];
            stack.push_back(i);
          } else {
            int j = stack.back();
            stack.pop_back();
            assert((x[i] - x[j]) % 2 == 0);
            int t = (x[i] - x[j]) / 2;
            result[i] = result[j] = t;
          }
        }
      }
      for (int k = static_cast<int>(stack.size()) - 2; k >= 0; k -= 2) {
        int i = stack[k];
        int j = stack[k + 1];
        x[j] = m + m - x[j];
        assert((x[j] - x[i]) % 2 == 0);
        int t = (x[j] - x[i]) / 2;
        result[i] = result[j] = t;
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", result[i], " \n"[i + 1 == n]);
    }
  }
}