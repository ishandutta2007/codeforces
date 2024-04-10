#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N], t[N];

void solve() {
  scanf("%s %s", s, t);
  int n = strlen(s), m = strlen(t);
  int rem = n - m;
  if (rem < 0) {
    puts("NO");
    return;
  }
  int i = 0;
  if (rem & 1)
    ++i;
  int j = 0;
  while (i < n && j < m) {
    if (s[i] == t[j]) {
      ++i;
      ++j;
    } else {
      i += 2;
    }
  }
  if (j == m) {
    puts("YES");
  } else {
    puts("NO");
  }
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}