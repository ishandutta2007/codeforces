#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> queue(n), depth(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &queue[i]);
    }
    depth[0] = 0;
    for (int head = 0, tail = 1; head < tail; ++head) {
      int du = depth[head];
      int pre = 0;
      while (tail < n && pre < queue[tail]) {
        depth[tail] = du + 1;
        pre = queue[tail++];
      }
    }
    printf("%d\n", depth[n - 1]);
  }
}