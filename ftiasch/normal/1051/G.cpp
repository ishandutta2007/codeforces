#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

struct Node;

Node *null;

struct Node {
  int count;
  Long sum0, sum1;

  Node *left, *right;
};

Node *singleton(int l, int r, int k) {
  if (k < l || r < k) {
    return null;
  }
  if (l == r) {
    return new Node{1, k, 0, null, null};
  }
  int m = (l + r) >> 1;
  return new Node{1, k, 0, singleton(l, m, k), singleton(m + 1, r, k)};
}

Node *merge(Node *u, Node *v) {
  if (u == null) {
    return v;
  }
  if (v == null) {
    return u;
  }
  auto left = merge(u->left, v->left);
  auto right = merge(u->right, v->right);
  u->sum1 = left->sum1 + left->sum0 * right->count + right->sum1;
  u->sum0 = left->sum0 + right->sum0;
  u->count = left->count + right->count;
  u->left = left;
  u->right = right;
  return u;
}

const int N = 400'001;

int n, parent[N];
Node *tree[N];

int find(int u) {
  if (parent[u] != u) {
    parent[u] = find(parent[u]);
  }
  return parent[u];
}

Long cost(int r) {
  int l = r - tree[r]->count;
  return tree[r]->sum1 + 1LL * l * tree[r]->sum0;
}

int main() {
  null = new Node{0, 0, 0, nullptr, nullptr};

  scanf("%d", &n);
  std::iota(parent, parent + N, 0);
  std::fill(tree, tree + N, null);

  Long result = 0;
  for (int i = 0, a0, b0; i < n; ++i) {
    scanf("%d%d", &a0, &b0);
    result -= 1LL * a0 * b0;
    int a = find(a0);
    int b = find(a + 1);
    result -= cost(a);
    result -= cost(b);
    tree[b] = merge(merge(tree[a], tree[b]), singleton(1, n, b0));
    parent[a] = b;
    result += cost(b);
    printf("%lld\n", result);
  }
}