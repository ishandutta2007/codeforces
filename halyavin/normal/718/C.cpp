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
#include <array>

const int p = 1000000007;

struct LazyBinTreeUniversal {
  using T = std::array<int, 2>;
  using TMod = std::array<std::array<int, 2>, 2>;
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

  void apply(size_t p, size_t level, TMod up_mod) {
    if (p < size) {
      mod[p] = combineMod(mod[p], up_mod);
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

  T query(size_t p) {
    p += size;
    push(p);
    return t[p];
  }

  T combineWithMod(T left, T right, size_t level, TMod mod) {
    T all = combine(left, right);
    return T{(int)((int64_t(all[0]) * mod[0][0] + int64_t(all[1]) * mod[0][1]) % p),
             (int)((int64_t(all[0]) * mod[1][0] + int64_t(all[1]) * mod[1][1]) % p)};
  }

  T combine(T left, T right) {
    return T{(left[0] + right[0]) % p, (left[1] + right[1]) % p};
  }

  static TMod combineMod(TMod mod, TMod up_mod) {
    TMod result = {};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        int64_t res = 0;
        for (int k = 0; k < 2; k++) {
          res += int64_t(mod[i][k]) * up_mod[k][j];
        }
        result[i][j] = res % p;
      }
    }
    return result;
  }

  T combineValue(T all, TMod mod) {
    return T{(int)((int64_t(all[0]) * mod[0][0] + int64_t(all[1]) * mod[0][1]) % p),
             (int)((int64_t(all[0]) * mod[1][0] + int64_t(all[1]) * mod[1][1]) % p)};
  }

  T init() {
    return T{0, 0};
  }

  static TMod modInit() {
    return TMod{{{{1,0}},{{0,1}}}};
  }
};

LazyBinTreeUniversal::TMod getMod(int pow) {
  LazyBinTreeUniversal::TMod res = LazyBinTreeUniversal::modInit();
  LazyBinTreeUniversal::TMod x = LazyBinTreeUniversal::TMod{{{{0, 1}}, {{1, 1}}}};
  while (pow > 0) {
    if ((pow & 1) != 0) {
      res = LazyBinTreeUniversal::combineMod(res, x);
    }
    x = LazyBinTreeUniversal::combineMod(x, x);
    pow >>= 1;
  }
  return res;
}

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<LazyBinTreeUniversal::T> init(n);
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    auto mod = getMod(a);
    init[i][0] = mod[0][1];
    init[i][1] = mod[1][1];
  }
  LazyBinTreeUniversal tree(init);
  for (int i = 0; i < m; i++) {
    int type;
    in >> type;
    if (type == 1) {
      int l, r, x;
      in >> l >> r >> x;
      l--;
      tree.modify(l, r, getMod(x));
    } else {
      int l, r;
      in >> l >> r;
      l--;
      auto result = tree.query(l, r);
      out << result[0] << "\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}