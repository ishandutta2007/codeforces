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

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::vector<int>> graph(n, std::vector<int>(n));
  std::for_each(graph.begin(), graph.end(), [&in](std::vector<int>& row) {
    std::for_each(row.begin(), row.end(), [&in](int& num) {
      in >> num;
    });
  });
  int k = 0;
  std::for_each(graph.begin(), graph.end(), [&graph, &k](std::vector<int>& row) {
    std::for_each(graph.begin(), graph.end(), [&graph, &k, &row](std::vector<int>& row2){
      int j = 0;
      std::for_each(row.begin(), row.end(), [&graph, &k, &j, &row, &row2](int v) {
        row2[j] = std::min(row2[k] + row[j], row2[j]);
        j++;
      });
    });
    k++;
  });
  std::vector<int> ms;
  std::for_each(graph.begin(), graph.end(), [&ms] (std::vector<int>& row){
    ms.push_back(*std::max_element(row.begin(), row.end()));
  });
  out << *std::max_element(ms.begin(), ms.end()) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}