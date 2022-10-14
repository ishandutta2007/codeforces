#include <bits/stdc++.h>

using std::max;

struct Info {
  int p = 0;            // )
  int q = 0;            // (
  int ppq = 1, spq = 1; // p + q
  int mp = 0;           // prefix -p + q
  int mq = 0;           // suffix p - q
  int mx = 0;

  Info() {}

  Info(char c) {
    if (c == '(') {
      q = mp = 1;
    } else {
      p = mq = 1;
    }
  }

  Info(const Info& other) = default;

  Info(const Info &a, const Info &b) {
    if (a.q >= b.p) {
      p = a.p, q = a.q - b.p + b.q;
    } else {
      p = a.p - a.q + b.p, q = b.q;
    }
    ppq = max(a.ppq, max(a.p + a.q + b.mp, a.p - a.q + b.ppq));
    spq = max(b.spq, max(a.mq + b.p + b.q, a.spq - b.p + b.q));
    mp = max(a.mp, -a.p + a.q + b.mp);
    mq = max(b.mq, a.mq + b.p - b.q);
    mx = max(max(a.mx, b.mx), max(a.spq + b.mp, a.mq + b.ppq));
  }
};

const int N = 100000;

int get_id(int l, int r) { return l + r | l != r; }

char s[N << 1];
Info tree[N << 2];

void build(int l, int r, int k) {
  if (~k && (k < l || r < k)) {
    return;
  }
  int id = get_id(l, r);
  if (l == r) {
    tree[id] = Info(s[l]);
  } else {
    int m = l + r >> 1;
    build(l, m, k);
    build(m + 1, r, k);
    tree[id] = Info(tree[get_id(l, m)], tree[get_id(m + 1, r)]);
  }
}

int main() {
  int n, q;
  while (scanf("%d%d%s", &n, &q, s) == 3) {
    int m = (n - 1 << 1) - 1;
    int root = get_id(0, m);
    build(0, m, -1);
    printf("%d\n", tree[root].mx);
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      l --;
      r --;
      std::swap(s[l], s[r]);
      build(0, m, l);
      build(0, m, r);
      printf("%d\n", tree[root].mx);
    }
  }
}