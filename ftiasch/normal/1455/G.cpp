// #include "debug.h"

#include <bits/stdc++.h>

using Long = long long;

const Long INF = 200'000'000'000'001;

struct Node;

Node *null;

struct Node {
  static Node *leaf() { return new Node{0, INF, nullptr, nullptr}; }

  Node *insert(int l, int r, int k, Long v) {
    if (l + 1 == r) {
      if (this == null) {
        return new Node{v, v, null, null};
      }
      delta = minimum = v;
      return this;
    } else {
      Node *n;
      if (this == null) {
        n = new Node{0LL, INF, null, null};
      } else {
        n = propagate();
      }
      int m = (l + r) >> 1;
      if (k < m) {
        n->left = n->left->insert(l, m, k, v);
      } else {
        n->right = n->right->insert(m, r, k, v);
      }
      return n->collect();
    }
  }

  Long get(int l, int r, int k) const {
    if (l + 1 == r) {
      return minimum;
    }
    int m = (l + r) >> 1;
    return (k < m ? left->get(l, m, k) : right->get(m, r, k)) + delta;
  }

  void add(Long v) {
    if (this != null) {
      delta += v;
      minimum += v;
    }
  }

  Node *propagate() {
    left->add(delta);
    right->add(delta);
    delta = 0;
    return this;
  }

  Node *collect() {
    assert(delta == 0);
    minimum = std::min(left->minimum, right->minimum); // + delta?
    return this;
  }

  void print(std::ostream &out, int l, int r) const {
    out << "[" << l << ", " << r << ") delta=" << delta
        << " minimum=" << minimum << std::endl;
    if (l + 1 < r) {
      int m = (l + r) >> 1;
      left->print(out, l, m);
      right->print(out, m, r);
    }
  }

  Long delta, minimum;
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
    Long v = std::min(a->minimum, b->minimum);
    a->delta = a->minimum = v;
    return a;
  } else {
    a->propagate();
    b->propagate();
    int m = (l + r) >> 1;
    a->left = merge(l, m, a->left, b->left);
    a->right = merge(m, r, a->right, b->right);
    return a->collect();
  }
}

struct Op {
  char code;
  int value, cost;
};

struct IfBlk {
  int value;
  Node *root;
};

int main() {
  null = new Node{0LL, INF, nullptr, nullptr};
  null->left = null->right = null;
  int q, fvalue;
  scanf("%d%d", &q, &fvalue);
  std::vector<int> values{0};
  values.reserve(q + 1);
  std::vector<Op> ops(q);
  for (int i = 0; i < q; ++i) {
    char buffer[4];
    scanf("%s", buffer);
    auto &op = ops[i];
    op.code = *buffer;
    op.value = -1;
    if (op.code != 'e') {
      int value;
      scanf("%d", &value);
      if (value != fvalue) {
        values.push_back(op.value = value);
      }
    }
    if (op.code == 's') {
      scanf("%d", &op.cost);
    }
  }
  std::sort(values.begin(), values.end());
  values.erase(std::unique(values.begin(), values.end()), values.end());
  for (auto &op : ops) {
    if (~op.value) {
      op.value = std::lower_bound(values.begin(), values.end(), op.value) -
                 values.begin();
    }
  }
  assert(values[0] == 0);
  int m = values.size();
  std::vector<IfBlk> stack{IfBlk{0, null->insert(0, m, 0, 0)}};
  // stack.back().root->print(std::cout, 0, m);
  for (auto &&op : ops) {
    int x = op.value;
    // std::cout << KV(op.code) << KV(op.value) << KV(op.cost) << std::endl;
    switch (op.code) {
    case 's': {
      Node *&n = stack.back().root;
      Long pre_min = n->minimum;
      n->add(op.cost);
      if (x != -1) {
        n = n->insert(0, m, x, pre_min);
      }
      break;
    }
    case 'i': {
      stack.push_back(x == -1 ? IfBlk{-1, null}
                              : IfBlk{x, null->insert(0, m, x, 0)});
      break;
    }
    case 'e': {
      auto back = stack.back();
      stack.pop_back();
      Node *&n = stack.back().root;
      Node *&nn = back.root;
      int y = back.value;
      if (y != -1) {
        Long pre = n->get(0, m, y);
        if (pre < INF) {
          n = n->insert(0, m, y, INF);
          nn->add(pre);
          n = merge(0, m, n, nn);
        }
      }
      break;
    }
    }
  }
  assert(static_cast<int>(stack.size()) == 1);
  printf("%lld\n", stack[0].root->minimum);
}