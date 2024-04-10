#line 1 "/home/ftiasch/Documents/shoka/sam.h"
#include <cstring>
#include <vector>

namespace sam_details {

struct EmptyNode {};

} // namespace sam_details

template <int C, typename BaseNode = sam_details::EmptyNode> struct SAM {
  struct Node : BaseNode {
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

struct Node {
  bool visited = false;
  long long sum_c = 0;
  std::vector<int> children;
};

const int C = 26;

struct MySAM : public SAM<C, Node> {
  MySAM(int sum_length) : SAM(sum_length) {}

  void add(const std::string &s, int c) {
    auto p = root();
    for (int i = 0; i < s.size(); ++i) {
      p = extend(p, s[i] - 'a');
      p->sum_c += c;
    }
  }

  void prepare(int u) {
    for (auto &&v : nodes[u].children) {
      //   std::cout << u << "->" << v << std::endl;
      prepare(v);
      nodes[u].sum_c += nodes[v].sum_c;
    }
  }

  long long dfs(Node *u) {
    long long result = 0;
    if (!u->visited) {
      u->visited = true;
      result = std::max(result, u->sum_c * u->length);
      for (int c = 0; c < C; ++c) {
        Node *v = u->go[c];
        if (v) {
          result = std::max(result, dfs(v));
        }
      }
    }
    return result;
  }

  long long solve() {
    for (auto &&n : nodes) {
      if (n.parent) {
        n.parent->children.push_back(&n - nodes.data());
      }
    }
    prepare(0);
    return dfs(root());
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  int sum_length = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    sum_length += s[i].length();
  }
  std::vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
  }
  MySAM sam(sum_length);
  for (int i = 0; i < n; ++i) {
    sam.add(s[i], c[i]);
  }
  std::cout << sam.solve() << std::endl;
}