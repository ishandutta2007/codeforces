#include <bits/stdc++.h>

using namespace std;

int n, rest = 2500000, a[200010];
int head[5000010], b[10000010][2], cnt[200010], last[2500010];
int c[200010];

bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n && rest >= 0; ++i) rest -= i / 2;
  if (rest >= 0) {
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        ++head[a[i] + a[j] + 1];
    for (int i = 1; i <= 5000000; ++i) head[i] += head[i - 1];
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        b[head[a[i] + a[j]]][0] = i;
        b[head[a[i] + a[j]]][1] = j;
        ++head[a[i] + a[j]];
      }
    for (int i = 1; i <= 5000000; ++i) {
      for (int j = head[i - 1]; j < head[i]; ++j) {
        ++cnt[b[j][0]];
        ++cnt[b[j][1]];
      }
      for (int j = head[i - 1]; j < head[i]; ++j)
        if (cnt[b[j][0]] + cnt[b[j][1]] - 1 != head[i] - head[i - 1]) {
          int x = b[j][0], y = b[j][1];
          for (int k = head[i - 1]; k < head[i]; ++k)
            if (x != b[k][0] && x != b[k][1] && y != b[k][0] && y != b[k][1]) {
              puts("YES");
              printf("%d %d %d %d\n", x + 1, y + 1, b[k][0] + 1, b[k][1] + 1);
              return 0;
            }
          puts("Wrong!");
          return 0;
        }
      for (int j = head[i - 1]; j < head[i]; ++j) {
        cnt[b[j][0]] = 0;
        cnt[b[j][1]] = 0;
      }
    }
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n; ++i) c[i] = i;
  sort(c, c + n, cmp);
  for (int i = 1; i < n; ++i)
    if (!last[a[c[i]] - a[c[i - 1]]])
      last[a[c[i]] - a[c[i - 1]]] = i; else
    if (last[a[c[i]] - a[c[i - 1]]] != i - 1) {
      printf("%d %d %d %d\n", c[last[a[c[i]] - a[c[i - 1]]] - 1] + 1, c[i] + 1,
                              c[i - 1] + 1, c[last[a[c[i]] - a[c[i - 1]]]] + 1);
      return 0;
    }
  puts("Wrong!");
  return 0;
}