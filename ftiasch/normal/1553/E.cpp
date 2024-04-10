#include <bits/stdc++.h>

int main() {
  std::mt19937 gen{0};
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &p[i]);
      p[i]--;
    }
    std::vector<int> result, visited(n, -1);
    for (int iter = 0; iter < 50; ++iter) {
      int index = gen() % n;
      int shift = (index + n - p[index]) % n;
      int need = n;
      for (int i = 0; i < n; ++i) {
        if (visited[i] != iter) {
          int j = i;
          do {
            visited[j] = iter;
            j = (p[j] + shift) % n;
          } while (j != i);
          need--;
        }
      }
      if (need <= m) {
        result.push_back(shift);
      }
    }
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
    printf("%d", static_cast<int>(result.size()));
    for (int k : result) {
      printf(" %d", k);
    }
    puts("");
  }
}