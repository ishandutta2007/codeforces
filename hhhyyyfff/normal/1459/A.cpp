#include <bits/stdc++.h>

using namespace std;

int T, n, r[1000], b[1000], cnt;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    cnt = 0;
    for (int i = 0; i < n; ++i) scanf("%1d", &r[i]);
    for (int i = 0; i < n; ++i) scanf("%1d", &b[i]);
    for (int i = 0; i < n; ++i)
      if (r[i] > b[i])
        ++cnt; else
      if (r[i] < b[i])
        --cnt;
    puts(cnt ? cnt > 0 ? "RED" : "BLUE" : "EQUAL");
  }
  return 0;
}