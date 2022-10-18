#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[200005];
long long y[200005];

bool cw(int i, int j, int k) {
  return (x[j] - x[i]) * (y[k] - y[i]) - (y[j] - y[i]) * (x[k] - x[i]) < 0;
}

int up[19][200005];

int lenToRoot(int a) {
  int ret = 0;
  for (int i = 18; i >= 0; --i) {
    if (up[i][a] != -1) {
      ret += 1<<i;
      a = up[i][a];
    }
  }
  return ret;
}

int goUp(int a, int len) {
  for (int i = 18; i >= 0; --i) {
    if ((1<<i) <= len) {
      len -= (1<<i);
      a = up[i][a];
    }
  }
  return a;
}

int lca(int a, int b) {
  int la = lenToRoot(a), lb = lenToRoot(b);
  // cout << "L: " << la << "  " << lb << endl;
  if (la < lb) {
    swap(a, b);
    swap(la, lb);
  }
  a = goUp(a, la - lb);
  la = lb;
  for (int i = 18; i >= 0; --i) {
    if (la >= (1<<i)) {
      if (up[i][a] != up[i][b]) {
        la -= (1<<i);
        a = up[i][a]; b = up[i][b];
      }
    }
  }
  if (a == b) return a;
  return up[0][a];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%lld", &x[i], &y[i]);
  }

  memset(up, -1, sizeof(up));
  for (int i = n - 2; i >= 0; --i) {
    up[0][i] = i + 1;
    while (true) {
      int k = up[0][i], j = up[0][k];
      if (k != -1 && j != -1 && cw(i, j, k)) up[0][i] = j;
      else break;
    }
    // cout << i << "  " << up[0][i] << endl;
  }

  for (int i = 1; i < 19; ++i) {
    for (int j = 0; j < n; ++j) {
      if (up[i - 1][j] != - 1)
        up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }

  int q, a, b;
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &a, &b); --a; --b;
    printf("%d ", lca(a, b) + 1);
  }
  printf("\n");
  return 0;
}