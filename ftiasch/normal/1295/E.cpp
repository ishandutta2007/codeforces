#include <bits/stdc++.h>

const int N = 200000;

int n, p[N], a[N];

struct {
  uint64_t dt, mi;
} tree[N + 1 << 1];

int get_id(int l, int r) { return l + r | l != r; }

void add(int l, int r, int a, int b, int c) {
  int id = get_id(l, r);
  if (b < l || r < a) {
    return;
  }
  if (a <= l && r <= b) {
    tree[id].dt += c;
    tree[id].mi += c;
  } else {
    int m = l + r >> 1;
    add(l, m, a, b, c);
    add(m + 1, r, a, b, c);
    tree[id].mi = std::min(tree[get_id(l, m)].mi, tree[get_id(m + 1, r)].mi) +
                  tree[id].dt;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  uint64_t result = std::numeric_limits<uint64_t>::max();
  for (int i = 0; i < n; ++i) {
    add(0, n + 1, p[i] + 1, n + 1, a[i]);
  }
  for (int i = 0; i + 1 < n; ++i) {
    add(0, n + 1, p[i] + 1, n + 1, -a[i]);
    add(0, n + 1, 0, p[i], a[i]);
    result = std::min(result, tree[get_id(0, n + 1)].mi);
  }
  std::cout << result << std::endl;
}