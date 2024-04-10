#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <bitset>

using namespace std;

const int BIG = 500;

bitset<50000> fr[(2 * 400005) / BIG + 1], online;
vector<int> ls[50005];
char t[250005];
int a[250005], b[250005];
int deg[50005], who[50005];
int pa[150005], pb[150005];

void add2(int ind, int val) {
  if (ind > 0) {
    fr[ind].set(val);
  } else {
    ls[-ind].push_back(val);
  }
}

void add(int x, int y) {
  add2(who[x], y);
  add2(who[y], x);
}

void rem2(int ind, int val) {
  if (ind > 0) {
    fr[ind].set(val, 0);
  } else {
    ls[-ind].erase(find(ls[-ind].begin(), ls[-ind].end(), val));
  }
}

void rem(int x, int y) {
  rem2(who[x], y);
  rem2(who[y], x);
}

int count(int x) {
  if (who[x] > 0)
    return (fr[who[x]]&online).count();
  int ret = 0;
  x = -who[x];
  for (int i = 0; i < ls[x].size(); ++i)
    if (online.test(ls[x][i])) ++ret;
  return ret;
}

int main() {
  int n, m, q, o;
  scanf("%d%d%d%d", &n, &m, &q, &o);
  for (int i = 0; i < o; ++i) {
    scanf("%d", &a[i]);
    online.set(a[i] - 1);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &pa[i], &pb[i]);
    deg[pa[i] - 1]++; deg[pb[i] - 1]++;
  }
  scanf("\n");
  char c;
  for (int i = 0; i < q; ++i) {
    scanf("%c", &t[i]);
    if (t[i] == 'O') {
      scanf("%d", &a[i]);
    }
    if (t[i] == 'F') {
      scanf("%d", &a[i]);
    }
    if (t[i] == 'A') {
      scanf("%d%d", &a[i], &b[i]);
      deg[a[i] - 1]++; deg[b[i] - 1]++;
    }
    if (t[i] == 'D') {
      scanf("%d%d", &a[i], &b[i]);
    }
    if (t[i] == 'C') {
      scanf("%d", &a[i]);
    }
    scanf("\n");
  }
  int p1 = 1, p2 = 1;
  for (int i = 0; i < n; ++i) {
    if (deg[i] >= BIG)
      who[i] = p1++;
    else {
      who[i] = -p2;
      ++p2;
    }
  }
  for (int i = 0; i < m; ++i) {
    add(pa[i] - 1, pb[i] - 1);
  }
  for (int i = 0; i < q; ++i) {
    if (t[i] == 'O') {
      online.set(a[i] - 1);
    }
    if (t[i] == 'F') {
      online.set(a[i] - 1, 0);
    }
    if (t[i] == 'A') {
      add(a[i] - 1, b[i] - 1);
    }
    if (t[i] == 'D') {
      rem(a[i] - 1, b[i] - 1);
    }
    if (t[i] == 'C') {
      printf("%d\n", count(a[i] - 1));
    }
    scanf("\n");
  }
  return 0;
}