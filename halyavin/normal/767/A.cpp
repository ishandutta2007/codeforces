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
#include <queue>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::priority_queue<int, std::vector<int>, std::less<>> queue;
  int cur = n;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    queue.push(x);
    while (!queue.empty() && queue.top() == cur) {
      out << cur << " ";
      cur--;
      queue.pop();
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}