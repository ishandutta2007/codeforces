#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdint>
#include <numeric>

struct Edge {
  int from;
  int to;
  int capacity;
  int flow;
  Edge(int from, int to, int capacity, int flow) :
      from(from), to(to), capacity(capacity), flow(flow) {}
};

struct Node {
  static constexpr uint32_t null = uint32_t(-1);
  uint32_t left = null;
  uint32_t right = null;
  uint32_t parent = null;
  int dv;
  int min;
  Node() : dv(0), min(0) {}
  Node(int value) : dv(value), min(0) {}
};

template<class E, bool oriented = false>
struct DynamicTree {
  static int capacity(int v, E* edge) {
    if (edge->from == v) {
      return edge->capacity - edge->flow;
    } else {
      return oriented ? edge->flow : edge->flow + edge->capacity;
    }
  }

  static void setCapacity(int v, E* edge, int cap) {
    if (edge->from == v) {
      edge->flow = edge->capacity - cap;
    } else {
      edge->flow = oriented ? cap : cap - edge->capacity;
    }
  }

  std::vector<E*> parentEdges;
  std::vector<Node> nodes;

  bool isRoot(uint32_t node) {
    uint32_t parent = nodes[node].parent;
    return parent == Node::null || (nodes[parent].left != node && nodes[parent].right != node);
  }

  void fixMin(uint32_t node) {
    int result = 0;
    uint32_t left = nodes[node].left;
    if (left != Node::null) {
      result = std::min(result, nodes[left].min + nodes[left].dv);
    }
    uint32_t right = nodes[node].right;
    if (right != Node::null) {
      result = std::min(result, nodes[right].min + nodes[right].dv);
    }
    nodes[node].min = result;
  }

  void rotate(uint32_t node) {
    uint32_t parent = nodes[node].parent;
    uint32_t middle;
    if (nodes[parent].left == node) {
      middle = nodes[node].right;
      nodes[node].right = parent;
      nodes[parent].left = middle;
    } else {
      middle = nodes[node].left;
      nodes[node].left = parent;
      nodes[parent].right = middle;
    }
    nodes[node].parent = nodes[parent].parent;
    uint32_t grandparent = nodes[node].parent;
    if (grandparent != Node::null) {
      if (nodes[grandparent].left == parent) {
        nodes[grandparent].left = node;
      } else if (nodes[grandparent].right == parent) {
        nodes[grandparent].right = node;
      }
    }
    nodes[parent].parent = node;
    int dNode = nodes[node].dv;
    int dParent = nodes[parent].dv;
    nodes[node].dv += dParent;
    nodes[parent].dv = -dNode;
    if (middle != Node::null) {
      nodes[middle].dv += dNode;
      nodes[middle].parent = parent;
    }
    fixMin(parent);
    fixMin(node);
  }

  void splay(uint32_t node) {
    while (!isRoot(node)) {
      uint32_t parent = nodes[node].parent;
      if (isRoot(parent)) {
        rotate(node);
        return;
      }
      uint32_t grandParent = nodes[parent].parent;
      if ((nodes[parent].left == node) == (nodes[grandParent].left == parent)) {
        rotate(parent);
      } else {
        rotate(node);
      }
      rotate(node);
    }
  }

  uint32_t pathRoot(uint32_t node) {
    while (true) {
      uint32_t right = nodes[node].right;
      if (right == Node::null) return node;
      node = right;
    }
  }

  void expose(uint32_t node) {
    splay(node);
    while (true) {
      uint32_t parent = nodes[node].parent;
      if (parent == Node::null) break;
      splay(parent);
      uint32_t left = nodes[parent].left;
      if (left != Node::null) {
        nodes[left].dv += nodes[parent].dv;
      }
      if (nodes[parent].parent == Node::null && nodes[parent].right == Node::null) {
        nodes[parent].dv = std::numeric_limits<int>::max();
        nodes[parent].min = 0;
      }
      nodes[parent].left = node;
      nodes[node].dv -= nodes[parent].dv;
      // fixMin(parent); // fixed by rotate
      rotate(node);
    }
  }

  uint32_t getRoot(uint32_t node) {
    expose(node);
    return pathRoot(node);
  }

  uint32_t disconnectRoot(uint32_t root) {
    uint32_t newRoot = root;
    if (nodes[newRoot].left == Node::null) {
      newRoot = nodes[newRoot].parent;
    } else {
      newRoot = nodes[newRoot].left;
      while (nodes[newRoot].right != Node::null) {
        newRoot = nodes[newRoot].right;
      }
    }
    splay(newRoot);
    nodes[newRoot].parent = Node::null;
    nodes[newRoot].right = Node::null;
    nodes[root].parent = Node::null;
    nodes[root].dv = std::numeric_limits<int>::max();
    nodes[root].min = 0;
    setCapacity(newRoot, parentEdges[newRoot], nodes[newRoot].dv);
    parentEdges[newRoot] = nullptr;
    if (nodes[newRoot].left != Node::null) {
      nodes[nodes[newRoot].left].dv += nodes[newRoot].dv - std::numeric_limits<int>::max();
    }
    nodes[newRoot].dv = std::numeric_limits<int>::max();
    nodes[newRoot].min = 0;
    return newRoot;
  }

  void disconnectVertex(uint32_t u) {
    splay(u);
    uint32_t v = nodes[u].right;
    nodes[u].right = Node::null;
    nodes[v].dv += nodes[u].dv;
    nodes[v].parent = nodes[u].parent;
    nodes[u].parent = Node::null;

    setCapacity(u, parentEdges[u], nodes[u].dv);
    if (nodes[u].left != Node::null) {
      nodes[nodes[u].left].dv += nodes[u].dv - std::numeric_limits<int>::max();
    }
    nodes[u].dv = std::numeric_limits<int>::max();
    parentEdges[u] = nullptr;
    nodes[u].min = 0;
    if (nodes[v].left == Node::null && nodes[v].right == Node::null) {
      nodes[v].dv = std::numeric_limits<int>::max();
      nodes[v].min = 0;
    }
  }

  void link(uint32_t u, uint32_t v, Edge* edge) {
    splay(u);
    int cap = capacity(u, edge);
    int delta = cap - nodes[u].dv;
    nodes[u].dv = cap;
    if (nodes[u].left != Node::null) {
      nodes[nodes[u].left].dv -= delta;
    }
    fixMin(u);
    parentEdges[u] = edge;
    nodes[u].parent = v;
  }

  int getPathMin(uint32_t u) {
    splay(u);
    return nodes[u].min + nodes[u].dv;
  }

  void subtractPath(uint32_t u, int value) {
    splay(u);
    nodes[u].dv -= value;
    if (nodes[u].left != Node::null) {
      nodes[nodes[u].left].dv += value;
    }
    fixMin(u);
  }

  uint32_t findNonZeroPath(uint32_t u) {
    splay(u);
    int delta = nodes[u].dv;
    if (delta == 0) return u;
    uint32_t check = nodes[u].right;
    while (true) {
      delta += nodes[check].dv;
      uint32_t left = nodes[check].left;
      if (left == Node::null || delta + nodes[left].dv + nodes[left].min > 0) {
        if (delta == 0) {
          return check;
        }
        check = nodes[check].right;
        continue;
      }
      check = left;
    }
  }

  void destroy(uint32_t v, int value) {
    value += nodes[v].dv;
    if (parentEdges[v] != nullptr) {
      setCapacity(v, parentEdges[v], value);
      parentEdges[v] = nullptr;
    }
    if (nodes[v].left != Node::null) {
      destroy(nodes[v].left, value);
    }
    if (nodes[v].right != Node::null) {
      destroy(nodes[v].right, value);
    }
  }

  void destroyAll() {
    for (uint32_t i = 0; i < nodes.size(); i++) {
      if (isRoot(i)) {
        destroy(i, 0);
      }
    }
  }

};

template<class E, bool oriented = false>
struct Flow2 {
  std::vector<std::vector<E*>>* pGraph;
  int vFrom;
  int vTo;
  int n;
  std::vector<int> queue;
  std::vector<int> ranks;
  std::vector<int> edgeIdx;
  DynamicTree<E, oriented> tree;

  static int capacity(int v, E* edge) {
    if (edge->from == v) {
      return edge->capacity - edge->flow;
    } else {
      return oriented ? edge->flow : edge->flow + edge->capacity;
    }
  }

  static int other(int v, E* edge) {
    return edge->from ^ edge->to ^ v;
  }

  void calcRanks() {
    std::fill(ranks.begin(), ranks.end(), -1);
    int bque = 0;
    int eque = 1;
    queue[0] = vFrom;
    ranks[vFrom] = 0;
    while (eque > bque) {
      int v = queue[bque];
      bque++;
      int nr = ranks[v] + 1;
      for (auto edge : (*pGraph)[v]) {
        if (capacity(v, edge) > 0) {
          int other = edge->from + edge->to - v;
          if (ranks[other] < 0) {
            queue[eque] = other;
            eque++;
            ranks[other] = nr;
          }
        }
      }
      if (v == vTo) {
        break;
      }
    }
  }

  bool calcFlow() {
    bool found = false;
    auto& graph = *pGraph;
    int root = vFrom;
    while (root != vFrom || edgeIdx[root] != graph[root].size()) {
      if (root == vTo) {
        int cap = tree.getPathMin(vFrom);
        if (cap > 0) {
          tree.subtractPath(vFrom, cap);
          found = true;
        }
        root = tree.findNonZeroPath(vFrom);
        tree.disconnectVertex(root);
        continue;
      }
      if (edgeIdx[root] == graph[root].size()) {
        ranks[root] = -1;
      }
      if (ranks[root] < 0) {
        root = tree.disconnectRoot(root);
        continue;
      }
      auto edge = graph[root][edgeIdx[root]];
      int next = other(root, edge);
      if (ranks[next] != ranks[root] + 1) {
        edgeIdx[root]++;
        continue;
      }
      if (capacity(root, edge) == 0) {
        edgeIdx[root]++;
        continue;
      }
      tree.link(root, next, edge);
      root = tree.getRoot(root);
    }
    tree.destroyAll();
    return found;
  }

  void solve(std::vector<std::vector<E*>>& graph, int from, int to, bool clear = true) {
    pGraph = &graph;
    vFrom = from;
    vTo = to;
    if (clear) {
      for (auto& vArray : graph) {
        for (auto& edge : vArray) {
          edge->flow = 0;
        }
      }
    }
    n = graph.size();
    queue.resize(n);
    ranks.resize(n);
    edgeIdx.resize(n);
    for (int i = 0; i < n; i++) {
      calcRanks();
      std::fill(edgeIdx.begin(), edgeIdx.end(), 0);
      tree.parentEdges.assign(n, nullptr);
      tree.nodes.assign(n, Node(std::numeric_limits<int>::max()));
      if (!calcFlow()) {
        break;
      }
    }
  }
};

void clearGraph(std::vector<std::vector<Edge*>>& graph) {
  for (size_t v = 0; v < graph.size(); v++) {
    auto& edges = graph[v];
    auto it = std::partition(edges.begin(), edges.end(), [v](Edge* e) { return e->from == v; });
    edges.erase(it, edges.end());
  }
  for (size_t v = 0; v < graph.size(); v++) {
    for (Edge* edge : graph[v]) {
      delete edge;
    }
  }
  graph.clear();
}

struct Solution {
  int n, k;
  std::vector<int> ps;
  std::vector<int> cs;
  std::vector<int> ls;
  std::vector<uint8_t> isprime;

  void init() {
    isprime.assign(200001, 1);
    for (int i = 2; i * i < isprime.size(); i++) {
      if (isprime[i]) {
        for (int j = i * i; j < isprime.size(); j += i) {
          isprime[j] = 0;
        }
      }
    }
    isprime[1] = 0;
  }
  std::vector<int> left;
  std::vector<int> leftC;
  std::vector<int> right;
  std::vector<int> rightC;
  int s;
  int t;

  std::vector<std::vector<Edge*>> buildGraph(int level) {
    std::vector<std::vector<Edge*>> graph;
    left.clear();
    leftC.clear();
    for (int i = 0; i < n; i++) {
      if (ls[i] <= level && cs[i] % 2 == 0) {
        left.push_back(ps[i]);
        leftC.push_back(cs[i]);
      }
    }
    right.clear();
    rightC.clear();
    int max1 = 0;
    for (int i = 0; i < n; i++) {
      if (ls[i] <= level && cs[i] % 2 == 1) {
        if (cs[i] > 1) {
          right.push_back(ps[i]);
          rightC.push_back(cs[i]);
        }
        else {
          max1 = std::max(max1, ps[i]);
        }
      }
    }
    if (max1 > 0) {
      right.push_back(max1);
      rightC.push_back(1);
    }
    s = left.size() + right.size();
    t = s + 1;
    graph.resize(t + 2);
    for (int i = 0; i < left.size(); i++) {
      Edge* edge = new Edge(s, i, left[i], 0);
      graph[s].push_back(edge);
      graph[i].push_back(edge);
    }
    for (int i = 0; i < right.size(); i++) {
      Edge* edge = new Edge(i + left.size(), t, right[i], 0);
      graph[t].push_back(edge);
      graph[i + left.size()].push_back(edge);
    }

    for (size_t i = 0; i < left.size(); i++) {
      for (size_t j = 0; j < right.size(); j++) {
        if (isprime[leftC[i] + rightC[j]] == 1) {
          Edge* edge = new Edge(i, j + left.size(), 100000, 0);
          graph[i].push_back(edge);
          graph[j + left.size()].push_back(edge);
        }
      }
    }
    return graph;
  }

  bool isGood(int level) {
    auto graph = buildGraph(level);
    int total = std::accumulate(left.begin(), left.end(), 0) + std::accumulate(right.begin(), right.end(), 0);
    Flow2<Edge, true> flow;
    flow.solve(graph, s, t);
    for (Edge* edge : graph[s]) {
      total -= edge->flow;
    }
    clearGraph(graph);
    return total >= k;
  }

  void run(std::istream &in, std::ostream &out) {
    in >> n >> k;
    ps.resize(n);
    cs.resize(n);
    ls.resize(n);
    for (int i = 0; i < n; i++) {
      in >> ps[i] >> cs[i] >> ls[i];
    }
    init();
    int left = 0;
    int right = n + 1;
    while (right - left > 1) {
      int middle = (right + left) / 2;
      if (isGood(middle)) {
        right = middle;
      }
      else {
        left = middle;
      }
    }
    if (right > n) {
      out << -1 << std::endl;
    }
    else {
      out << right << std::endl;
    }

  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}