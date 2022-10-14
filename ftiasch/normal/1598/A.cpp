#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<char> a(n + 1), b(n + 1);
    scanf("%s%s", a.data(), b.data());
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= a[i] == '0' || b[i] == '0';
    }
    puts(ok ? "YES" : "NO");
  }
}