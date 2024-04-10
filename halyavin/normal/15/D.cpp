#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif

#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <tuple>

using vvi = std::vector<std::vector<int>>;
using vvl = std::vector<std::vector<int64_t>>;

void process(vvi& map, vvl& sumRect, vvi& minRect, size_t a, size_t b) {
  for (size_t i = 0; i < map.size(); i++) {
    std::vector<int64_t> sumLine;
    int64_t sum = 0;
    for (size_t j = 0; j < b; j++) {
      sum += map[i][j];
    }
    for (size_t j = 0; j <= map[i].size() - b; j++) {
      sumLine.push_back(sum);
      if (j < map[i].size() - b) {
        sum -= map[i][j];
        sum += map[i][j + b];
      }
    }
    sumRect.push_back(std::move(sumLine));
    std::vector<int> minLine = map[i];
    size_t cur_b = 1;
    while (2 * cur_b <= b) {
      for (size_t j = 0; j < minLine.size() - cur_b; j++) {
        minLine[j] = std::min(minLine[j], minLine[j + cur_b]);
      }
      minLine.resize(minLine.size() - cur_b);
      cur_b *= 2;
    }
    if (cur_b < b) {
      size_t diff = b - cur_b;
      for (size_t j = 0; j < minLine.size() - diff; j++) {
        minLine[j] = std::min(minLine[j], minLine[j + diff]);
      }
      minLine.resize(minLine.size() - diff);
    }
    minRect.push_back(std::move(minLine));
  }
  std::vector<int64_t> sumLine = sumRect[0];
  for (size_t i = 1; i < a; i++) {
    for (size_t j = 0; j < sumLine.size(); j++) {
      sumLine[j] += sumRect[i][j];
    }
  }
  for (size_t i = 0; i <= sumRect.size() - a; i++) {
    std::vector<int64_t> prev = sumRect[i];
    sumRect[i] = sumLine;
    if (i < sumRect.size() - a) {
      for (size_t j = 0; j < sumLine.size(); j++) {
        sumLine[j] += sumRect[i + a][j] - prev[j];
      }
    }
  }
  sumRect.resize(sumRect.size() - a + 1);
  size_t cur_a = 1;
  while (2 * cur_a <= a) {
    for (size_t i = 0; i < minRect.size() - cur_a; i++) {
      for (size_t j = 0; j < minRect[i].size(); j++) {
        minRect[i][j] = std::min(minRect[i][j], minRect[i + cur_a][j]);
      }
    }
    minRect.resize(minRect.size() - cur_a);
    cur_a *= 2;
  }
  if (cur_a < a) {
    size_t diff = a - cur_a;
    for (size_t i = 0; i < minRect.size() - diff; i++) {
      for (size_t j = 0; j < minRect[i].size(); j++) {
        minRect[i][j] = std::min(minRect[i][j], minRect[i + diff][j]);
      }
    }
    minRect.resize(minRect.size() - diff);
  }
}

void run(std::istream& in, std::ostream& out) {
  size_t n, m, a, b;
  in >> n >> m;
  in >> a >> b;
  vvi map(n, std::vector<int>(m));
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      in >> map[i][j];
    }
  }
  vvl sumRect;
  vvi minRect;
  process(map, sumRect, minRect, a, b);
  vvl costRect = sumRect;
  int64_t area = static_cast<int64_t>(a * b);
  for (size_t i = 0; i < costRect.size(); i++) {
    for (size_t j = 0; j < costRect[i].size(); j++) {
      costRect[i][j] = sumRect[i][j] - area * minRect[i][j];
    }
  }
  std::vector<std::vector<bool>> flags(n + a - 1, std::vector<bool>(m + b - 1));
  std::vector<std::tuple<int64_t, size_t, size_t>> pos;
  for (size_t i = 0; i < costRect.size(); i++) {
    for (size_t j = 0; j < costRect[i].size(); j++) {
      pos.emplace_back(costRect[i][j], i, j);
    }
  }
  std::sort(pos.begin(), pos.end());
  std::vector<std::tuple<int64_t, size_t, size_t>> ans;
  for (size_t i = 0; i < pos.size(); i++) {
    size_t x = std::get<1>(pos[i]) + a - 1;
    size_t y = std::get<2>(pos[i]) + b - 1;
    if (flags[x][y]) continue;
    for (size_t i = x - a + 1; i < x + a; i++) {
      for (size_t j = y - b + 1; j < y + b; j++) {
        flags[i][j] = 1;
      }
    }
    ans.push_back(pos[i]);
  }
//  out << ans.size() << std::endl;
//  for (size_t i = 0; i < ans.size(); i++) {
//    out << (std::get<1>(ans[i]) + 1) << " " << (std::get<2>(ans[i]) + 1) << " " << std::get<0>(ans[i]) << std::endl;
//  }
  printf("%d\n", (int)ans.size());
  for (size_t i = 0; i < ans.size(); i++) {
    printf("%d %d %I64d\n", int(std::get<1>(ans[i]) + 1), int(std::get<2>(ans[i]) + 1), std::get<0>(ans[i]));
  }
//  size_t mult = costRect[0].size();
//  std::vector<int64_t> cost2(costRect.size() * mult);
//  for (size_t i = 0; i < costRect.size(); i++) {
//    for (size_t j = 0; j < costRect[i].size(); j++) {
//      cost2[i * mult + j] = costRect[i][j];
//    }
//  }
//  costRect.clear();
//  std::vector<size_t> pos(cost2.size());
//  std::iota(pos.begin(), pos.end(), 0);
//  std::sort(pos.begin(), pos.end(), [&cost2](size_t left, size_t right) {
//    return cost2[left] < cost2[right] || (cost2[left] == cost2[right] && left < right);
//  });
//  std::vector<std::tuple<int64_t, size_t, size_t>> ans;
//  for (size_t i = 0; i < pos.size(); i++) {
//    size_t x = pos[i] / mult;
//    size_t y = pos[i] % mult;
//    if (flags[x][y]) continue;
//    size_t lx = x >= a - 1 ? x - a + 1 : 0;
//    size_t ly = std::min(x + a, flags.size());
//    for (size_t i = x >= a - 1 ? x - a + 1 : 0; i < x + a; i++) {
//      for (size_t j = y >= b - 1 ? y - b + 1 : 0; j < y + b; j++) {
//        flags[i][j] = true;
//      }
//    }
//    ans.emplace_back(cost2[pos[i]], x, y);
//  }
//  out << ans.size() << std::endl;
//  for (size_t i = 0; i < ans.size(); i++) {
//    out << (std::get<1>(ans[i]) + 1) << " " << (std::get<2>(ans[i]) + 1) << " " << std::get<0>(ans[i]) << std::endl;
//  }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}