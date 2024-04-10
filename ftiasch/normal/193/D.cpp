#include <bits/stdc++.h>
#include <cstdlib>

struct Entry {
  int m0, c0, c1;
};

Entry merge(const Entry &a, const Entry &b) {
  if (a.m0 > b.m0) {
    return merge(b, a);
  }
  if (a.m0 + 1 < b.m0) {
    return a;
  }
  return a.m0 == b.m0 ? Entry{a.m0, a.c0 + b.c0, a.c1 + b.c1}
                      : Entry{a.m0, a.c0, a.c1 + b.c0};
}

int get_id(int l, int r) { return l + r | l != r; }

const int N = 300000;

int n, a[N + 1], position[N];

struct Node {
  int delta;
  Entry entry;
} tree[N << 1];

void build(int l, int r) {
  tree[get_id(l, r)].entry.c0 = r - l + 1;
  if (l < r) {
    int m = l + r >> 1;
    build(l, m);
    build(m + 1, r);
  }
}

template <int delta> void add(int l, int r, int a, int b) {
  if (b < l || r < a) {
    return;
  }
  auto &node = tree[get_id(l, r)];
  if (a <= l && r <= b) {
    node.delta += delta, node.entry.m0 += delta;
  } else {
    int m = l + r >> 1;
    add<delta>(l, m, a, b);
    add<delta>(m + 1, r, a, b);
    node.entry = merge(tree[get_id(l, m)].entry, tree[get_id(m + 1, r)].entry);
    node.entry.m0 += node.delta;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    position[--a[i]] = i;
  }
  a[n] = n;
  build(0, n - 1);
  add<3>(0, n - 1, 0, n - 1);
  long long result = 0;
  for (int i = 0; i < n; ++i) {
    int j = a[position[i] + 1];
    add<-3>(0, n - 1, i, i);
    if (j < i) {
      add<1>(0, n - 1, j + 1, i);
    } else {
      add<1>(0, n - 1, 0, i);
    }
    if (position[i]) {
      j = a[position[i] - 1];
      if (j < i) {
        add<-1>(0, n - 1, 0, j);
      }
    }
    auto entry = tree[get_id(0, n - 1)].entry;
    if (entry.m0 == 1) {
      result += entry.c0 + entry.c1;
    } else if (entry.m0 == 2) {
      result += entry.c0;
    }
  }
  printf("%lld\n", result - n);
}