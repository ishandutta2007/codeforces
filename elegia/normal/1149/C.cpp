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

struct Data {
  int l, r, lm, rm, Lm, Rm, mm, m;

  Data(int l = 0, int r = 0) : l(l), r(r), lm(max(l, 0)), rm(max(r, 0)), Lm(1), Rm(1), mm(1), m(1) {}

  Data(int l, int r, int lm, int rm, int Lm, int Rm, int mm, int m) : l(l), r(r), lm(lm), rm(rm), Lm(Lm), Rm(Rm), mm(mm), m(m) {}

  Data operator+(const Data& rhs) const {
    int _l = l + rhs.l, _r = r + rhs.r, _lm = max(lm, l + rhs.lm), _rm = max(rm + rhs.r, rhs.rm),
            _Lm = max({rhs.Lm, rhs.mm + rm, Lm + rhs.l}), _Rm = max({Rm, mm + rhs.lm, rhs.Rm + r}),
            _mm = max(mm + rhs.l, r + rhs.mm), _m = max({m, rhs.m, Lm + rhs.lm, rm + rhs.Rm});
    return Data(_l, _r, _lm, _rm, _Lm, _Rm, _mm, _m);
  }
};

struct Node {
  int l, r;
  Data v;
  Node *ls, *rs;

  void ch(int k, const Data& d) {
    if (l == r) {
      v = d;
      return;
    }
    (k <= ls->r ? ls : rs)->ch(k, d);
    v = ls->v + rs->v;
  }
};

const int N = 200010;

int n;
char s[N];

Node* build(int l, int r) {
  static Node pool[N * 2], *ptop = pool;
  Node* p = ptop;
  ++ptop;
  p->l = l;
  p->r = r;
  if (l == r) {
    p->v = s[l] == '(' ? Data(1, -1) : Data(-1, 1);
    return p;
  }
  int mid = (l + r) >> 1;
  p->ls = build(l, mid);
  p->rs = build(mid + 1, r);
  p->v = p->ls->v + p->rs->v;
  //LOG("%d %d: (l %d, r %d, lm %d, rm %d, Lm %d, Rm %d, mm %d, m %d)\n", l, r, p->v.l, p->v.r, p->v.lm, p->v.rm, p->v.Lm, p->v.Rm, p->v.mm, p->v.m);
  return p;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int q;
  scanf("%d%d%s", &n, &q, s + 1);
  n = 2 * (n - 1);
  Node* seg = build(1, n);
  printf("%d\n", seg->v.m);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (s[x] != s[y]) {
      if (s[x] == ')')
        swap(x, y);
      s[x] = ')';
      s[y] = '(';
      seg->ch(x, Data(-1, 1));
      seg->ch(y, Data(1, -1));
    }
    printf("%d\n", seg->v.m);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}