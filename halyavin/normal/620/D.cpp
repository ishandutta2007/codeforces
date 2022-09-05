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
#include <tuple>
#include <fstream>

using Swap = std::tuple<int64_t, std::vector<int>, std::vector<int>>;

template<int K>
using Variants = std::vector<std::pair<int64_t, std::array<int, K>>>;

template<int K>
Swap findOpt(Variants<K>& a,
             Variants<K>& b,
             int64_t suma,
             int64_t sumb) {
  Swap result;
  if (a.size()== 0 || b.size() == 0) {
    std::get<0>(result) = 1LL << 61;
    return result;
  }
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  int j = 0;
  int64_t opt = 1LL << 61;
  int opta = -1;
  int optb = -1;
  int64_t sum = suma + sumb;
  for (size_t i = 0; i < a.size(); i++) {
    int64_t cur = suma - a[i].first + b[j].first;
    int64_t diff = std::abs(cur - (sum - cur));
    if (diff < opt) {
      opt = diff;
      opta = i;
      optb = j;
    }
    while (j + 1 < b.size()) {
      int64_t cur2 = suma - a[i].first + b[j + 1].first;
      int64_t diff2 = std::abs(cur2 - (sum - cur2));
      if (diff2 <= diff) {
        diff = diff2;
        j++;
      } else {
        break;
      }
      if (diff2 < opt) {
        opt = diff2;
        opta = i;
        optb = j;
      }
    }
  }
  std::get<0>(result) = opt;
  std::get<1>(result).assign(a[opta].second.begin(), a[opta].second.end());
  std::get<2>(result).assign(b[optb].second.begin(), b[optb].second.end());
  return result;
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  int64_t suma = 0;
  std::vector<int64_t> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
    suma += as[i];
  }
  int m;
  in >> m;
  int64_t sumb = 0;
  std::vector<int64_t> bs(m);
  for (int i = 0; i < m; i++) {
    in >> bs[i];
    sumb += bs[i];
  }
  Swap s = {};
  std::get<0>(s) = std::abs(suma - sumb);
  {
    Variants<1> a1;
    Variants<1> b1;
    for (int i = 0; i < n; i++) {
      a1.emplace_back(as[i], std::array<int, 1>{{i}});
    }
    for (int i = 0; i < m; i++) {
      b1.emplace_back(bs[i], std::array<int, 1>{{i}});
    }
    Swap s1 = findOpt<1>(a1, b1, suma, sumb);
    if (std::get<0>(s1) < std::get<0>(s)) {
      s = s1;
    }
  }
  {
    Variants<2> a2;
    Variants<2> b2;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        a2.emplace_back(as[i] + as[j], std::array<int, 2>{{i, j}});
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = i + 1; j < m; j++) {
        b2.emplace_back(bs[i] + bs[j], std::array<int, 2>{{i, j}});
      }
    }
    Swap s2 = findOpt<2>(a2, b2, suma, sumb);
    if (std::get<0>(s2) < std::get<0>(s)) {
      s = s2;
    }
  }
  out << std::get<0>(s) << std::endl;
  out << std::get<1>(s).size() << std::endl;
  for (size_t i = 0; i < std::get<1>(s).size(); i++) {
    out << std::get<1>(s)[i] + 1 << " " << std::get<2>(s)[i] + 1 << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}