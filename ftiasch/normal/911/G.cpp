#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Node;

Node *null;

int result[200'000];

struct Node {
  static Node *smart(Node *l, Node *r) {
    if (l == null && r == null) {
      return null;
    }
    return new Node{l, r};
  }

  Node *insert(int l, int r, int k) {
    if (k < l || r <= k) {
      return this;
    }
    if (l + 1 == r) {
      assert(this == null);
      return new Node{null, null};
    }
    auto n = this == null ? new Node{null, null} : this;
    int m = (l + r) >> 1;
    if (k < m) {
      n->left = n->left->insert(l, m, k);
    } else {
      n->right = n->right->insert(m, r, k);
    }
    return n;
  }

  // [l, r) [a, b)
  std::pair<Node *, Node *> extract(int l, int r, int a, int b) {
    if (this == null || b <= l || r <= a) {
      return {null, this};
    }
    if (a <= l && r <= b) {
      return {this, null};
    }
    int m = (l + r) >> 1;
    auto [el, tl] = left->extract(l, m, a, b);
    auto [er, tr] = right->extract(m, r, a, b);
    left = tl;
    right = tr;
    return {smart(el, er), this};
  }

  void traverse(int l, int r, int a) {
    if (this != null) {
      if (l + 1 == r) {
        result[l] = a;
      } else {
        int m = (l + r) >> 1;
        left->traverse(l, m, a);
        right->traverse(m, r, a);
      }
    }
  }

  Node *left, *right;
};

Node *merge(Node *a, Node *b) {
  if (a == null) {
    return b;
  }
  if (b == null) {
    return a;
  }
  a->left = merge(a->left, b->left);
  a->right = merge(a->right, b->right);
  delete b;
  return a;
}

const int A = 101;

Node *occ[A];

int main() {
  null = new Node{nullptr, nullptr};
  null->left = null->right = null;
  int n;
  scanf("%d", &n);
  std::fill(occ, occ + A, null);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    occ[a] = occ[a]->insert(0, n, i);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, x, y;
    scanf("%d%d%d%d", &l, &r, &x, &y);
    l--;
    auto [e, t] = occ[x]->extract(0, n, l, r);
    occ[x] = t;
    occ[y] = merge(occ[y], e);
  }
  for (int a = 0; a < A; ++a) {
    occ[a]->traverse(0, n, a);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == n]);
  }
}