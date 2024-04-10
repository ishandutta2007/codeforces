#include <bits/stdc++.h>

const int N = 200'000;

int n, p[N], q[N];
char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", p + i);
    }
    scanf("%s", s);
    // int dislikes = std::count(s, s + n, '0');
    std::vector<std::tuple<int, int, int>> order(n);
    for (int i = 0; i < n; ++i) {
      order[i] = {static_cast<int>(s[i] - '0'), p[i], i};
    }
    std::sort(order.begin(), order.end());
    int rank = 1;
    for (auto [_, __, i] : order) {
      q[i] = rank++;
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", q[i], " \n"[i + 1 == n]);
    }
  }
}