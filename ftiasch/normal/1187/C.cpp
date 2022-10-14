#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::pair<int, int>> ns;
  std::vector<bool> leq(n - 1);
  for (int i = 0, t, l, r; i < m; ++i) {
    scanf("%d%d%d", &t, &l, &r);
    l--;
    r--;
    if (t == 1) {
      for (int i = r; i-- > l;) {
        leq[i] = true;
      }
    } else {
      ns.emplace_back(l, r);
    }
  }
  bool ok = true;
  for (auto [l, r] : ns) {
    bool found = false;
    for (int i = r; i-- > l;) {
      found |= !leq[i];
    }
    ok &= found;
  }
  if (ok) {
    puts("YES");
    int up = n;
    for (int i = 0; i < n;) {
      int j = i;
      while (j + 1 < n && leq[j]) {
        j++;
      }
      up -= j - i + 1;
      for (int k = i; k <= j; ++k) {
          printf("%d%c", up + (k - i) + 1, " \n"[k + 1 == n]);
      }
      i = j + 1;
    }
  } else {
    puts("NO");
  }
}