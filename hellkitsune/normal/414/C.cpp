#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, nn;
int a[1 << 21];
PII b[1 << 21];
int t[1 << 21] = {};
LL inv[25], inv2[25];

int sum(int r) {
  int ret = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1)
    ret += t[r];
  return ret;
}

void add(int i, int inc) {
  for (; i < nn; i = (i | (i + 1)))
    t[i] += inc;
}

int sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

int main() {
  scanf("%d", &n);
  nn = 1 << n;
  REP(i, nn)
    scanf("%d", a + i);
  REP(i, nn)
    b[i] = mp(a[i], i);
  sort(b, b + nn);
  a[b[0].second] = 1;
  for (int i = 1; i < nn; ++i)
    if (b[i].first == b[i - 1].first)
      a[b[i].second] = a[b[i - 1].second];
    else
      a[b[i].second] = a[b[i - 1].second] + 1;
  inv[0] = inv2[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (nn >> i); ++j) {
      int pos = j * ((int)1 << i);
      int cnt = ((int)1 << (i - 1));
      REP(tt, cnt)
        add(a[pos + cnt + tt] - 1, 1);
      REP(tt, cnt)
        inv[i] += sum(a[pos + tt] - 2);
      REP(tt, cnt)
        add(a[pos + cnt + tt] - 1, -1);

      REP(tt, cnt)
        add(a[pos + tt] - 1, 1);
      REP(tt, cnt)
        inv2[i] += sum(a[pos + cnt + tt] - 2);
      REP(tt, cnt)
        add(a[pos + tt] - 1, -1);
    }
  }
  LL invs = 0;
  for (int i = 1; i <= n; ++i)
    invs += inv[i];
  int q;
  scanf("%d", &q);
  bool invt[25];
  REP(i, n + 1)
    invt[i] = false;
  REP(i, q) {
    int j;
    scanf("%d", &j);
    for (int x = 1; x <= j; ++x) {
      if (invt[x])
        invs += inv[x] - inv2[x];
      else
        invs += inv2[x] - inv[x];
      invt[x] = !invt[x];
    }
    printf("%I64d\n", invs);
  }
  return 0;
}