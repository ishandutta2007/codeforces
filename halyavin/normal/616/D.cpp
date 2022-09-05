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

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int ansl = 0;
  int ansr = 0;
  int ans = 0;
  int l = 0;
  int cur = 0;
  std::map<int, int> stat;
  for (int r = 0; r < n; r++) {
    int num = as[r];
    stat[num]++;
    if (stat[num] == 1) {
      cur++;
      if (cur > k) {
        while (true) {
          stat[as[l]]--;
          if (stat[as[l]] == 0) {
            l++;
            break;
          }
          l++;
        }
        cur--;
      }
    }
    if (r - l + 1 > ans) {
      ans = r - l + 1;
      ansl = l;
      ansr = r;
    }
  }
  out << (ansl + 1) << " " << (ansr + 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}