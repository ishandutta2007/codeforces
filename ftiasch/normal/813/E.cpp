#line 1 "sol.cpp"
#include <bits/stdc++.h>

struct Node;

Node *null;

struct Node {
  Node *insert(int l, int r, int k) {
    if (k < l || r < k) {
      return this;
    }
    if (l == r) {
      return new Node{sum + 1, null, null};
    }
    int m = (l + r) >> 1;
    return new Node{sum + 1, left->insert(l, m, k), right->insert(m + 1, r, k)};
  }

  int sum;
  Node *left, *right;
};

int count(Node *u, Node *v, int l, int r, int k) {
  if (r < k) {
    return 0;
  }
  if (k <= l) {
    return u->sum - v->sum;
  }
  int m = (l + r) >> 1;
  return count(u->left, v->left, l, m, k) +
         count(u->right, v->right, m + 1, r, k);
}

int main() {
  null = new Node{0, nullptr, nullptr};
  null->left = null->right = null;
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::map<int, std::vector<int>> indices;
  std::vector<Node *> tree(n + 1);
  tree[n] = null;
  for (int i = n; i--;) {
    auto &indices_a = indices[a[i]];
    int next = k <= indices_a.size() ? indices_a[indices_a.size() - k] : n;
    indices_a.push_back(i);
    tree[i] = tree[i + 1]->insert(0, n, next);
  }
  int q, last = 0;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a = (a + last) % n;
    b = (b + last) % n;
    if (a > b) {
      std::swap(a, b);
    }
    b++;
    // next >= r
    last = count(tree[a], tree[b], 0, n, b);
    printf("%d\n", last);
  }
}