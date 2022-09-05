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

const int p = 1000000007;

inline int mulMod(int x, int y) {
  return int(int64_t(x) * y % p);
}

inline int addMod(int x, int y) {
  int result = x + y;
  if (result >= p) result -= p;
  return result;
}

template<class T>
std::pair<T, T> gcd2(T x, T y) {
  if (x == 0) {
    return {0, 1};
  }
  T s = y / x;
  std::pair<T, T> res = gcd2(y % x, x);
  return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
  x = x % p;
  if (x < 0) {
    x += p;
  }
  std::pair<T, T> res = gcd2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}
template<class T, class TMod = T>
struct LazyBinTreeUniversal {
  size_t size;
  std::vector<T> t;
  std::vector<TMod> mod;
  size_t h;

  LazyBinTreeUniversal(size_t N) :
      size(N),
      t(2 * N),
      mod(2 * N, modInit()),
      h(32 - __builtin_clz(N)) { }

  LazyBinTreeUniversal(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()),
      mod(2 * other.size(), modInit()),
      h(32 - __builtin_clz(other.size())) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  void apply(size_t p, size_t level, TMod up_mod) {
    mod[p] = combineMod(mod[p], up_mod);
    if (p < size) {
      t[p] = combineWithMod(t[2 * p], t[2 * p + 1], level, mod[p]);
    } else {
      t[p] = combineValue(t[p], up_mod);
    }
  }

  void build(size_t p) {
    size_t level = 0;
    while (p > 1) {
      level++;
      p /= 2;
      t[p] = combineWithMod(t[2 * p], t[2 * p + 1], level, mod[p]);
    }
  }

  void push(size_t p) {
    for (size_t s = h; s > 0; s--) {
      size_t pos = p >> s;
      if (mod[pos] != modInit()) {
        apply(2 * pos, s - 1, mod[pos]);
        apply(2 * pos + 1, s - 1, mod[pos]);
        mod[pos] = modInit();
      }
    }
  }

  void modify(size_t p, T value) {
    p += size;
    t[p] = combineValue(value, mod[p]);
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
    size_t level = 0;
    while (l < r) {
      if (l & 1) {
        apply(l, level, value);
        l++;
      }
      if (r & 1) {
        r--;
        apply(r, level, value);
      }
      l /= 2;
      r /= 2;
      level++;
    }
    build(l0);
    build(r0);
  }

  TMod queryMult(size_t p) {
    p += size;
    push(p);
    return mod[p];
  }

private:
  T combineWithMod(T left, T right, size_t level, TMod mod) {
    return mulMod(mod, combine(left, right));
  }

  T combine(T left, T right) {
    return addMod(left, right);
  }

  TMod combineMod(TMod mod, TMod up_mod) {
    return mulMod(mod, up_mod);
  }

  T combineValue(T value, TMod up_mod) {
    return mulMod(value, up_mod);
  }

  T init() {
    return 0;
  }

  TMod modInit() {
    return 1;
  }
};

struct InputRecord {
  int type;
  int vertex;
  int value;
};

#include <random>

struct Solution {

  std::vector<InputRecord> input;
  std::vector<std::vector<int>> graph;
  std::vector<int> prev;
  int nodes;
  std::vector<int> order;
  std::vector<int> maxOrder;
  std::vector<int> degs;

  void buildGraph() {
    prev.resize(nodes);
    graph.resize(nodes);
    int cur = 0;
    for (InputRecord rec : input) {
      if (rec.type == 1) {
        prev[cur] = rec.vertex;
        if (rec.vertex >= 0) {
          graph[rec.vertex].push_back(cur);
        }
        cur++;
      }
    }
  }

  int curOrder;

  int dfsOrder(int v) {
    order[v] = curOrder;
    curOrder++;
    for (int nv : graph[v]) {
      dfsOrder(nv);
    }
    maxOrder[v] = curOrder;
  }

  void calcOrder() {
    order.resize(nodes);
    maxOrder.resize(nodes);
    curOrder = 0;
    dfsOrder(0);
  }


  void run(std::istream& in, std::ostream& out) {
    int value, requests;
    in >> value >> requests;
    input.push_back({1, -1, value});
    nodes = 1;
    for (int i = 0; i < requests; i++) {
      int type, vertex;
      value = 0;
      in >> type >> vertex;
      if (type == 1) {
        in >> value;
        nodes++;
      }
      vertex--;
      input.push_back({type, vertex, value});
    }
    buildGraph();
    calcOrder();
    degs.resize(nodes);
    LazyBinTreeUniversal<int> tree(nodes);
    int cur = 0;
    for (InputRecord rec : input) {
      if (rec.type == 1) {
        degs[cur] = 1;
        tree.modify(order[cur], rec.value);
        if (rec.vertex >= 0) {
          int before = degs[rec.vertex];
          degs[rec.vertex]++;
          int mult = mulMod(before + 1, inv(before, p));
          int left = order[rec.vertex];
          int right = maxOrder[rec.vertex];
          tree.modify(left, right, mult);
        }
        cur++;
        continue;
      }
      // rec.type == 2
      int v = rec.vertex;
      int left = order[v];
      int right = maxOrder[v];
      int sum = tree.query(left, right);
      int pv = prev[v];
      if (pv >= 0) {
        sum = mulMod(sum, inv(tree.queryMult(order[pv]), p));
      }
      out << sum << "\n";
    }
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}