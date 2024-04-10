#include <bits/stdc++.h>

namespace {

using List = std::list<int>;

bool solve(int n, std::vector<int> &&b) {
  List medians{b[0]};
  auto current = medians.begin();
  for (int i = 1; i < n; ++i) {
    const int m = b[i];
    if (m != *current) {
      if (m < *current) {
        if (current == medians.begin()) {
          current = medians.insert(current, m);
        } else {
          current--;
          if (m < *current) {
            return false;
          }
          if (*current < m) {
            current = medians.insert(std::next(current), m);
          }
        }
      } else {
        auto next = std::next(current);
        if (next == medians.end()) {
          current = medians.insert(next, m);
        } else {
          current++;
          if (*current < m) {
            return false;
          }
          if (m < *current) {
            current = medians.insert(current, m);
          }
        }
      }
    }
  }
  return true;
}

} // namespace

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    puts(solve(n, std::move(b)) ? "YES" : "NO");
  }
}