#include <bits/stdc++.h>

const int N = 300000;
const int M = 1000000;

struct Segment {
  int l, r, w;
};

bool operator<(const Segment &a, const Segment &b) { return a.w < b.w; }

int n, m;
Segment s[N];

struct Node {
  int cover;
  bool full;
};

Node tree[M << 1];

int get_id(int l, int r) { return l + r | (l != r); }

void build(int l, int r) {
  auto &n = tree[get_id(l, r)];
  n = Node{0, false};
  if (l < r) {
    int m = (l + r) >> 1;
    build(l, m);
    build(m + 1, r);
  }
}

template <int delta> void cover(int l, int r, int a, int b) {
  if (b < l || r < a) {
    return;
  }
  auto &n = tree[get_id(l, r)];
  int m = (l + r) >> 1;
  if (a <= l && r <= b) {
    n.cover += delta;
  } else {
    cover<delta>(l, m, a, b);
    cover<delta>(m + 1, r, a, b);
  }
  if (l == r) {
    n.full = n.cover > 0;
  } else {
    n.full = (tree[get_id(l, m)].full && tree[get_id(m + 1, r)].full) ||
             (n.cover > 0);
  }
}

// void debug(int l, int r) {
//     auto& n = tree[get_id(l, r)];
//     if (l < r) {
//         int m = (l + r) >> 1;
//         debug(l, m);
//         debug(m + 1, r);
//     }
// }

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, l, r, w; i < n; ++i) {
    scanf("%d%d%d", &l, &r, &w);
    // 1 2 3 ... m
    //  0 1
    s[i] = Segment{l - 1, r - 2, w};
  }
  std::sort(s, s + n);
  build(0, m - 2);
  int result = 1e6;
  auto &root = tree[get_id(0, m - 2)];
  for (int i = 0, j = 0; i < n; ++i) {
    cover<1>(0, m - 2, s[i].l, s[i].r);
    if (root.full) {
      while (true) {
        cover<-1>(0, m - 2, s[j].l, s[j].r);
        if (root.full) {
          j++;
        } else {
          cover<1>(0, m - 2, s[j].l, s[j].r);
          break;
        }
      }
      result = std::min(result, s[i].w - s[j].w);
    }
  }
  printf("%d\n", result);
}