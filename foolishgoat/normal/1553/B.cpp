#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N], t[N];

void solve() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  for (int st = 0; st < n; ++st) {
    int id = 0;
    for (int r = st; r < n; ++r) {
      if (s[r] != t[id]) {
        break;
      }
      ++id;
      if (id == m) {
        puts("YES");
        return;
      }
      int now = id;
      for (int u = r-1; u >= 0 && id < m; --u) {
        if (s[u] != t[now]) {
          break;
        }
        ++now;
      }
      if (now == m) {
        puts("YES");
        return;
      }
    }
  }
  puts("NO");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}