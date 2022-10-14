#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  int q;
  scanf("%d", &q);
  std::vector<int> visit(n, -1);
  for (int t = 0; t < q; ++t) {
    int l, r;
    scanf("%d%d", &l, &r);
    std::reverse(a.begin() + (l - 1), a.begin() + r);
    int cycles = 0;
    for (int i = 0; i < n; ++i) {
      if (visit[i] != t) {
        cycles++;
        int j = i;
        do {
          visit[j = a[j]] = t;
        } while (j != i);
      }
    }
    puts((n - cycles) & 1 ? "odd" : "even");
  }
}