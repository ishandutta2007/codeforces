#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

struct Node;

Node *null;

struct Node {
  Node *cover(int l, int r, int a, int b, int kk, int bb) {
    if (b < l || r < a) {
      return this;
    }
    if (a <= l && r <= b) {
      return new Node{sum_k + kk, sum_b + bb, left, right};
    }
    int m = (l + r) >> 1;
    return new Node{sum_k, sum_b, left->cover(l, m, a, b, kk, bb),
                    right->cover(m + 1, r, a, b, kk, bb)};
  }

  Long ask(int l, int r, int k) const {
    if (this == null) {
      return 0;
    }
    int m = (l + r) >> 1;
    return sum_k * k + sum_b +
           (k <= m ? left->ask(l, m, k) : right->ask(m + 1, r, k));
  }

  Long sum_k, sum_b;
  Node *left, *right;
};

const int M = 200'001;

int main() {
  null = new Node{0, 0, nullptr, nullptr};
  null->left = null->right = null;
  int n;
  scanf("%d", &n);
  std::vector<Node *> tree(n + 1);
  tree[0] = null;
  for (int i = 1; i <= n; ++i) {
    int x1, x2, y1, a, b, y2;
    scanf("%d%d%d%d%d%d", &x1, &x2, &y1, &a, &b, &y2);
    tree[i] = tree[i - 1]
                  ->cover(0, M, 0, x1, 0, y1)
                  ->cover(0, M, x1 + 1, x2, a, b)
                  ->cover(0, M, x2 + 1, M, 0, y2);
  }
  int q;
  scanf("%d", &q);
  Long last = 0;
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    x = std::min((last + x) % 1'000'000'000, static_cast<Long>(M));
    last = tree[r]->ask(0, M, x) - tree[l - 1]->ask(0, M, x);
    printf("%lld\n", last);
  }
}