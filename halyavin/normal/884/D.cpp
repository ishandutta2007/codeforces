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
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> heap;
    for (int i = 0; i < n ;i++) {
        int a;
        in >> a;
        heap.push(a);
    }
    int64_t answer = 0;
    if (n % 2 == 0) {
        int64_t a = heap.top();heap.pop();
        int64_t b = heap.top();heap.pop();
        answer += a + b;
        heap.push(a + b);
    }
    while (heap.size() > 1) {
        int64_t a= heap.top();heap.pop();
        int64_t b =heap.top();heap.pop();
        int64_t c = heap.top();heap.pop();
        answer += a + b + c;
        heap.push(a + b + c);
    }
    out << answer << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}