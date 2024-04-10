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


struct HL {
  using Edge = int;
  const std::vector<std::vector<Edge>>* graph;
  size_t n;
  std::vector<int> parent;
  std::vector<int> left;
  std::vector<int> right;
  std::vector<int> start;
  HL() {}

  static int vertex(const Edge& edge) {
    return edge;
  }

  void build(const std::vector<std::vector<Edge>>& graph);

  int dfsSize(int v, int prev, std::vector<int>& treeSize);

  int dfs(int v, int prev, const std::vector<int>& treeSize);
};

int HL::dfsSize(int v, int prev, std::vector<int>& treeSize) {
  int res = 1;
  for (const Edge& e : (*graph)[v]) {
    int nv = vertex(e);
    if (nv != prev) {
      res += dfsSize(nv, v, treeSize);
    }
  }
  treeSize[v] = res;
  return res;
}

int HL::dfs(int v, int prev, const std::vector<int>& treeSize) {
  parent[v] = prev;
  int maxV = -1;
  int maxSize = 0;
  for (const Edge& e : (*graph)[v]) {
    int nv = vertex(e);
    if (nv != prev) {
      if (treeSize[nv] > maxSize) {
        maxV = nv;
        maxSize = treeSize[nv];
      }
    }
  }
  int cur = left[v] + 1;
  if (maxV >= 0) {
    left[maxV] = cur;
    start[maxV] = start[v];
    cur = dfs(maxV, v, treeSize);
    for (const Edge& e : (*graph)[v]) {
      int nv = vertex(e);
      if (nv != prev && nv != maxV) {
        left[nv] = cur;
        start[nv] = nv;
        cur = dfs(nv, v, treeSize);
      }
    }
  }
  right[v] = cur;
  return cur;
}

void HL::build(const std::vector<std::vector<Edge>>& graph) {
  this->graph = &graph;
  n = graph.size();
  std::vector<int> treeSize(n);
  dfsSize(0, -1, treeSize);
  parent.resize(n);
  left.resize(n);
  right.resize(n);
  start.resize(n);
  dfs(0, -1, treeSize);
}

struct LazyBinMaxTree {
  size_t size;
  std::vector<std::pair<int64_t, int>> t;
  std::vector<int64_t> mod;

  LazyBinMaxTree(size_t N) :
      size(N),
      t(2 * N),
      mod(N) {}

  LazyBinMaxTree(const std::vector<std::pair<int64_t, int>>& other) :
      size(other.size()),
      t(2 * other.size()),
      mod(other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  std::pair<int64_t, int> query(size_t l, size_t r) {
    if (l == r) return init();
    l += size;
    r += size;
    std::pair<int64_t, int> leftMax = init();
    std::pair<int64_t, int> rightMax = init();
    while (l < r) {
      if (leftMax != init()) {
        leftMax.first += mod[l - 1];
      }
      if (l & 1) {
        leftMax = combine(leftMax, t[l]);
        l++;
      }
      if (rightMax != init()) {
        rightMax.first += mod[r];
      }
      if (r & 1) {
        r--;
        rightMax = combine(t[r], rightMax);
      }
      l /= 2;
      r /= 2;
    }
    l--;
    while (r > 0) {
      if (leftMax != init()) leftMax.first += mod[l];
      if (rightMax != init()) rightMax.first += mod[r];
      l /= 2;
      r /= 2;
    }
    return combine(leftMax, rightMax);
  }

  void modify(size_t l, size_t r, int64_t value) {
    if (l == r) return;
    l += size;
    r += size;
    bool leftAdd = false;
    bool rightAdd = false;
    while (l < r) {
      if (leftAdd) {
        restore(l - 1);
      }
      if (l & 1) {
        if (l < size) {
          mod[l] += value;
        }
        t[l].first += value;
        leftAdd = true;
        l++;
      }
      if (rightAdd) {
        restore(r);
      }
      if (r & 1) {
        r--;
        if (r < size) {
          mod[r] += value;
        }
        t[r].first += value;
        rightAdd = true;
      }
      l /= 2;
      r /= 2;
    }
    l--;
    while (r > 0) {
      if (leftAdd) restore(l);
      if (rightAdd) restore(r);
      l /= 2;
      r /= 2;
    }
  }

  std::pair<int64_t, int> query(size_t p) {
    p += size;
    std::pair<int64_t, int> res = t[p];
    while (p > 1) {
      p = p / 2;
      res.first += mod[p];
    }
    return res;
  }

  void modify(size_t p, int64_t value) {
    p += size;
    t[p].first += value;
    while (p > 1) {
      p = p / 2;
      restore(p);
    }
  }

 private:
  void restore(size_t p) {
    t[p] = combine(t[2 * p], t[2 * p + 1]);
    t[p].first += mod[p];
  }

  std::pair<int64_t, int> combine(std::pair<int64_t, int> left, std::pair<int64_t, int> right) {
    return std::min(left, right);
  }

  std::pair<int64_t, int> init() {
    return {(1LL << 60), 0};
  }
};

struct Solution {
  int n, m, q;
  std::vector<std::vector<int>> graph;
  std::vector<std::vector<int>> girls;
  HL hl;

  std::pair<int64_t, int> query(int u, int v, LazyBinMaxTree& tree) {
    std::pair<int64_t, int> res {(1LL << 60), 0};
    while (hl.start[u] != hl.start[v]) {
      if (hl.left[u] > hl.left[v]) std::swap(u, v);
      std::pair<int64_t, int> resV = tree.query(hl.left[hl.start[v]], hl.left[v] + 1);
      res = std::min(res, resV);
      v = hl.parent[hl.start[v]];
    }
    if (hl.left[u] > hl.left[v]) std::swap(u, v);
    std::pair<int64_t, int> resFinal = tree.query(hl.left[u], hl.left[v] + 1);
    return std::min(res, resFinal);
  };

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m >> q;
    graph.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      in >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    girls.assign(n, {});
    std::vector<int> girlVs(m);
    for (int i = 0; i < m; i++) {
      int v;
      in >> v;
      v--;
      girlVs[i] = v;
      girls[v].push_back(i);
    }
    hl.build(graph);
    for (int i = 0; i < n; i++) {
      std::sort(girls[i].begin(), girls[i].end(), std::greater<int>());
    }
    std::vector<std::pair<int64_t, int>> init(n, std::pair<int64_t, int>{(1LL << 60), 0});
    for (int i = 0; i < n; i++) {
      if (!girls[i].empty()) {
        init[hl.left[i]] = {girls[i].back(), girls[i].back()};
      }
    }
    LazyBinMaxTree tree(init);
    for (int i = 0; i < q; i++) {
      int t;
      in >> t;
      if (t == 1) {
        std::vector<int> ans;
        int v, u, k;
        in >> v >> u >> k;
        v--; u--;
        for(; k > 0; k--) {
          std::pair<int64_t, int> girl = query(v, u, tree);
          if (girl.first > (1LL << 59)) {
            break;
          }
          int curGirl = girl.second;
          int pos = girlVs[curGirl];
          ans.push_back(curGirl);
          girls[pos].resize(girls[pos].size() - 1);
          if (girls[pos].empty()) {
            tree.modify(hl.left[pos], (1LL << 60));
          } else {
            tree.t[hl.left[pos] + n].second = girls[pos].back();
            tree.modify(hl.left[pos], girls[pos].back() - curGirl);
          }
        }
        out << ans.size();
        for (int girl : ans) {
          out << " " << (girl + 1);
        }
        out << std::endl;
      } else {
        int v, mod;
        in >> v >> mod;
        v--;
        tree.modify(hl.left[v], hl.right[v], mod);
      }
    }
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}