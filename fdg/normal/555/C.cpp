#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct item {
  int l, r, addl, addu;
};

bool operator < (const item &a, const item &b) {
  return a.l < b.l || a.l == b.l && a.r < b.r;
}

set<item> f;

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  f.insert({1, n, 0, 0});
  while (m--) {
    int x, y; char c;
    scanf("%d %d %c\n", &x, &y, &c);

    if (f.size() == 0) {
      puts("0");
      continue;
    }

    auto it = f.lower_bound(item{x + 1, -1, -1, -1});

    if (it == f.begin()) {
      puts("0");
      continue;
    }
    --it;

    if (it->l > x || it->r < x) {
      printf("0\n");
      continue;
    }

    item cur = *it;
    f.erase(it);
    // cout << x << "  " << y << " " << c << endl;
    // cout << cur.l << " " << cur.r << "  " << cur.addl << " " << cur.addu << endl;
    if (c == 'L') {
      printf("%d\n", x - cur.l + 1 + cur.addl);

      if (cur.l <= x - 1)
        f.insert(item{cur.l, x - 1, cur.addl, 0});
      if (x + 1 <= cur.r)
        f.insert(item{x + 1, cur.r, cur.addl + (x - cur.l + 1), cur.addu});
    } else {
      printf("%d\n", cur.r - x + 1 + cur.addu);

      if (cur.l <= x - 1)
        f.insert(item{cur.l, x - 1, cur.addl, cur.addu + (cur.r - x + 1)});
      if (x + 1 <= cur.r)
        f.insert(item{x + 1, cur.r, 0, cur.addu});
    }
    // break;
  }
  return 0;
}