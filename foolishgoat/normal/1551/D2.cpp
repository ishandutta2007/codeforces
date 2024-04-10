#include <bits/stdc++.h>

using namespace std;

char s[121][121];

void solve() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int hor = 0, ver = 0, tot = n * m / 2;
  if (n & 1) {
    hor = m / 2;
  }
  if (m & 1) {
    ver = n / 2;
  }
  if (((hor-k) & 1) || hor > k || k > tot - ver) {
    puts("NO");
    return;
  }
  puts("YES");
  if (n & 1) {
    for (int i = 0; i < m; i += 2) {
      s[n-1][i] = s[n-1][i+1] = 'a' + ((i/2) & 1);
    }
  }
  if (m & 1) {
    for (int i = 0; i < n; i += 2) {
      s[i][m-1] = s[i+1][m-1] = 'a' + ((i/2) & 1);
    }
  }
  int need = (k - hor)/2;
  for (int i = 0; i + 1 < n; i += 2) {
    for (int j = 0; j + 1 < m; j += 2) {
      int add = 0;
      if (((i+j)/2) & 1) {
        add += 2;
      }
      if (need > 0) {
        s[i][j] = s[i][j+1] = 'c' + add;
        s[i+1][j] = s[i+1][j+1] = 'd' + add;
        --need;
      } else {
        s[i][j] = s[i+1][j] = 'c' + add;
        s[i][j+1] = s[i+1][j+1] = 'd' + add;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    s[i][m] = 0;
    printf("%s\n", s[i]);
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