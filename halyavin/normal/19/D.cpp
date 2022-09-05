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
#include <chrono>

template<class Comp, class Set, class = decltype(std::declval<Comp>()(size_t(0), size_t(0)))>
void compress(size_t n, Comp comp, Set set, std::vector<size_t>* map) {
  map->resize(n);
  std::iota(map->begin(), map->end(), size_t(0));
  std::sort(map->begin(), map->end(), comp);
  size_t start = 0;
  set((*map)[0], start);
  for (size_t i = 1; i < n; i++) {
    if (comp((*map)[start], (*map)[i])) {
      start++;
      (*map)[start] = (*map)[i];
    }
    set((*map)[i], start);

  }
  map->resize(start + 1);
};

template<class T>
struct BinTree1 {
  size_t size;
  std::vector<T> t;

  BinTree1(size_t N) :
      size(N),
      t(2 * N) { }

  BinTree1(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = std::max(t[2 * i], t[2 * i + 1]);
    }
  }

  T get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p, T value) {
    p += size;
    t[p] = value;
    while (p > 1) {
      p = p / 2;
      t[p] = std::max(t[2 * p], t[2 * p + 1]);
    }
  }

  void modifyMax(size_t p, T value) {
    p += size;
    t[p] = value;
    while (p > 1) {
      p = p / 2;
      if (t[p] >= value) break;
      t[p] = value;
    }
  }

  size_t getNode(size_t node, T value) {
    while (node < size) {
      if (t[2 * node] > value) {
        node = 2 * node;
      } else {
        node = 2 * node + 1;
      }
    }
    return node - size;
  }

  size_t query(size_t l, size_t r, T value) {
    l += size;
    r += size;
    size_t minR = 0;
    while (l < r) {
      if (l & 1) {
        if (t[l] > value) return getNode(l, value);
        l++;
      }
      if (r & 1) {
        r--;
        if (t[r] > value) minR = r;
      }
      l = l / 2;
      r = r / 2;
    }
    return minR == 0 ? size : getNode(minR, value);
  }

};

void run(std::istream& in, std::ostream& out) {
  size_t n;
  //in >> n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> input(n);
  std::vector<int> tp(n);
  for (size_t i = 0; i < n; i++) {
    char tmp[16];
    scanf("%9s%d%d", tmp, &input[i].first, &input[i].second);
    if (tmp[0] == 'a') {
      tp[i] = 0;
    } else if (tmp[0] == 'r') {
      tp[i] = 1;
    } else {
      tp[i] = 2;
    }
//    std::string strTp;
//    in >> strTp;
//    if (strTp == "add") {
//      tp[i] = 0;
//    } else if (strTp == "remove") {
//      tp[i] = 1;
//    } else {
//      tp[i] = 2;
//    }
//    in >> input[i].first >> input[i].second;
  }
  std::vector<size_t> compressedPoint(n);
  std::vector<size_t> map(n);
  compress(n, [&input](size_t left, size_t right) { return input[left] < input[right]; },
           [&compressedPoint](size_t idx, size_t res) { compressedPoint[idx] = res; }, &map);
  BinTree1<int> tree(map.size());
  std::vector<size_t> stack;
  std::vector<size_t> remap(map.size());
  for (size_t i = 0; i < map.size(); i++) {
    if (i > 0 && input[map[i]].first != input[map[i - 1]].first) {
      for (size_t v : stack) {
        remap[v] = i;
      }
      stack.clear();
    }
    stack.push_back(i);
  }
  for (size_t v : stack) {
    remap[v] = map.size();
  }
  for (int i = 0; i < n; i++) {
    if (tp[i] == 0) {
      tree.modifyMax(compressedPoint[i], input[i].second);
      continue;
    }
    if (tp[i] == 1) {
      tree.modify(compressedPoint[i], 0);
      continue;
    }
    size_t find = tree.query(remap[compressedPoint[i]], tree.size, input[i].second);
    if (find == tree.size) {
      //printf("-1\n");
      out << "-1\n" << std::endl;
    } else {
      //printf("%d %d\n", input[map[find]].first, input[map[find]].second);
      out << input[map[find]].first << " " << input[map[find]].second << std::endl;
    }
  }
}

int main() {
//  freopen("../../../in.txt", "r", stdin);
//  freopen("../../../out.txt", "w", stdout);
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  char buf[65536];
  std::cout.rdbuf()->pubsetbuf(buf, sizeof(buf));
  auto time1 = std::chrono::steady_clock::now();
  run(std::cin, std::cout);
  auto diff = std::chrono::steady_clock::now() - time1;
  std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() << " msec" << std::endl;
  return 0;
}