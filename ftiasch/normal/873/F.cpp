#line 1 "/home/ftiasch/Documents/shoka/sam.h"
#include <cstring>
#include <vector>

template <int C> struct SAM {
  struct Node {
    Node(int length_ = 0) : length(length_), parent(nullptr) {
      memset(go, 0, sizeof(go));
    }

    int length;
    Node *parent, *go[C];
  };

  SAM(int n) : node_count(1), nodes(n << 1) {}

  Node *root() { return nodes.data(); }

  Node *extend(Node *p, int c) {
    Node *np = new (nodes.data() + (node_count++)) Node(p->length + 1);
    while (p && !p->go[c]) {
      p->go[c] = np;
      p = p->parent;
    }
    if (!p) {
      np->parent = root();
    } else {
      Node *q = p->go[c];
      if (p->length + 1 == q->length) {
        np->parent = q;
      } else {
        Node *nq = new (nodes.data() + (node_count++)) Node(p->length + 1);
        memcpy(nq->go, q->go, sizeof(q->go));
        nq->parent = q->parent;
        np->parent = q->parent = nq;
        while (p && p->go[c] == q) {
          p->go[c] = nq;
          p = p->parent;
        }
      }
    }
    return np;
  }

protected:
  int node_count;
  std::vector<Node> nodes;
};
#line 2 "sol.cpp"

#include <bits/stdc++.h>

const int N = 200'000;

int n, count[N + N];
long long result;
char s[N + 1], forbidden[N + 1];
std::vector<int> children[N + N];

struct MySam : public SAM<26> {
  MySam(int n) : SAM(n) {}

  void solve(int i) {
    for (int j : children[i]) {
      solve(j);
      count[i] += count[j];
    }
    result = std::max(result, 1LL * count[i] * nodes[i].length);
  }

  void build() {
    for (int i = 1; i < node_count; ++i) {
      children[nodes[i].parent - root()].push_back(i);
    }
    solve(0);
  }
};

int main() {
  scanf("%d%s%s", &n, s, forbidden);
  MySam sam(n);
  auto p = sam.root();
  for (int i = 0; i < n; ++i) {
    p = sam.extend(p, s[i] - 'a');
    if (forbidden[i] == '0') {
      count[p - sam.root()]++;
    }
  }
  sam.build();
  printf("%lld\n", result);
}