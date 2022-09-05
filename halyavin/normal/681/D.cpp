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

struct Solution {
  int n;
  std::vector<std::vector<int>> graph;
  std::vector<bool> isSon;
  std::vector<int> order;
  std::vector<int> presents;
  int left, right;


  void addLast(int v) {
    order[right] = v;
    right++;
  }

  void addFirst(int v) {
    left--;
    order[left] = v;
  }

  bool dfs(int v) {
    int value = presents[v];
    for (int nv : graph[v]) {
      if (presents[nv] != value && presents[nv] != nv) {
        return false;
      }
      if (presents[nv] == value) {
        addLast(nv);
      } else {
        addFirst(nv);
      }
      bool res = dfs(nv);
      if (!res) {
        return false;
      }
    }
    return true;
  }

  void run(std::istream& in, std::ostream& out) {
    int m;
    in >> n >> m;
    graph.assign(n, std::vector<int>());
    isSon.assign(n, false);
    for (int i = 0; i < m; i++) {
      int p, q;
      in >> p >> q;
      p--;
      q--;
      graph[p].push_back(q);
      isSon[q] = true;
    }
    presents.resize(n);
    for (int i = 0; i < n; i++) {
      int p;
      in >> p;
      presents[i] = p - 1;
    }
    order.resize(2 * n);
    left = n;
    right = n;
    bool bad = false;
    for (int i = 0; i < n && !bad; i++) {
      if (!isSon[i]) {
        if (presents[i] != i) {
          bad = true;
          break;
        }
        addLast(i);
        bad = bad || !dfs(i);
      }
    }
    if (bad) {
      out << -1 << std::endl;
    } else {
      out << n << std::endl;
      for (int i = left; i < right; i++) {
        out << (order[i] + 1) << std::endl;
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