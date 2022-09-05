#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <forward_list>
#include <memory>
#include <queue>

struct BinInvTree {
  size_t size;
  std::vector<std::forward_list<int>> t;
  std::vector<bool> flags;

  BinInvTree(size_t N) :
      size(N),
      t(2 * N) { }

  void add(size_t l, size_t r) {
    int id = flags.size();
    flags.push_back(true);
    l += size;
    r += size;
    while (l < r) {
      if (l & 1) {
        t[l].push_front(id);
        l++;
      }
      if (r & 1) {
        r--;
        t[r].push_front(id);
      }
      l /= 2;
      r /= 2;
    }
  }

  std::vector<int> query(size_t p) {
    std::vector<int> res;
    p += size;
    while (p > 0) {
      for (int elem : t[p]) {
        if (flags[elem]) {
          flags[elem] = false;
          res.push_back(elem);
        }
      }
      t[p].clear();
      p = p / 2;
    }
    return res;
  }
};

struct BinCountTree {
  using T = int;
  size_t size;
  std::vector<T> t;

  BinCountTree(size_t N) :
      size(N),
      t(2 * N) {
    std::iota(t.begin() + N, t.begin() + 2 * N, 0);
    for (size_t i = N; i-- > 1; ) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  T get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p) {
    p += size;
    if (t[p] == -1) {
      return;
    }
    t[p] = -1;
    while (p > 1) {
      p = p / 2;
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  T query(size_t l, size_t r) {
    l += size;
    r += size;
    T left = init();
    T right = init();
    while (l < r) {
      if (l & 1) {
        left = combine(left, t[l]);
        l++;
      }
      if (r & 1) {
        r--;
        right = combine(t[r], right);
      }
      l = l / 2;
      r = r / 2;
    }
    return combine(left, right);
  }

 private:
  T combine(T left, T right) {
    if (left == -1) {
      return right;
    }
    return left;
  }

  T init() {
    return -1;
  }
};

struct HeapElem {
  int64_t dist;
  int from;
  int to;
};

struct Comp {
  bool operator()(const HeapElem& left, const HeapElem& right) {
    return left.dist > right.dist;
  }
};

struct Solution {
  std::unique_ptr<BinInvTree> invTree;
  std::unique_ptr<BinCountTree> countTree;
  std::priority_queue<HeapElem, std::vector<HeapElem>, Comp> heap;
  int n;
  int s;
  std::vector<std::vector<std::array<int, 3>>> graph1;
  std::vector<std::array<int, 4>> graph2;
  std::vector<int64_t> dist;

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    int q;
    in >> q;
    in >> s;
    s--;
    graph1.assign(n, std::vector<std::array<int, 3>>());
    graph2.clear();
    for (int i = 0; i < q; i++) {
      int t;
      in >> t;
      if (t == 1) {
        int v, u, dist;
        in >> v >> u >> dist;
        v--;u--;
        graph1[v].push_back({u, u + 1, dist});
      } else if (t == 2) {
        int l, r, v, dist;
        in >> v >> l >> r >> dist;
        v--;l--;r--;
        graph1[v].push_back({l, r + 1, dist});
      } else {
        int l, r, v, dist;
        in >> v >> l >> r >> dist;
        v--;l--;r--;
        graph2.push_back({l, r + 1, v, dist});
      }
    }
    countTree.reset(new BinCountTree(n));
    invTree.reset(new BinInvTree(n));
    for (auto& edge : graph2) {
      invTree->add(edge[0], edge[1]);
    }
    heap.push(HeapElem{0, s, s+1});
    dist.assign(n, 1LL << 60);
    while (!heap.empty()) {
      HeapElem cur = heap.top();
      heap.pop();
      while (cur.from < cur.to) {
        int v = countTree->query(cur.from, cur.to);
        if (v < 0) break;
        cur.from = v + 1;
        dist[v] = cur.dist;
        countTree->modify(v);
        for (auto& edge : graph1[v]) {
          heap.push(HeapElem{cur.dist + edge[2], edge[0], edge[1]});
        }
        std::vector<int> edges = invTree->query(v);
        for (int edge : edges) {
          heap.push(HeapElem{cur.dist + graph2[edge][3], graph2[edge][2], graph2[edge][2] + 1});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] != 1LL << 60) {
        out << dist[i] << " ";
      } else {
        out << -1 << " ";
      }
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}