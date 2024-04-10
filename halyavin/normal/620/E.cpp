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

template<class T, class TMod = T>
struct LazyBinTreeUniversal {
  size_t size;
  std::vector<T> t;
  std::vector<TMod> mod;
  size_t h;

  LazyBinTreeUniversal(size_t N) :
      size(N),
      t(2 * N),
      mod(N, modInit()),
      h(32 - __builtin_clz(N)) { }

  LazyBinTreeUniversal(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()),
      mod(other.size(), modInit()),
      h(32 - __builtin_clz(other.size())) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  void apply(size_t p, TMod up_mod) {
    if (p < size) {
      mod[p] = combineMod(mod[p], up_mod);
      t[p] = combineWithMod(t[2 * p], t[2 * p + 1], mod[p]);
    } else {
      t[p] = combineValue(t[p], up_mod);
    }
  }

  void build(size_t p) {
    while (p > 1) {
      p /= 2;
      t[p] = combineWithMod(t[2 * p], t[2 * p + 1], mod[p]);
    }
  }

  void push(size_t p) {
    for (size_t s = h; s > 0; s--) {
      size_t pos = p >> s;
      if (mod[pos] != modInit()) {
        apply(2 * pos, mod[pos]);
        apply(2 * pos + 1, mod[pos]);
        mod[pos] = modInit();
      }
    }
  }

  void modify(size_t p, TMod value) {
    p += size;
    t[p] = combineValue(t[p], value);
    build(p);
  }

  T query(size_t l, size_t r) {
    if (l == r) return init();
    l += size;
    r += size;
    push(l);
    push(r - 1);
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
      l /= 2;
      r /= 2;
    }
    return combine(left, right);
  }

  void modify(size_t l, size_t r, TMod value) {
    if (l == r) return;
    l += size;
    r += size;
    int l0 = l;
    int r0 = r - 1;
    push(l0);
    push(r0);
    while (l < r) {
      if (l & 1) {
        apply(l, value);
        l++;
      }
      if (r & 1) {
        r--;
        apply(r, value);
      }
      l /= 2;
      r /= 2;
    }
    build(l0);
    build(r0);
  }

  T query(size_t p) {
    p += size;
    push(p);
    return t[p];
  }

private:
  T combineWithMod(T left, T right, TMod mod) {
    return mod == 0 ? combine(left, right) : mod;
  }

  T combine(T left, T right) {
    return left | right;
  }

  TMod combineMod(TMod mod, TMod up_mod) {
    return up_mod;
  }

  T combineValue(T value, TMod up_mod) {
    return up_mod == 0 ? value : up_mod;
  }

  T init() {
    return 0;
  }

  TMod modInit() {
    return 0;
  }
};



struct Solution {
  int n;
  int q;
  std::vector<int64_t> startColors;
  std::vector<std::vector<int>> graph;
  std::vector<std::pair<int, int>> order;

  int dfs(int v, int prev, int o) {
    order[v].first = o;
    o++;
    for (int nv : graph[v]) {
      if (nv != prev) {
        o = dfs(nv, v, o);
      }
    }
    order[v].second = o;
    return o;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> q;
    startColors.resize(n);
    for (int i = 0; i < n; i++) {
      int c;
      in >> c;
      startColors[i] = 1LL << c;
    }
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      in >> x >> y;
      x--;
      y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    order.resize(n);
    dfs(0, -1, 0);
    std::vector<int64_t> start(n);
    for (int i = 0; i < n; i++) {
      start[order[i].first] = startColors[i];
    }
    LazyBinTreeUniversal<int64_t, int64_t> tree(start);
    for (int i = 0; i < q; i++) {
      int type, v, color;
      in >> type;
      if (type == 1) {
        in >> v >> color;
        v--;
        tree.modify(order[v].first, order[v].second, 1LL << color);
      } else {
        in >> v;
        v--;
        int64_t mask = tree.query(order[v].first, order[v].second);
        out << __builtin_popcount(uint32_t(mask)) + __builtin_popcount(uint32_t(mask >> 32)) << "\n";
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