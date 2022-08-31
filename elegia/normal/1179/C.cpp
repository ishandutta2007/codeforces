#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
  int l, r, mx, sum;
  Node *ls, *rs;

  void ch(int k, int x) {
    if (l == r) {
      mx += x;
      sum += x;
      return;
    }
    sum += x;
    (k <= ls->r ? ls : rs)->ch(k, x);
    mx = max(ls->mx + rs->sum, rs->mx);
  }

  int fnd(int v) {
    if (l == r) return l;
    if (rs->mx > v)
      return rs->fnd(v);
    return ls->fnd(v - rs->sum);
  }
};

const int N = 300010, M = 1000010;

int x[N], y[N];

Node* seg;

Node* build(int l, int r) {
  static Node pool[M * 2];
  static Node* ptop = pool;
  Node* p = ptop++;
  p->l = l;
  p->r = r;
  if (l == r)
    return p;
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  seg = build(1, 1000000);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
    seg->ch(x[i], 1);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &y[i]);
    seg->ch(y[i], -1);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int opt, a, b;
    scanf("%d%d%d", &opt, &a, &b);
    if (opt == 1) {
      seg->ch(x[a], -1);
      seg->ch(x[a] = b, 1);
    } else {
      seg->ch(y[a], 1);
      seg->ch(y[a] = b, -1);
    }
    if (seg->mx > 0)
      printf("%d\n", seg->fnd(0));
    else
      puts("-1");
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}