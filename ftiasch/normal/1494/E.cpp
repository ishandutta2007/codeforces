#include <bits/stdc++.h>

int n, q;

int main() {
  scanf("%d%d", &n, &q);
  std::map<std::pair<int, int>, int> edges;
  int pairs = 0, same_pairs = 0;
  for (int i = 0; i < q; ++i) {
    char op[2];
    scanf("%s", op);
    if (*op == '?') {
      int k;
      scanf("%d", &k);
      puts((k % 2 == 1 ? pairs : same_pairs) ? "YES" : "NO");
    } else {
      int u, v;
      char ch[2];
      if (*op == '+') {
        scanf("%d%d%s", &u, &v, ch);
        edges[{u, v}] = *ch;
        int another = edges[{v, u}];
        if (another) {
          pairs++;
          same_pairs += another == *ch;
        }
      } else {
        scanf("%d%d", &u, &v);
        int ch = edges[{u, v}];
        int another = edges[{v, u}];
        if (another) {
          pairs--;
          same_pairs -= another == ch;
        }
        edges[{u, v}] = 0;
      }
    }
  }
}