#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>


using namespace std;

const int MaxM = 500010;
const int MaxN = 1010;
int colour[MaxN], comp[MaxN], nc[MaxN];
int nv[MaxN][MaxN];
int aa[MaxM], bb[MaxM], cc[MaxM];
int id[MaxM];
int a[MaxM], b[MaxM], c[MaxM];
int n, m, q;


inline bool cmp(int x, int y) {
  return cc[x] > cc[y];
}


int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &aa[i], &bb[i], &cc[i]);
    aa[i]--; 
    bb[i]--;
    id[i] = i;
  }
  sort(id, id + m, cmp);
  for (int i = 0; i < m; i++) {
    a[i] = aa[id[i]];
    b[i] = bb[id[i]];
    c[i] = cc[id[i]];
  }
  for (int ii = 0; ii < q; ii++) {
    int s, f;
    scanf("%d %d", &s, &f);
    for (int i = 0; i < n; i++) {
      colour[i] = 0;
      comp[i] = i;
      nc[i] = 1;
      nv[i][0] = i;
    }
    s--; 
    f--;
    int ans = -1;
    for (int i = 0; i < m; i++) {
      if (id[i] < s || id[i] > f) {
        continue;
      }
      if (comp[a[i]] == comp[b[i]]) {
        if (colour[a[i]] == colour[b[i]]) {
          ans = c[i];
          break;
        }
      } else {
        int x = comp[a[i]];
        int y = comp[b[i]];
        if (nc[x] < nc[y]) {
          swap(x, y);
        }
        int inv = (colour[a[i]] == colour[b[i]]);
        for (int j = 0; j < nc[y]; j++) {
          int ver = nv[y][j];
          comp[ver] = x;
          colour[ver] ^= inv;
          nv[x][nc[x]++] = ver;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}