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
struct LazyBinTreeUniversal {
  using T = std::pair<int64_t, int>;
  using TMod = int;
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

  void setNode(size_t p, size_t level, TMod up_mod) {
    if (p < size) {
      mod[p] = combineMod(mod[p], up_mod);
      t[p] = convert(mod[p], level);
    } else {
      t[p] = convert(combineMod(t[p].first, up_mod), 0);
    }
  }

  void apply(size_t p, size_t level, TMod up_mod) {
    if (p >= size || mod[p] != 0) {
      setNode(p, level, up_mod);
      return;
    }
    if (t[p].second >= up_mod) {
      return;
    }
    if (t[2 * p].second < up_mod) {
      setNode(2 * p + 1, level - 1, up_mod);
      apply(2 * p, level - 1, up_mod);
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    } else {
      apply(2 * p + 1, level - 1, up_mod);
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  void build(size_t p) {
    size_t level = 0;
    while (p > 1) {
      level++;
      p /= 2;
      if (mod[p] == modInit()) {
        t[p] = combine(t[2 * p], t[2 * p + 1]);
      }
    }
  }

  void push(size_t p) {
    for (size_t s = h; s > 0; s--) {
      size_t pos = p >> s;
      if (mod[pos] != modInit()) {
        TMod curMod = mod[pos];
        if (s > 1) {
          mod[2 * pos] = curMod;
          mod[2 * pos + 1] = curMod;
        }
        t[2 * pos] = convert(curMod, s - 1);
        t[2 * pos + 1] = convert(curMod, s - 1);
        mod[pos] = modInit();
      }
    }
  }

  void modify(size_t p, TMod value) {
    p += size;
    push(p);
    t[p] = convert(value, 0);
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
    //std::cerr << l << " " << r << " " << value << std::endl;
    if (l == r) return;
    l += size;
    r += size;
    int l0 = l;
    int r0 = r - 1;
    push(l0);
    push(r0);
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
//    for (int i = l0; i <= r0; i++) {
//      push(i);
//    }
    build(l0);
    build(r0);
  }

  T query(size_t p) {
    p += size;
    push(p);
    return t[p];
  }

 private:
//  T combineWithMod(T left, T right, size_t level, TMod mod) {
//    return combine(left, right) + mod;
//  }

  T combine(T left, T right) {
    return {left.first + right.first, std::min(left.second, right.second)};
  }

  T convert(TMod mod, int level) {
    return {int64_t(mod) << level, mod};
  }

  TMod combineMod(TMod mod, TMod up_mod) {
    return std::max(mod, up_mod);
  }

  T combineValue(T value, TMod up_mod) {
    if (up_mod > value.first) {
      return {up_mod, up_mod};
    }
    return value;
  }

  T init() {
    return {0, 0}; // std::numeric_limits<T>::lowest();
  }

  TMod modInit() {
    return 0;
  }
};

void init(std::vector<int>& minP, std::vector<int>& degP) {
  std::fill(degP.begin(), degP.end(), 1);
  std::iota(minP.begin(), minP.end(), 0);
  for (int i = 2; i * i < minP.size(); i++) {
    if (minP[i] != i) continue;
    for (int j = i * i; j < minP.size(); j += i) {
      if (minP[j] > i) {
        minP[j] = i;
        if (minP[j / i] == i) {
          degP[j] = degP[j / i] + 1;
        } else {
          degP[j] = 1;
        }
      }
    }
  }
}

void init(std::vector<std::vector<int>>& divisors) {
  int n = divisors.size();
  for (int i = 1; i < n; i++) {
    for (int j = i; j < n; j += i) {
      divisors[j].push_back(i);
    }
  }

}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  int maxNum = 2;
  for (int i = 0; i < n; i++) {
    in >> as[i];
    maxNum = std::max(maxNum, as[i]);
  }
  if (n <= 2) {
    out << 0 << std::endl;
    return;
  }
  std::vector<std::vector<int>> divisors(maxNum + 1);
  init(divisors);
  std::vector<std::vector<int>> pos(maxNum + 1);
  for (int i = 0; i < n; i++) {
    for (int d : divisors[as[i]]) {
      pos[d].push_back(i);
    }
  }
  for (std::vector<int>& idx : pos) {
    if (idx.size() == 1) {
      idx.clear();
    }
  }
  std::vector<int> startMaxGCD(n);
  std::vector<int> endMaxGCD(n);
  for (int d = maxNum; d >= 1; d--) {
    if (!pos[d].empty()) {
      int idx = pos[d][1];
      startMaxGCD[idx] = std::max(startMaxGCD[idx], d);
    }
  }
  for (int i = 1; i < n; i++) {
    startMaxGCD[i] = std::max(startMaxGCD[i], startMaxGCD[i - 1]);
  }
  for (int d = maxNum; d >= 1; d--) {
    if (!pos[d].empty()) {
      int idx = pos[d][pos[d].size() - 2];
      endMaxGCD[idx] = std::max(endMaxGCD[idx], d);
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    endMaxGCD[i] = std::max(endMaxGCD[i], endMaxGCD[i + 1]);
  }
  std::vector<std::vector<std::pair<int, int>>> bounds(n);
  for (int d = maxNum; d >= 1; d--) {
    if (!pos[d].empty()) {
      bounds[pos[d][0]].emplace_back(d, pos[d].back());
    }
  }
  int64_t ans = 0;
  std::vector<std::pair<int64_t, int>> initData(n);
  for (int i = 0; i < n; i++) {
    initData[i].first = endMaxGCD[i];
    initData[i].second = endMaxGCD[i];
  }
  LazyBinTreeUniversal tree(initData);
  for (int i = 0; i < n - 1; i++) {
    ans += startMaxGCD[i];
    ans += tree.query(i + 1, n).first;
    tree.modify(0, n, startMaxGCD[i]);
    for (std::pair<int, int>& bound : bounds[i]) {
      tree.modify(0, bound.second + 1, bound.first);
    }
//    std::cerr << ans << std::endl;
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}