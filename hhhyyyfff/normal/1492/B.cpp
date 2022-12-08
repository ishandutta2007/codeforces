#include <bits/stdc++.h>

using namespace std;

int t, n, p[100010];
bool used[100010];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
    memset(used, 0, sizeof(bool) * (n + 10));
    for (int i = n, cur = n; i >= 1; --i) {
      while (used[cur]) --cur;
      int j = i;
      while (p[j] < cur) --j;
      while (j <= i) {
        printf("%d ", p[j]);
        ++j;
      }
      while (p[i] < cur) used[p[i--]] = 1;
      used[cur] = 1;
    }
    puts("");
  }
  return 0;
}