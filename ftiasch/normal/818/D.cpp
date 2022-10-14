#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, a;
  scanf("%d%d", &n, &a);
  std::vector<int> indices_a;
  std::map<int, std::vector<int>> indices;
  for (int i = 0, c; i < n; ++i) {
    scanf("%d", &c);
    if (c == a) {
      indices_a.push_back(i);
    } else {
      indices[c].push_back(i);
    }
  }
  auto count = [&](int l, int r) -> int {
    return std::lower_bound(indices_a.begin(), indices_a.end(), r) -
           std::upper_bound(indices_a.begin(), indices_a.end(), l);
  };

  auto find = [&]() -> int {
    for (auto &&[b, indices_b] : indices) {
      int last = -1, cnt_a = 0, cnt_b = 0;
      bool ok = true;
      for (int i : indices_b) {
        cnt_a += count(last, i);
        ok &= cnt_a <= cnt_b;
        cnt_b++;
        last = i;
      }
      cnt_a += count(last, n);
      ok &= cnt_a <= cnt_b;
      if (ok) {
        return b;
      }
    }
    return -1;
  };
  printf("%d\n", find());
}