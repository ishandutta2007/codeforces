#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int D = 27;
const int V = 1 + N * D;

int size = 1, sum[V], trie[V][2];

int main() {
  int q;
  scanf("%d", &q);
  memset(trie, -1, sizeof(trie));
  while (q--) {
    int t, p;
    scanf("%d%d", &t, &p);
    if (t == 3) {
      int target;
      scanf("%d", &target);
      int result = 0, u = 0;
      for (int i = D; i-- && ~u;) {
        if (target >> i & 1) {
          int c = p >> i & 1;
          if (~trie[u][c]) {
            result += sum[trie[u][c]];
          }
        }
        int c = (target ^ p) >> i & 1;
        u = trie[u][c];
      }
      printf("%d\n", result);
    } else {
      int delta = 3 - 2 * t;
      int u = 0;
      sum[0] += delta;
      for (int i = D; i--;) {
        int c = p >> i & 1;
        if (!~trie[u][c]) {
          trie[u][c] = size++;
        }
        u = trie[u][c];
        sum[u] += delta;
      }
    }
  }
}