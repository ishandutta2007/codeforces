#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long llint;
const int mod = 1000000009;
const int off = 1 << 19;

#define MAX 300005

int _f[MAX];
int *f = _f + 1;

int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (llint)a * b % mod; }

int kth_fib(int f1, int f2, int k) {
  return add(mul(f[k - 2], f1), mul(f[k - 1], f2));
}

int kth_sum(int f1, int f2, int k) {
  return add(mul(f[k], f1), mul(add(f[k + 1], mod - 1), f2));
}

struct node {
  int f1, f2;
  int sum;
  node() { f1 = f2 = sum = 0; }
};

node t[off << 1];
int lo, hi;

void push(int n, int l, int mid, int r) {
  node &N = t[n];
  node &L = t[2 * n];
  node &R = t[2 * n + 1];

  L.f1 = add(L.f1, N.f1);
  L.f2 = add(L.f2, N.f2);
  L.sum = add(L.sum, kth_sum(N.f1, N.f2, mid - l));

  int ff1 = kth_fib(N.f1, N.f2, 1 + mid - l);
  int ff2 = kth_fib(N.f1, N.f2, 2 + mid - l);

  R.f1 = add(R.f1, ff1);
  R.f2 = add(R.f2, ff2);
  R.sum = add(R.sum, kth_sum(ff1, ff2, r - mid));

  N.f1 = N.f2 = 0;
}

int query(int l, int r, int n) {
  if (l >= hi || r <= lo) return 0;
  if (l >= lo && r <= hi) return t[n].sum;

  int mid = (l + r) / 2;
  push(n, l, mid, r);

  return add(
    query(l, mid, 2 * n),
    query(mid, r, 2 * n + 1)
  );
}

void update(int l, int r, int n, int f1, int f2) {
  if (l >= hi || r <= lo) return;
  if (l >= lo && r <= hi) {
    t[n].f1 = add(t[n].f1, f1);
    t[n].f2 = add(t[n].f2, f2);
    t[n].sum = add(t[n].sum, kth_sum(f1, f2, r - l));
    return;
  }

  int mid = (l + r) / 2;
  push(n, l, mid, r);

  if (hi <= mid) 
    update(l, mid, 2 * n, f1, f2);
  else if (lo >= mid)
    update(mid, r, 2 * n + 1, f1, f2);
  else {
    update(l, mid, 2 * n, f1, f2);
    int L = max(l, lo);
    int ff1 = kth_fib(f1, f2, 1 + mid - L);
    int ff2 = kth_fib(f1, f2, 2 + mid - L);
    update(mid, r, 2 * n + 1, ff1, ff2);
  }

  t[n].sum = add(t[2 * n].sum, t[2 * n + 1].sum);
}

int query(int l, int r) {
  lo = l; hi = r + 1;
  return query(0, off, 1);
}

void update(int l, int r) {
  lo = l; hi = r + 1;
  return update(0, off, 1, 1, 1);
}

void build(int n) {
  if (n >= off) return;
  build(2 * n);
  build(2 * n + 1);
  t[n].sum = add(t[2 * n].sum, t[2 * n + 1].sum);
}

int N, M;
int type, l, r;

int main(void)
{
  f[-1] = 1;
  for (int i = 1; i < MAX; ++i)
    f[i] = add(f[i - 2], f[i - 1]);

  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; ++i)
    scanf("%d", &t[i + off].sum);

  build(1);

  for (int i = 0; i < M; ++i) {
    scanf("%d%d%d", &type, &l, &r); --l; --r;
    if (type == 1) update(l, r);
    else printf("%d\n", query(l, r));
  }

  return 0;
}