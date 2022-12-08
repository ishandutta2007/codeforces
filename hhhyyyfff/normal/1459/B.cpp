#include <bits/stdc++.h>

using namespace std;

int n, ans;

int sqr(int x) { return x * x; }

int main() {
  scanf("%d", &n);
  if (n % 2 == 0)
    printf("%d\n", sqr((n / 2) + 1)); else {
    for (int i = 1, j = 4; i <= n; i += 2, j += 4) ans += j;
    printf("%d\n", ans);
  }
  return 0;
}