#include <bits/stdc++.h>

struct Node;

static Node *zero;

struct Node {
  Node(int s, const Node *l, const Node *r) : sum(s), left(l), right(r) {}

  Node(const Node *l, const Node *r) : Node(l->sum + r->sum, l, r) {}

  const Node *clear(int m, int r) const {
    if (m--) {
      return (r <= left->sum) ? new Node(left->clear(m, r), right)
                              : new Node(left, right->clear(m, r - left->sum));
    } else {
      return zero;
    }
  }

  int ask(int m, int k) const {
    if (m--) {
      return (k < (1 << m)) ? left->ask(m, k) : left->sum + right->ask(m, k - (1 << m));
    } else {
      return sum;
    }
  }

  int sum;
  const Node *left, *right;
};

const int MOD = 1e9 + 1;

int main() {
  zero = new Node(0, nullptr, nullptr);
  zero->left = zero->right = zero;
  const Node *root = new Node{1, zero, zero};
  const int M = 30;
  for (int i = 0; i < M; ++i) {
    root = new Node(root, root);
  }
  int n;
  scanf("%d", &n);
  const int offset = -n;
  int delta = n + 1;
  int last_result = 0;
  for (int _ = 0; _ < n; ++_) {
    int t;
    scanf("%d", &t);
    t += delta;
    root = root->clear(M, t);
    root = root->clear(M, t);
    delta--;
    int k;
    scanf("%d", &k);
    while (k--) {
      int x;
      scanf("%d", &x);
      x += last_result;
      if (x >= MOD) {
        x -= MOD;
      }
      last_result = root->ask(M, x - offset) - delta;
      printf("%d\n", last_result);
    }
  }
}