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
#include <map>

struct Solution {
  std::map<int64_t, int64_t> events;

  int64_t lca(int64_t u, int64_t v) {
    while (true) {
      if (u > v) {
        u /= 2;
      } else if (u < v) {
        v /= 2;
      } else {
        return u;
      }
    }
  }

  void addToll(int64_t v, int64_t u, int64_t w) {
    int64_t p = lca(v, u);
    while (v != p) {
      events[v] += w;
      v /= 2;
    }
    while (u != p) {
      events[u] += w;
      u /= 2;
    }
  }

  int64_t getCost2(int64_t p, int64_t u) {
    int64_t res = 0;
    while (u != p) {
      res += events[u];
      u /= 2;
    }
    return res;
  }

  int64_t getCost(int64_t v, int64_t u) {
    int64_t p = lca(v, u);

    return getCost2(p, v) + getCost2(p, u);
  }

  void run(std::istream& in, std::ostream& out) {
    int q;
    in >> q;
    events.clear();
    for (int i = 0; i < q; i++) {
      int type;
      in >> type;
      if (type == 1) {
        int64_t v,u, w;
        in >> v >> u >> w;
        addToll(v, u, w);
      } else if (type == 2) {
        int64_t v, u;
        in >> v >> u;
        out << getCost(v, u) << std::endl;
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