#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;

struct Node;

Node *null;

struct Node {
  static Node *smart(Node *l, Node *r) {
    return new Node{std::min(l->minimum, r->minimum), l, r};
  }

  Node *insert(int l, int r, int k, int v) {
    if (k < l || r <= k) {
      return this;
    }
    if (l + 1 == r) {
      return new Node{v, null, null};
    }
    int m = (l + r) >> 1;
    return smart(left->insert(l, m, k, v), right->insert(m, r, k, v));
  }

  // <= k
  int ask(int l, int r, int k) {
    if (k < l) {
      return INT_MAX;
    }
    if (r - 1 <= k) {
      return minimum;
    }
    int m = (l + r) >> 1;
    return std::min(left->ask(l, m, k), right->ask(m, r, k));
  }

  int minimum;
  Node *left, *right;
};

Node *merge(int l, int r, Node *a, Node *b) {
  if (a == null) {
    return b;
  }
  if (b == null) {
    return a;
  }
  if (l + 1 == r) {
    return new Node{std::min(a->minimum, b->minimum), null, null};
  }
  int m = (l + r) >> 1;
  return Node::smart(merge(l, m, a->left, b->left),
                     merge(m, r, a->right, b->right));
}

int root, n, a[N], depth[N];
std::vector<int> tree[N];
Node *sgt[N];

void prepare(int p, int u) {
  depth[u] = ~p ? depth[p] + 1 : 0;
  sgt[u] = null->insert(0, n, depth[u], a[u]);
  for (int v : tree[u]) {
    if (v != p) {
      prepare(u, v);
      sgt[u] = merge(0, n, sgt[u], sgt[v]);
    }
  }
}

int main() {
  null = new Node{INT_MAX, nullptr, nullptr};
  null->left = null->right = null;
  scanf("%d%d", &n, &root);
  root--;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0, x, y; i < n - 1; ++i) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }
  prepare(-1, root);
  int last = 0;
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, k;
    scanf("%d%d", &x, &k);
    x = (x + last) % n;
    k = (k + last) % n;
    last = sgt[x]->ask(0, n, depth[x] + k);
    printf("%d\n", last);
  }
}