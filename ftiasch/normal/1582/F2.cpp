// #include "debug.h"

#include <bits/stdc++.h>

const int N = 1'000'000;
const int B = 13;
const int M = 1 << B;

int n, val[M];
std::vector<int> indices[M];

int main() {
  scanf("%d", &n);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    indices[a].push_back(i);
  }
  std::vector<std::pair<int, int>> ord[2], buf;
  ord[0].reserve(M);
  ord[1].reserve(M);
  buf.reserve(M);
  ord[0].emplace_back(0, -1);
  std::fill(val, val + M, n);
  val[0] = -1;
  for (int a = 0; a < M; ++a) {
    const auto &cur = ord[a & 1];
    auto &nxt = ord[(a + 1) & 1];
    nxt.clear();
    auto iterator = indices[a].begin();
    // if (!indices[a].empty()) {
    //   std::cerr << KV(a) << std::endl;
    // }
    for (auto [sum, idx] : cur) {
      while (iterator != indices[a].end() && idx >= *iterator) {
        for (auto p : buf) {
          nxt.push_back(p);
        }
        buf.clear();
        iterator++;
      }
      if (val[sum] == idx) {
        nxt.emplace_back(sum, idx);
      }
      if (iterator != indices[a].end() && val[sum ^ a] > *iterator) {
        // std::cerr << "update " << (sum ^ a) << " from " << sum << " with "
        //           << *iterator << std::endl;
        val[sum ^ a] = *iterator;
        buf.emplace_back(sum ^ a, *iterator);
      }
    }
    for (auto p : buf) {
      nxt.push_back(p);
    }
    buf.clear();
    // if (!indices[a].empty()) {
    //   std::cerr << KV(indices[a]) << "\n"
    //             << KV(cur) << "\n"
    //             << KV(nxt) << std::endl;
    // }
  }
  auto &cur = ord[M & 1];
  std::sort(cur.begin(), cur.end());
  printf("%d\n", static_cast<int>(cur.size()));
  for (auto [x, _] : cur) {
    printf("%d ", x);
  }
  puts("");
}