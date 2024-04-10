#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100;

int n, a[N], l[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::vector<int> v;
    for (int i = 0; i < n; ++i) {
      scanf("%d", l + i);
      if (l[i] == 0) {
        v.push_back(a[i]);
      }
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int i = 0, cnt = 0; i < n; ++i) {
      if (l[i] == 0) {
        a[i] = v[cnt++];
      }
    }
    for (int i = 0; i < n; ++i) {
      printf("%d%c", a[i], " \n"[i + 1 == n]);
    }
  }
}