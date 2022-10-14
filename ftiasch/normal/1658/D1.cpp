#include <bits/stdc++.h>

using Prefix = std::pair<int, int>;

void dfs(std::vector<Prefix> &prefixes, int l, int r, int prefix, int length,
         bool is_greater, bool is_less) {
  if (length == 0 || (is_greater && is_less)) {
    prefixes.emplace_back(prefix, length);
  } else {
    length--;
    for (int c = 0; c < 2; ++c) {
      if ((is_greater || (l >> length & 1) <= c) &&
          (is_less || c <= (r >> length & 1))) {
        dfs(prefixes, l, r, prefix | c << length, length,
            is_greater || (l >> length & 1) < c,
            is_less || c < (r >> length & 1));
      }
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int n = r - l + 1;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    std::vector<Prefix> prefixes;
    dfs(prefixes, l, r, 0, 17, false, false);
    auto check = [&](int x) -> bool {
      for (auto [prefix, suflen] : prefixes) {
        int p = (prefix ^ x) & ~((1 << suflen) - 1);
        if (static_cast<int>(
                std::lower_bound(a.begin(), a.end(), p + (1 << suflen)) -
                std::lower_bound(a.begin(), a.end(), p)) != (1 << suflen)) {
          return false;
        }
      }
      return true;
    };
    auto find = [&]() -> int {
      for (int i = 0; i < n; ++i) {
        int x = l ^ a[i];
        if (check(x)) {
          return x;
        }
      }
      return -1;
    };
    printf("%d\n", find());
  }
}