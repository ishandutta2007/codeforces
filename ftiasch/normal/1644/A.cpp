#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[7];
    scanf("%s", s);
    int pos[6];
    for (int i = 0; i < 6; ++i) {
      pos[std::string{"rRgGbB"}.find(s[i])] = i;
    }
    bool ok = true;
    for (int i = 0; i < 6; i += 2) {
      ok &= pos[i] < pos[i + 1];
    }
    puts(ok ? "YES" : "NO");
  }
}