#include <bits/stdc++.h>

using namespace std;

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
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}