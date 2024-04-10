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

const int N = 100010;

struct Node {
  int l, r;
  int mul, ad;
  union {
    struct { Node *ls, *rs; };
    Node* ch[2];
  };

  void apply(int mul, int ad) {
    this->ad = this->ad * mul + ad;
    this->mul *= mul;
  }

  void pd() {
    for (int i = 0; i < 2; ++i)
      ch[i]->apply(mul, ad);
    mul = 1;
    ad = 0;
  }

  void modify(int l, int r, int mul, int ad) {
    if (this->l == l && this->r == r) {
      apply(mul, ad);
      return;
    }
    pd();
    if (r <= ls->r)
      ls->modify(l, r, mul, ad);
    else if (l >= rs->l)
      rs->modify(l, r, mul, ad);
    else {
      ls->modify(l, ls->r, mul, ad);
      rs->modify(rs->l, r, mul, ad);
    }
  }

  int qry(int k) {
    if (l == r)
      return mul + ad;
    pd();
    return k <= ls->r ? ls->qry(k) : rs->qry(k);
  }
};

int n;
int a[N];
Node* seg;

Node* build(int l, int r) {
  static Node pool[N * 4], *ptop = pool;
  Node* p = ptop++;
  p->l = l;
  p->r = r;
  p->mul = 1;
  p->ad = 0;
  if (l == r) {
    if (r < 0)
      p->mul = -1;
    return p;
  }
  int mid = (l + r) >> 1;
  if ((l + r) < 0)
    mid = (l + r - 1) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  seg = build(-100001, 100001);
  while (q--) {
    char c;
    int x;
    scanf(" %c%d", &c, &x);
    if (c == '>') {
      if (x < 0) {
        seg->modify(-100001, x, 0, -1);
        seg->modify(-x, 100001, 0, -1);
        seg->modify(x + 1, -x - 1, -1, 0);
      } else {
        seg->modify(-100001, -x - 1, 0, -1);
        seg->modify(x + 1, 100001, 0, -1);
      }
    } else {
      if (x > 0) {
        seg->modify(-100001, -x, 0, 1);
        seg->modify(x, 100001, 0, 1);
        seg->modify(-x + 1, x - 1, -1, 0);
      } else {
        seg->modify(-100001, x - 1, 0, 1);
        seg->modify(-x + 1, 100001, 0, 1);
      }
    }
  }

  for (int i = 1; i <= n; ++i)
    printf("%d ", abs(a[i]) * seg->qry(a[i]));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}