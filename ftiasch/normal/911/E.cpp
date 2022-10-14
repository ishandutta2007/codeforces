#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  // 231 avoiding
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &a[i]);
  }
  auto solve = [&]() -> bool {
    std::set<int> left;
    for (int i = 1; i <= n; ++i) {
      left.insert(i);
    }
    for (int i = 0; i < m; ++i) {
      left.erase(a[i]);
    }
    int cur = 1;
    std::vector<int> stack;
    for (int i = 0; i < n; ++i) {
      if (i < m) {
        if (!stack.empty() && stack.back() < a[i]) {
          return false;
        }
      } else {
        auto it = std::prev(stack.empty() ? left.end()
                                          : left.lower_bound(stack.back()));
        a[i] = *it;
        left.erase(it);
      }
      stack.push_back(a[i]);
      while (!stack.empty() && stack.back() == cur) {
        stack.pop_back();
        cur++;
      }
    }
    return true;
  };
  if (solve()) {
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
  } else {
    puts("-1");
  }
}